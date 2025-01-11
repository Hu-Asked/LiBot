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

bool isColorSort = false;

double BLUE_MIN = 170;
double BLUE_MAX = 260;

double RED_MIN = 0;
double RED_MAX = 35;

double RED_MIN_ALT = 330;
double RED_MAX_ALT = 360;

//          TASKS
double lbTarget = 0;
double lbLimit = 0;

void set_lb_pos(double target, double limit) {
    if(target == LB_STAGED_POSITION) {
        double lb_pos = (lb1.get_position() + lb2.get_position()) / 2;
        if(lb_pos < 0) {
            lb1.tare_position();
            lb2.tare_position();
        }
    }
    exitLB = false;
    lbTarget = target;
    lbLimit = limit;
    isMovingLB = true;
}

bool exitLB = true;
void STAGE_LADY_BROWN(void* param) {
    // pros::Task track_lb_pos([&]() {
    //         double start = pros::millis();
    //         while (true) {
    //             std::cout << lb_encoder.get_position() << " " << lbTarget << " " << pros::millis() - start << "\n";
    //         }
    //     });  

    while(true) {
        if (isMovingLB) {
            movelb(lbTarget, 120, lbLimit);
            isMovingLB = false;
        }
        // if(isStaging) {
        //     limit = 16000;
        //     target = 3000;
        //     movelb(target, 100, limit);
        //     isStaging = false;
        // } else if(isReturning) {
        //     limit = 50000;
        //     target = 3000;
        //     pros::delay(300);
        //     movelb(target, 100, limit);
        //     isReturning = false;
        // } else if(isZeroing) {
        //     limit = 16000;
        //     target = 700;
        //     movelb(target, 100, limit);
        //     isZeroing = false;
        // } else if(isScoring) {
        //     limit = 16000;
        //     target = 14000;
        //     movelb(target, 120, limit);
        //     isScoring = false;
        // }
        pros::delay(20);
    }
}

void INTAKE(void* param) {
    int val = 0;
    double jamStart = -1;
    bool isWrongColor = false;
    double colorSortDistance = 230; //Degrees after detecting ring to eject
    double distBetweenRings = 400;  //Distance to timeout color detection for
    std::deque<std::pair<bool, double>> ringsInIntake;  // Eject if true, Position when wrong color detected;
    while(true) {
        // val = colorSensor.get_hue();
        if(isIntaking) {  
            activateIntake(120);
            // if(isColorSort && colorSensor.get_proximity() > 200) {
            //     if(ringsInIntake.empty() || fabs(intake1.get_position() - ringsInIntake.front().second) >= distBetweenRings) {
            //         if ((isRedAlliance && (val > BLUE_MIN && val < BLUE_MAX)) ||
            //             (!isRedAlliance && (val < RED_MAX || val > RED_MIN_ALT))) {
            //             ringsInIntake.push_back({true, intake1.get_position()});
            //         } else {
            //             ringsInIntake.push_back({false, intake1.get_position()});
            //         }
            //     } else if (!ringsInIntake.empty()) {
            //         if ((isRedAlliance && (val > BLUE_MIN && val < BLUE_MAX)) ||
            //             (!isRedAlliance && (val < RED_MAX || val > RED_MIN_ALT))) {
            //             ringsInIntake.back().first = true;
            //         }
            //     }
            // }
            
            if (intake1.get_power() == 0 && ((lb1.get_position() + lb2.get_position()) / 2 < 120 || (lb1.get_position() + lb2.get_position()) / 2 > 200) && !isIntakeIncreased) {
                if (jamStart == -1) {
                    jamStart = pros::millis();
                }
                if (pros::millis() - jamStart >= 100) {
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
        } // when no longer ring detected and is wrong color stop intake
        // if(isColorSort && !ringsInIntake.empty()) {
        //     if(fabs(intake1.get_position() - ringsInIntake.front().second) >= colorSortDistance) {
        //         if(ringsInIntake.front().first) {
        //             // std::cout << ringsInIntake.front().second << " " << intake1.get_position() << " " << ringsInIntake.size() << "\n";
        //             activateIntake(-127);
        //             pros::delay(25);
        //             activateIntake(0);
        //         }
        //         ringsInIntake.pop_front();
        //     }
        //     if(fabs(intake1.get_position()) < fabs(ringsInIntake.back().second) && colorSensor.get_proximity() < 70) { //ring no longer past colorsensor
        //         ringsInIntake.pop_back();
        //     }
        // }
        // GHUI::console_print(std::to_string(colorSensor.get_proximity()) + " " + std::to_string(colorSensor.get_hue()) + " " + std::to_string(intake1.get_position()), 0);
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
    double reset_dist = true_dist * cos(angle);
    reset_dist /= 25.4;
    return reset_dist;
}