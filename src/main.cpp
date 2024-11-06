#include "main.h"

void initialize() {
    ez::as::auton_selector.autons_add({
        Auton("Red Rings", RedRings),
        Auton("Red MOGO \nMOGO rush", RedMOGO),
        Auton("Red MOGO 2 \nTwo rings two stakes", RedMOGO2),
        Auton("Blue Rings", BlueRings),
        Auton("Blue MOGO \nMOGO rush", BlueMOGO),
        Auton("Blue MOGO 2 \nTwo rings two stakes", BlueMOGO2),
        Auton("Skills", AutonomousSkills),
        Auton("Drive Example\n\nRobot drives forward", drive_example),
        Auton("Turn Example\n\nRobot turns 90 degrees", turn_example),
        Auton("Curve Example\n\nRobot curves", curve_example)
    });
    pros::lcd::initialize();
    chassis.calibrate();
    ez::as::initialize();
    lb_encoder.reset_position();
    pidlb.setExitCondition(100, 100, 1400);
    lb1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    lb2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    if(!pros::competition::is_connected()) {    
        pros::Task screen_task([&]() {
            while (true) {
                // print robot location to the brain screen
                pros::lcd::print(2, "X: %f", chassis.getPose().x); // x
                pros::lcd::print(3, "Y: %f", chassis.getPose().y); // y
                master.print(2, 0 , "Theta: %f", chassis.getPose().theta); // heading
                // delay to save resources
                pros::delay(20);
            }
        });
    }
    colorSensor.set_led_pwm(100);
    pros::Task lb_stage(STAGE_LADY_BROWN, nullptr);
    pros::Task intake(INTAKE, nullptr);

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    master.rumble(".");
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
    chassis.setPose(0, 0, 0);
    isRedAlliance = true;
    ez::as::auton_selector.selected_auton_call();
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

        chassis.arcade(Y, X);
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
        if(!isZeroing && !isStaging && !isReturning && lb_encoder.get_position() > 16500) {
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
        if (master.get_digital_new_press(DIGITAL_A)) toggleMOGO();
        if (master.get_digital_new_press(DIGITAL_X)) toggleIntakeCount();
        if (master.get_digital_new_press(DIGITAL_Y)) toggleDoinker();
        pros::lcd::print(5, "Target: %ld", lb_encoder.get_position());
        pros::lcd::set_text(4, to_string(isStaging) + " " + to_string(isReturning) + " " + to_string(isScoring) + " " + to_string(isIntaking));
        if(!isNotified && pros::millis() - startTime >= 85000) {
            master.rumble("--------");
            isNotified = true;
        }
        pros::delay(ez::util::DELAY_TIME);
    }
}
