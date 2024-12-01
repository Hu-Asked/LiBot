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
bool isStagingClimb = false;
bool isClimbing = false;

bool isRedAlliance = true;
bool isColorSort = true;
double winchOutTime = 500;
double maxClimbTime = 3500;

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
        pros::delay(30);
    }
}

void INTAKE(void* param) {
    int val = 0;
    bool isWrongColor = false;
    while(true) {
        val = colorSensor.get_hue();
        if(isIntaking) {  
            activateIntake(110);
            if(colorSensor.get_proximity() > 200) { 
                if ((isRedAlliance && (val > 100 && val < 300)) ||
                    (!isRedAlliance && (val < 30 || val > 300))) {
                    isWrongColor = true;
                } else {
                    isWrongColor = false;
                }
            } else {
                isWrongColor = false;
            }
        } else if (isReverseIntake) {
            activateIntake(-110);
        } else if(!isScoring) {
            activateIntake(0);
        }// when no longer ring detected and iswrong color stop intake
        if(isColorSort && isWrongColor) {
            pros::delay(30);
            activateIntake(0);
            pros::delay(100);
            isWrongColor = false;
        }
        GHUI::console_print(std::to_string(colorSensor.get_proximity()) + " " + std::to_string(colorSensor.get_hue()), 0);
        pros::delay(20);
    }
}

void CLIMB(void* param) {
    bool PTOEnabled = true;
    climbPTO.set_value(true);
    climbPiston.set_value(true);
    while(true) {
        if(isStagingClimb && !PTOEnabled) {
            climbPTO.set_value(true);
            // wingPiston.set_value(true);
        } else if(!isStagingClimb) {
            climbPTO.set_value(false);
            // windPiston.set_value(false);
        }
        if(isClimbing) break;
        pros::delay(40);
    }
    int currentStage = 0;
    int distance = 0;
    while(true) {
        if(isClimbing) {
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
                    /* if distancesensor >= distance or pros::millis - startOfClimb >= maxClimbTime:
                        currentStage++;
                        break;
                    */
                    if(!isClimbing) {
                        break;
                    }
                    pros::delay(30);
                }
                if(!isClimbing) {
                    break;
                }
                while(pros::millis() - startOfClimb < winchOutTime) { //Winch out
                    pros::delay(30);
                }
                climbPiston.set_value(false);
                pros::delay(500);
                
                while(pros::millis() - startOfClimb < winchOutTime) { //Continue winch out
                    pros::delay(30);
                }
                climbPiston.set_value(true);
                pros::delay(30);
            }
        }
        pros::delay(40);
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