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

bool isRedAlliance = true;


//          TASKS

void STAGE_LADY_BROWN(void* param) {
    double target = 2850; //centidegrees
    double limit = 16500; //prevent from going past;
    while(true) {
        if(isStaging) {
            limit = 16500;
            target = 2850;
            movelb(target, 100, limit);
            isStaging = false;
        } else if(isReturning) {
            limit = 50000;
            target = 2850;
            pros::delay(300);
            movelb(target, 100, limit);
            isReturning = false;
        } else if(isZeroing) {
            limit = 16500;
            target = 0;
            movelb(target, 100, limit);
            isZeroing = false;
        } else if(isScoring) {
            limit = 16500;
            target = 15200;
            movelb(target, 100, limit);
            isScoring = false;
        }
        pros::delay(30);
    }
}

void INTAKE(void* param) {
    int val = 0;
    int avg = 0;
    while(true) {
        val = colorSensor.get_hue();
        if(isIntaking) {  
            activateIntake(110);
            if(colorSensor.get_proximity() > 200) { 
                if (isRedAlliance && (val > avg && val < 300)) {
                    pros::delay(30);
                    activateIntake(0);
                    pros::delay(100);
                } else if (!isRedAlliance && (val < avg || val > 300)) {
                    pros::delay(30);
                    activateIntake(0);
                    pros::delay(100);
                }
            } else {
                avg = colorSensor.get_hue();
            }
        } else if (isReverseIntake) {
            activateIntake(-110);
        } else if(!isScoring) {
            activateIntake(0);
        }
        
        if(colorSensor.get_proximity() > 200) {    
            pros::lcd::set_text(7, (val > avg && val < 300) ? "Blue" : "Red"); 
        } else {
            pros::lcd::set_text(7, "None");
        }
        pros::lcd::set_text(6, to_string(val) + " " + to_string(colorSensor.get_proximity()));

        
        pros::delay(20);
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