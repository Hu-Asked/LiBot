#include "main.h"

void initialize() {
    GHUI::initialize_auton_selector(
        {
            GHUI::Auton(RedRings, "Red Ringside", GHUI::RED),
            GHUI::Auton(RedMOGO, "Red MOGO Rush", GHUI::RED),
            GHUI::Auton(RedMOGO2, "Red Ringside Safe", GHUI::RED),
            GHUI::Auton(BlueRings, "Blue Ringside", GHUI::BLUE),
            GHUI::Auton(BlueMOGO, "Blue MOGO Rush", GHUI::BLUE),
            GHUI::Auton(BlueMOGO2, "Blue Ringside Safe", GHUI::BLUE),
            GHUI::Auton(AutonomousSkills, "Skills", GHUI::OTHER),
            GHUI::Auton(drive_example, "Drive Test", GHUI::OTHER),
            GHUI::Auton(turn_example, "Turn Test", GHUI::OTHER),
        }
    );
    chassis.calibrate();
    lb_encoder.reset_position();
    pidlb.setExitCondition(100, 100, 1400);
    lb1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    lb2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
    if (!pros::competition::is_connected()) {
        pros::Task screen_task([&]() {
            while (true) {
                GHUI::update_pos(chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
                std::string temperature = "Left";
                for(auto a : LeftDrive.get_temperature_all()) {
                    temperature += " " + std::to_string(a);
                }
                temperature += " Right";
                for(auto a : RightDrive.get_temperature_all()) {
                    temperature + " " + std::to_string(a);
                }
                temperature += " Intake " + std::to_string(intake1.get_temperature());
                GHUI::console_print(temperature, 1);
                pros::delay(25);
            }
        });  
    }
    colorSensor.set_integration_time(10);
    colorSensor.set_led_pwm(80);
    pros::Task lb_stage(STAGE_LADY_BROWN, nullptr);
    pros::Task intake(INTAKE, nullptr);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    master.rumble(".");
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
    isRedAlliance = true;
    GHUI::run_selected_auton();
}
void opcontrol() {  
    double startTime = pros::millis();
    bool isNotified = false;
    
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    isIntaking = false;
    isReverseIntake = false;
    isStaging = false;
    isScoring = false;
    isReturning = false;

    while (true) {
        if (!pros::competition::is_connected()) {
            if (master.get_digital_new_press(DIGITAL_RIGHT))
                autonomous();
        }

        int Y = master.get_analog(ANALOG_LEFT_Y);
        int X = master.get_analog(ANALOG_RIGHT_X);
        if(!isClimbing) {
            chassis.arcade(Y, X);
        }
        if(!isZeroing && !isStaging && !isReturning && master.get_digital(DIGITAL_L2)) {
            activatelb(-110);
        } else if (!isZeroing && !isStaging && !isReturning && master.get_digital(DIGITAL_R2)) {
            activatelb(110);
        } else if (!isZeroing && !isStaging && !isReturning && !isScoring) { 
            activatelb(0);
        }
        if(!isScoring) {
            if (master.get_digital(DIGITAL_R1)) {
                isIntaking = true;
                isReverseIntake = false;
            } else if(master.get_digital(DIGITAL_L1)) {
                isIntaking = false;
                isReverseIntake = true;
            } else {
                isIntaking = false;
                isReverseIntake = false;
            }
        }
        if(!isClimbingInitiated) {
            if(!isZeroing && !isStaging && !isReturning && lb_encoder.get_position() > 16000) {
                isScoring = false;
                lb1.move(0);
                lb2.move(0);
                isReturning = true;
            }
            if(!isStaging && !isReturning && !isScoring && !isZeroing) {
                if (master.get_digital(DIGITAL_UP)) {
                    intake1.move(0);
                    intake1.move_relative(-60, 127);
                    isIntaking = false;
                    isScoring = true;
                } else if (master.get_digital(DIGITAL_DOWN)) {
                    isZeroing = true;
                } else if (master.get_digital(DIGITAL_LEFT)) {
                    isStaging = true;
                }
            }
        } else {
            if(master.get_digital_new_press(DIGITAL_UP)) {
                toggleClimb();
            }
        }
        if (master.get_digital_new_press(DIGITAL_A)) toggleMOGO();
        if (master.get_digital_new_press(DIGITAL_B)) toggleIntakeCount();
        if (master.get_digital_new_press(DIGITAL_Y)) toggleDoinker();
        if (master.get_digital(DIGITAL_L1) && master.get_digital(DIGITAL_R1) && master.get_digital_new_press(DIGITAL_X)) {
            if(!isClimbingInitiated) {
                master.rumble("--");
                isClimbingInitiated = true;
                pros::Task climb(CLIMB, nullptr);
            } else {
                master.rumble(".");
                isClimbing = !isClimbing;
            }
        }
        
        if(!isNotified && pros::millis() - startTime >= 85000) {
            master.rumble("--------");
            isNotified = true;
        }
        lv_task_handler();
        pros::delay(10);
    }
}