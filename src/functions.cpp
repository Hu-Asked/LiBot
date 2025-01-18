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

bool isWingOut = false;
bool isClimbOut = false;

bool isClimbingInitiated = false;
bool isClimbing = false;

bool isRedAlliance = true;

bool isColorSort = true;

double BLUE_MIN = 150;
double BLUE_MAX = 260;

double RED_MIN = 0;
double RED_MAX = 35;

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

bool exitLB = true;
void STAGE_LADY_BROWN(void* param) {
    while(true) {
        if (isMovingLB) {
            movelb(lbTarget, 120, lbLimit);
            isMovingLB = false;
        }
        pros::delay(20);
    }
}

bool isAntiJam = true;
void INTAKE(void* param) {
    int val = 0;
    double jamStart = -1;
    bool isWrongColor = false;
    double distBetweenRings = 700;  //Distance to timeout color detection for
    std::deque<std::pair<bool, double>> ringsInIntake;  // Eject if true, Position when wrong color detected;
    while(true) {
        val = colorSensor.get_hue();
        if(isIntaking) {  
            activateIntake(120);
            if(isColorSort && colorSensor.get_proximity() > 150) {
                if(ringsInIntake.empty() || fabs(intake1.get_position() - ringsInIntake.back().second) >= distBetweenRings) {
                    if ((isRedAlliance && (val > BLUE_MIN && val < BLUE_MAX)) ||
                        (!isRedAlliance && (val < RED_MAX || val > RED_MIN_ALT))) {
                        ringsInIntake.push_back({true, intake1.get_position()});
                    } else {
                        ringsInIntake.push_back({false, intake1.get_position()});
                    }
                } else if (!ringsInIntake.empty()) {
                    if ((isRedAlliance && (val > BLUE_MIN && val < BLUE_MAX)) ||
                        (!isRedAlliance && (val < RED_MAX || val > RED_MIN_ALT))) {
                        ringsInIntake.back().first = true;
                    }
                }
            }
            
            if (isAntiJam && intake1.get_power() == 0 && ((lb1.get_position() + lb2.get_position()) / 2 < LB_STAGED_POSITION - 15 || (lb1.get_position() + lb2.get_position()) / 2 > LB_STAGED_POSITION + 15) && !isIntakeIncreased) {
                if (jamStart == -1) {
                    jamStart = pros::millis();
                }
                if (pros::millis() - jamStart >= 250) {
                    activateIntake(-127);
                    double startRev = pros::millis();
                    while (pros::millis() - startRev < 170) {
                        pros::delay(10);
                    }
                    jamStart = -1;
                }
            } else {
                jamStart = -1;
            }
        } else if (isReverseIntake) {
            activateIntake(-120);
        } else if (!isScoring) {
            jamStart = -1;
            activateIntake(0);
        }
        if(isColorSort && !ringsInIntake.empty()) {
            if(distanceSensor.get_distance() < 100) {
                if(ringsInIntake.front().first) {
                    pros::delay(70);
                    intake1.move(-127);
                    pros::delay(100);
                    intake1.move(0);
                }
                ringsInIntake.pop_front();
            } else if(fabs(intake1.get_position()) < fabs(ringsInIntake.back().second) && colorSensor.get_proximity() < 70) { //ring no longer past colorsensor
                ringsInIntake.pop_back();
            } else if(fabs(intake1.get_position() - ringsInIntake.front().second >= 2000)) ringsInIntake.pop_front();
        }
        GHUI::console_print(std::to_string(colorSensor.get_proximity()) + " " + std::to_string(val) + " " + std::to_string(intake1.get_position()) + " " + std::to_string(ringsInIntake.size()), 0);
        pros::delay(10);
    }
}

void CLIMB(void* param) {
    climbPiston.set_value(true); //release hang
    int currentStage = 0;
    double pistonExtendTime = 1100; //900
    double winchOutTime = 2700;     //2000
    double maxClimbTime = 3700;
    bool endClimb = false;
    pros::delay(500);
    climbPiston.set_value(false);
    wingPiston.set_value(false);
    while(true) {
        if(endClimb) {
            break;
        }
        if(isClimbing) {
            climbPTO.set_value(true);
            wingPiston.set_value(false);
            while (currentStage < 3) {
                switch (currentStage) {//set distance to level the robot should be off the ground for the respective hang
                    case 0:
                        maxClimbTime = 3350;
                        break;
                    case 1:
                        maxClimbTime = 3800;
                        break;
                    case 2:
                        maxClimbTime = 3800;
                        break;
                }
                double startOfClimb = pros::millis();

                while(true) { //Winch in
                    if(!isClimbing) {
                        endClimb = true;
                        break;
                    }
                    LeftDrive.move(-127);
                    RightDrive.move(-127);
                    if (pros::millis() - startOfClimb >= maxClimbTime){                       
                        currentStage++;
                        break;
                    }
                    pros::delay(20);
                }
                if (currentStage == 3) {
                    isClimbing = false;
                    endClimb = true;
                    break;
                }
                if(!isClimbing) {
                    endClimb = true;
                    break;
                }
                climbPiston.set_value(false);
                double startOfWinchOut = pros::millis();
                bool isEvaded = false;
                bool isPassived = false;
                pros::delay(150);
                double speed = 60;
                while(pros::millis() - startOfWinchOut < winchOutTime) { //Winch out
                    if(!isClimbing) {
                        endClimb = true;
                        break;
                    }
                    LeftDrive.move(speed);
                    RightDrive.move(speed);
                    if(!isPassived && pros::millis() - startOfWinchOut >= 600) {
                        climbPiston.set_value(true);
                        isPassived = true;
                        speed = 127;
                    }
                    if(!isEvaded && pros::millis() - startOfWinchOut >= pistonExtendTime) {
                        climbPiston.set_value(false);
                        isEvaded = true;
                    }
                    pros::delay(20);
                }
                if(!isClimbing) {
                    endClimb = true;
                    break;
                }
                LeftDrive.move(0);
                RightDrive.move(0);
                climbPiston.set_value(true);
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

void toggleDoinker() {
    doinkerPiston.set_value(!isLifted);
    isLifted = !isLifted;
}

void toggleIntakeCount() {
    intakeSizePiston.set_value(!isIntakeIncreased);
    isIntakeIncreased = !isIntakeIncreased;
}


void toggleClimb() {
    climbPiston.set_value(!isClimbOut);
    isClimbOut = !isClimbOut;
}

void activatelb(int speed) {
    lb1.move(speed);
    lb2.move(speed);
}

void movelb(double target, double power, double limit) {
    // pidlb.stop = false;
    // pidlb.timer = 0;
    // pidlb.maxTimeTimer = 0;
    double temp = power;
    double max = power;
    double pos = lb1.get_position() + lb2.get_position();
    pos /= 2;
    bool isReversing = (target - pos) < 0;
    double startOfMove = pros::millis();
    while (true) {
        pos = (lb1.get_position() + lb2.get_position()) / 2;
        double LPower = power;
        double RPower = power;
        double error = pidlb.update(target - pos);
        LPower = LPower * error;
        RPower = RPower * error;
        lb1.move(std::clamp(LPower, -max, max));
        lb2.move(std::clamp(RPower, -max, max));
        if (exitLB || pros::millis() - startOfMove >= limit) {
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