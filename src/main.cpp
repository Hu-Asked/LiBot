#include "main.h"

void initialize() {
    GHUI::initialize_auton_selector(
        {
            GHUI::Auton(RedRings, "6 ring + 1", GHUI::RED),
            GHUI::Auton(RedMOGO, "Red MOGO Rush", GHUI::RED),
            GHUI::Auton(RedMOGO2, "Red MOGO Safe", GHUI::RED),
            GHUI::Auton(BlueRings, "6 ring + 1", GHUI::BLUE),
            GHUI::Auton(BlueMOGO, "Blue MOGO Rush", GHUI::BLUE),
            GHUI::Auton(BlueMOGO2, "Blue MOGO Safe", GHUI::BLUE),
            GHUI::Auton(AutonomousSkills, "Skills", GHUI::OTHER),
            GHUI::Auton(drive_example, "Drive Test", GHUI::OTHER),
            GHUI::Auton(turn_example, "Turn Test", GHUI::OTHER),
        }
    );
    chassis.calibrate();
    lb1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    lb2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
    // if (!pros::competition::is_connected()) 
        pros::Task update_info([&]() {  
            while (true) {
                GHUI::update_pos(chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
                pros::delay(25);
            }
        });  
    
    // colorSensor.set_integration_time(15);
    // colorSensor.set_led_pwm(80);
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
    isMovingLB = false;

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
        double lb_pos = (lb1.get_position() + lb2.get_position()) / 2;
        GHUI::console_print(std::to_string(lb_pos), 5);
        if(!isClimbingInitiated) {
            if(master.get_digital_new_press(DIGITAL_LEFT)) {
                if(lb_pos < 144 && lb_pos > 124) {
                    set_lb_pos(LB_ZEROED_POSITION, 1200);
                } else {
                    set_lb_pos(LB_STAGED_POSITION, 1200);
                }
            } 
            if(master.get_digital(DIGITAL_L2)) {
                exitLB = true;
                activatelb(-127);
            } else if(master.get_digital(DIGITAL_R2) && lb_pos < 1010) {
                exitLB = true;
                activatelb(127);
            } else if(exitLB){
                activatelb(0);
            }
            
        } else {
            if(master.get_digital_new_press(DIGITAL_UP)) {
                toggleClimb();
            }
        }
        if (master.get_digital_new_press(DIGITAL_A)) toggleMOGO();
        if (master.get_digital_new_press(DIGITAL_B)) toggleIntakeCount();
        if (master.get_digital_new_press(DIGITAL_Y)) toggleDoinker();
        if (master.get_digital_new_press(DIGITAL_X)) {
            if(!isClimbingInitiated) {
                master.rumble("--");
                set_lb_pos(150, 1200);
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