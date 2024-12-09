#include "functions.hpp"

bool isClamped = false;
bool isLifted = false;
bool isIntakeIncreased = false;
bool isStaging = false;
bool isReturning = false;
bool isZeroing = false;
bool isScoring = false;
bool isIntaking = false;
bool isReverseIntake = false;

bool isClimbingInitiated = false;
bool isClimbing = false;

bool isRedAlliance = true;

bool isColorSort = true;

double BLUE_MIN = 200;
double BLUE_MAX = 260;

double RED_MIN = 0;
double RED_MAX = 35;

double RED_MIN_ALT = 330;
double RED_MAX_ALT = 360;

//          TASKS

void STAGE_LADY_BROWN(void* param) {
    double target = 2850; //centidegrees
    double limit = 16000; //prevent from going past;
    while(true) {
        if(isStaging) {
            limit = 16000;
            target = 3000;
            movelb(target, 100, limit);
            isStaging = false;
        } else if(isReturning) {
            limit = 50000;
            target = 3000;
            pros::delay(300);
            movelb(target, 100, limit);
            isReturning = false;
        } else if(isZeroing) {
            limit = 16000;
            target = 700;
            movelb(target, 100, limit);
            isZeroing = false;
        } else if(isScoring) {
            limit = 16000;
            target = 14000;
            movelb(target, 120, limit);
            isScoring = false;
        }
        pros::delay(20);
    }
}

void INTAKE(void* param) {
    int val = 0;
    bool isWrongColor = false;
    double colorSortDistance = 230; //Degrees after detecting ring to eject
    double distBetweenRings = 400;  //Distance to timeout color detection for
    std::deque<std::pair<bool, double>> ringsInIntake;  // Eject if true, Position when wrong color detected;
    while(true) {
        val = colorSensor.get_hue();
        if(isIntaking) {  
            activateIntake(110);
            if(isColorSort && colorSensor.get_proximity() > 200) {
                if(ringsInIntake.empty() || fabs(intake1.get_position() - ringsInIntake.front().second) >= distBetweenRings) {
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
        } else if (isReverseIntake) {
            activateIntake(-110);
        } else if(!isScoring) {
            activateIntake(0);
        } // when no longer ring detected and is wrong color stop intake
        if(isColorSort && !ringsInIntake.empty()) {
            if(fabs(intake1.get_position() - ringsInIntake.front().second) >= colorSortDistance) {
                if(ringsInIntake.front().first) {
                    std::cout << ringsInIntake.front().second << " " << intake1.get_position() << " " << ringsInIntake.size() << "\n";
                    activateIntake(-127);
                    pros::delay(25);
                    activateIntake(0);
                }
                ringsInIntake.pop_front();
            }
            if(fabs(intake1.get_position()) < fabs(ringsInIntake.back().second) && colorSensor.get_proximity() < 70) { //ring no longer past colorsensor
                ringsInIntake.pop_back();
            }
        }
        GHUI::console_print(std::to_string(colorSensor.get_proximity()) + " " + std::to_string(colorSensor.get_hue()) + " " + std::to_string(intake1.get_position()), 0);
        pros::delay(5);
    }
}

void CLIMB(void* param) {
    climbPiston.set_value(true); //release hang
    int currentStage = 0;
    int distance = 0;
    double FirstWinchOutTime = 2000;
    double SecondWinchOutTime = 2300;
    double maxClimbTime = 5000;
    while(true) {
        GHUI::console_print(std::to_string(distanceSensor.get_distance()), 3);
        if(isClimbing) {
            climbPTO.set_value(true);
            wingPiston.set_value(true);
            while (currentStage < 3) {
                switch (currentStage) { // set distance to level the robot should be off the ground for the respective hang
                    case 0:
                        distance = 0;
                        break;
                    case 1:
                        distance = 1;
                        break;
                    case 2:
                        distance = 2;
                        break;
                }
                double startOfClimb = pros::millis();
                while(true) { //Winch in
                    LeftDrive.move(127);
                    RightDrive.move(127);
                    if (distanceSensor.get_distance() >= distance || pros::millis() - startOfClimb >= maxClimbTime){                       currentStage++;
                        break;
                    }
                    if(!isClimbing) break;
                    pros::delay(30);
                }
                if (currentStage == 3) {
                    isClimbing = false;
                    break;
                }
                double startOfWinchOut = pros::millis();
                while(pros::millis() - startOfWinchOut < FirstWinchOutTime) { //Winch out
                    LeftDrive.move(-127);
                    RightDrive.move(-127);
                    if(!isClimbing) break;
                    pros::delay(30);
                }
                LeftDrive.move(0);
                RightDrive.move(0);
                climbPiston.set_value(false);
                pros::delay(100);
                startOfWinchOut = pros::millis();
                while(pros::millis() - startOfWinchOut < SecondWinchOutTime) {
                    LeftDrive.move(-127);
                    RightDrive.move(-127);
                    if(!isClimbing) break;
                    pros::delay(30);
                }
                LeftDrive.move(0);
                RightDrive.move(0);
                climbPiston.set_value(true);
                pros::delay(30);
            }
        }
        pros::delay(50);
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

void activatelb(int speed) {
    lb1.move(speed);
    lb2.move(speed);
}

void movelb(double target, double power, double limit) {
    pidlb.stop = false;
    pidlb.timer = 0;
    pidlb.maxTimeTimer = 0;
    double temp = power;
    double max = power + 27.0;
    bool isReversing = (target - lb_encoder.get_position()) < 0;
    while (true) {
        double LPower = power;
        double RPower = power;
        double error = pidlb.calculateError(lb_encoder.get_position(), target, isReversing);
        if (pidlb.stop || lb_encoder.get_position() > limit - 500) {
            break;
        }
        LPower = LPower * error;
        RPower = RPower * error;
        lb1.move(std::clamp(LPower, -max, max));
        lb2.move(std::clamp(RPower, -max, max));
        pros::delay(20);
    }
    lb1.move(0);
    lb2.move(0);
}