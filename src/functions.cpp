#include "functions.hpp"

bool isClamped = false;
bool isLifted = false;
bool isIntakeIncreased = false;
// bool isStaging = false;
// bool isReturning = false;
// bool isZeroing = false;
bool isScoring = false;
bool isMovingLB = false;
bool isIntaking = false;
bool isReverseIntake = false;
bool isPTOED = false;

bool isWingOut = false;
bool isClimbOut = false;

bool isClimbingInitiated = false;
bool isClimbing = false;

bool isRedAlliance = true;

bool isColorSort = true;

double BLUE_MIN = 80;
double BLUE_MAX = 290;

double RED_MIN = 0;
double RED_MAX = 45;

double RED_MIN_ALT = 330;
double RED_MAX_ALT = 360;

//          TASKS
double lbTarget = 0;
double lbLimit = 0;

void set_lb_pos(double target, double limit) {
    exitLB = false;
    lbTarget = target;
    lbLimit = limit;
    isMovingLB = true;
}

bool isMovingLbNoTimeout = false;

// void set_lb_pos_climb(double target, double limit) {
//     exitLB = false;
//     lbTarget = target;
//     lbLimit = limit;
//     isMovingLbNoTimeout = true;
// }

bool exitLB = true;
void STAGE_LADY_BROWN(void* param) {
    while(true) {
        if (isMovingLB) {
            movelb(lbTarget, 120, lbLimit, true);
            isMovingLB = false;
        }
        // if(isMovingLbNoTimeout) {
        //     movelb(lbTarget, 120, lbLimit, false);
        //     isMovingLbNoTimeout = false;
        // }
        pros::delay(20);
    }
}
bool isSavingRing = false;
bool isAntiJam = true;
void INTAKE(void* param) {
    int val = 0;
    double jamStart = -1;
    bool isWrongColor = false;
    double distBetweenRings = 700;  //Distance to timeout color detection for
    std::deque<std::pair<bool, double>> ringsInIntake;  // Eject if true, Position when wrong color detected;
    int wrongColor = 0;
    int correctColor = 0;
    while(true) {
        val = colorSensor.get_hue();
        if(isIntaking) { 
            activateIntake(127);
            if(isColorSort && colorSensor.get_proximity() > 200) {
                if(ringsInIntake.empty() || fabs(intake1.get_position() - ringsInIntake.back().second) >= distBetweenRings) {
                    if ((isRedAlliance && (val > BLUE_MIN && val < BLUE_MAX)) ||
                        (!isRedAlliance && (val < RED_MAX || val > RED_MIN_ALT))) {
                        ringsInIntake.push_back({true, intake1.get_position()});
                    } else {
                        if(isSavingRing) {
                            isIntaking = false;
                            isSavingRing = false;
                            activateIntake(0);
                        }
                        ringsInIntake.push_back({false, intake1.get_position()});
                    }
                } else if (!ringsInIntake.empty()) {
                    if ((isRedAlliance && (val > BLUE_MIN && val < BLUE_MAX)) ||
                        (!isRedAlliance && (val < RED_MAX || val > RED_MIN_ALT))) {
                        wrongColor++;
                    } else {
                        correctColor++;
                    }
                    if(wrongColor > correctColor) {
                        ringsInIntake.back().first = true;
                    } else{
                        ringsInIntake.back().first = false;
                    }
                }
            } else {
                wrongColor = 0;
                correctColor = 0;
            }
            if (isAntiJam && intake1.get_power() == 0 && (((lb1.get_position() + lb2.get_position()) / 2 < LB_STAGED_POSITION - 15 || (lb1.get_position() + lb2.get_position()) / 2 > LB_STAGED_POSITION + 15) || (colorSensor.get_proximity() >= 210 && ringsInIntake.size() < 2))) {
                if (jamStart == -1) {
                    jamStart = pros::millis();
                }
                if (pros::millis() - jamStart >= 150) {
                    activateIntake(-127);
                    double startRev = pros::millis();
                    while (pros::millis() - startRev < 100) {
                        pros::delay(10);
                    }
                    jamStart = -1;
                }
            } else {
                jamStart = -1;
            }
        } else if (isReverseIntake) {
            activateIntake(-127);
        } else if (!isScoring) {
            jamStart = -1;
            activateIntake(0);
        }
        if(isColorSort && !ringsInIntake.empty()) {
            if(distanceSensor.get_distance() < 100) {
                if(ringsInIntake.front().first) {
                    pros::delay(60);
                    intake1.move(-127);
                    pros::delay(100);
                    intake1.move(0);
                }
                ringsInIntake.pop_front();
            } else if(fabs(intake1.get_position()) < fabs(ringsInIntake.back().second) && colorSensor.get_proximity() < 70) { //ring no longer past colorsensor
                ringsInIntake.pop_back();
            } else if(fabs(intake1.get_position() - ringsInIntake.front().second >= 2000)) ringsInIntake.pop_front();
        }
        // GHUI::console_print(std::to_string(colorSensor.get_proximity()) + " " + std::to_string(val) + " " + std::to_string(intake1.get_position()) + " " + std::to_string(ringsInIntake.size()), 0);
        pros::delay(10);
    }
}

void CLIMB(void* param) {
    int currentStage = 0;
    double pistonExtendTime = 1100; //900
    double winchOutTime = 2500;     //2000
    double maxClimbTime = 5000;
    double LBUpPosition = 480; //480 / 330
    bool endClimb = false; 
    double WinchInPosition = -1600;
    double WinchOutPosition = 3300;
    set_lb_pos(LBUpPosition, 1500);
    climbReleasePiston.set_value(true);
    while(true) {
        if(endClimb) {
            break;
        }
        if(isClimbing) {
            LeftDrive.tare_position_all();
            RightDrive.tare_position_all();
            climbPTO.set_value(true);
            isPTOED = true;
            LeftDrive.set_brake_mode(MOTOR_BRAKE_HOLD);
            RightDrive.set_brake_mode(MOTOR_BRAKE_HOLD);
            while (currentStage < 3) {
                switch (currentStage) {//set distance to level the robot should be off the ground for the respective hang
                    // case 0:
                    //     set_lb_pos(LBUpPosition, 1500);
                    //     break;
                    case 1:
                        activatelb(127);
                        pros::delay(600);
                        break;
                    case 2:
                        WinchInPosition = -2000;
                        activatelb(127);
                        pros::delay(600);
                        break;
                }
                double startOfClimb = pros::millis();
                
                while(currentStage > 0 && pros::millis() - startOfClimb <= maxClimbTime) { //Winch in
                    if(!isClimbing) {
                        endClimb = true;
                        break;
                    }
                    if(currentStage >= 1 && pros::millis() - startOfClimb <= 100) {
                        activatelb(127);
                    } else {
                        activatelb(10);
                    }
                    LeftDrive.move(-127);
                    RightDrive.move(-127);
                    // if (pros::millis() - startOfClimb >= maxClimbTime){                       
                    //     currentStage++;
                    //     break;
                    // }
                    double avgIME = 0;
                    for(auto i : LeftDrive.get_position_all()) {
                        avgIME += i;
                    }
                    for(auto i : RightDrive.get_position_all()) {
                        avgIME += i;
                    }
                    if(avgIME / 6 <= WinchInPosition) {
                        break;
                    }
                    pros::delay(20);
                }
                if(currentStage == 0) {
                    LeftDrive.tare_position_all();
                    RightDrive.tare_position_all();
                    WinchInPosition = 50;
                }
                currentStage++;
                if (currentStage == 3) {
                    isClimbing = false;
                    endClimb = true;
                    break;
                }
                if(!isClimbing) {
                    endClimb = true;
                    break;
                }
                activatelb(0);
                // climbPiston.set_value(false);
                double startOfWinchOut = pros::millis();
                bool isEvaded = false;
                bool isPassived = false;
                // pros::delay(150);
                double speed = 60;
                while(pros::millis() - startOfWinchOut <= winchOutTime) { //Winch out
                    if(!isClimbing) {
                        endClimb = true;
                        break;
                    }
                    LeftDrive.move(speed);
                    RightDrive.move(speed);
                    if(!isPassived) activatelb(-110);
                    if(!isPassived && pros::millis() - startOfWinchOut >= 400) {
                        // climbPiston.set_value(true);
                        master.rumble("--");
                        isPassived = true;
                        activatelb(110);
                        speed = 127;
                    }
                    if(pros::millis() - startOfWinchOut >= 650) activatelb(-110);
                    double avgIME = 0;
                    for(auto i : LeftDrive.get_position_all()) {
                        avgIME += i;
                    }
                    for(auto i : RightDrive.get_position_all()) {
                        avgIME += i;
                    }
                    if(avgIME / 6 >= WinchOutPosition) {
                        break;
                    }
                    pros::delay(20);
                }
                activatelb(0);
                if(!isClimbing) {
                    endClimb = true;
                    break;
                }
                LeftDrive.move(0);
                RightDrive.move(0);
                // climbPiston.set_value(true);
                pros::delay(100);
            }
        }
        pros::delay(30);
    }
}

//          FUNCTIONS

void activateIntake(int speed) {
    intake1.move(speed);
}

void toggleMOGO() {
    clampPiston.set_value(!isClamped);
    isClamped = !isClamped;
}

void toggleLeftDoinker() {
    leftDoinkerPiston.set_value(!isLifted);
    isLifted = !isLifted;
}

void toggleRightDoinker() {
    rightDoinkerPiston.set_value(!isLifted);
    isLifted = !isLifted;
}

// void toggleIntakeCount() {
//     intakeSizePiston.set_value(!isIntakeIncreased);
//     isIntakeIncreased = !isIntakeIncreased;
// }


// void toggleClimb() {
//     climbPiston.set_value(!isClimbOut);
//     isClimbOut = !isClimbOut;
// }

void activatelb(int speed) {
    lb1.move(speed);
    lb2.move(speed);
}

void movelb(double target, double power, double limit, bool timeOut) {
    // pidlb.stop = false;
    // pidlb.timer = 0;
    // pidlb.maxTimeTimer = 0;
    double temp = power;
    double max = power;
    double pos = lb1.get_position() + lb2.get_position();
    pos /= 2;
    bool isReversing = (target - pos) < 0;
    double startOfMove = pros::millis();
    double exitTime = 0;
    while (true) {
        pos = (lb1.get_position() + lb2.get_position()) / 2;
        double LPower = power;
        double RPower = power;
        double error = pidlb.update(target - pos);
        LPower = LPower * error;
        RPower = RPower * error;
        lb1.move(std::clamp(LPower, -max, max));
        lb2.move(std::clamp(RPower, -max, max));
        if(timeOut && pos < target + 2 && pos > target - 2) {
            exitTime++;
        } else {
            exitTime = 0;
        }
        if(exitTime >= 3 || pros::millis() - startOfMove >= limit) {
            exitLB = true;
        }
        if (exitLB) {
            break;
        }
        pros::delay(20);
    }
    lb1.move(0);
    lb2.move(0);
}

double calculate_reset_distance(double offset_in, double distance_mm, double intended_heading, double true_heading) {
    double true_dist = distance_mm + (offset_in * 25.4);
    double angle = intended_heading - true_heading;
    double angle_rad = angle * M_PI / 180;
    double reset_dist = true_dist * cos(angle_rad);
    reset_dist /= 25.4;
    return reset_dist;
}

double calculate_relative_move_x(double dist_in) {
    double heading = fmod(chassis.getPose().theta, 360);
    double heading_rad = heading * M_PI / 180;
    double x = chassis.getPose().x;
    double y = chassis.getPose().y;
    
    double targetx = x + dist_in * sin(heading_rad);
    double targety = y + dist_in * cos(heading_rad);
    return targetx;
}

double calculate_relative_move_y(double dist_in) {
    double heading = fmod(chassis.getPose().theta, 360);
    double heading_rad = heading * M_PI / 180;
    double x = chassis.getPose().x;
    double y = chassis.getPose().y;
    
    double targetx = x + dist_in * sin(heading_rad);
    double targety = y + dist_in * cos(heading_rad);
    return targety;
}