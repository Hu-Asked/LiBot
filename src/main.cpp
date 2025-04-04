#include "main.h"

void initialize() {
    GHUI::initialize_auton_selector(
        {
            GHUI::Auton(RedRings, "6 ring + 1 (R)", GHUI::RED),
            GHUI::Auton(RedMOGO, "Red MOGO Rush", GHUI::RED),
            GHUI::Auton(RedSAWP, "Red SAWP", GHUI::RED),
            GHUI::Auton(BlueRings, "Ring Rush (B)", GHUI::BLUE),
            GHUI::Auton(BlueMOGO, "Blue MOGO Rush", GHUI::BLUE),
            GHUI::Auton(BlueSAWP, "Blue SAWP", GHUI::BLUE),
            GHUI::Auton(AutonomousSkills, "Skills", GHUI::OTHER),
            GHUI::Auton(drive_example, "Drive Test", GHUI::OTHER),
            GHUI::Auton(turn_example, "Turn Test", GHUI::OTHER),
            GHUI::Auton(driveOffLine, "Drive Off Line", GHUI::OTHER)
        }
    );
    chassis.calibrate();
    lb1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    lb2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
    // if (!pros::competition::is_connected()) 
        pros::Task update_info([&]() {  
            while (true) {
                GHUI::update_pos(chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta, 3);
                pros::delay(25);
            }
        });  
    
    colorSensor.set_integration_time(15);
    colorSensor.set_led_pwm(80);
    pros::Task lb_stage(STAGE_LADY_BROWN, nullptr);
    pros::Task intake(INTAKE, nullptr);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    master.rumble(".");
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
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
        // GHUI::console_print(std::to_string(-70 + calculate_reset_distance(3.3, leftResetSensor.get_distance(), 0, chassis.getPose().theta)), 0);
        GHUI::console_print(std::to_string(lb_pos) + " " + std::to_string(lb1.get_position()) + " " + std::to_string(lb2.get_position()), 5);
        if(!isClimbing) {
            if(master.get_digital_new_press(DIGITAL_LEFT)) {
                set_lb_pos(LB_STAGED_POSITION, 1200);
            } else if (master.get_digital_new_press(DIGITAL_UP)) {
                set_lb_pos(LB_DESCORE_POSITION, 1200);
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
        }
        if (master.get_digital_new_press(DIGITAL_A)) toggleMOGO();
        // if (master.get_digital_new_press(DIGITAL_B)) toggleIntakeCount();
        if (master.get_digital_new_press(DIGITAL_B)) toggleRightDoinker();
        if (master.get_digital_new_press(DIGITAL_DOWN)) toggleLeftDoinker();
        if (master.get_digital_new_press(DIGITAL_X)) toggleIntakeCount();
        if (master.get_digital(DIGITAL_RIGHT) && master.get_digital_new_press(DIGITAL_Y)) { isColorSort = !isColorSort; master.rumble(".");}
        // if (master.get_digital_new_press(DIGITAL_X)) {
        //     if(!isClimbingInitiated) {
        //         master.rumble("--");
        //         // set_lb_pos(150, 1200);
        //         isClimbingInitiated = true;
        //         pros::Task climb(CLIMB, nullptr);
        //     } else {
        //         master.rumble(".");
        //         isClimbing = !isClimbing;
        //     }
        // }
        // if(master.get_digital_new_press(DIGITAL_Y)) {
        //     climbPTO.set_value(!isPTOED);
        //     isPTOED = !isPTOED;
        // }
        // double avgIME = 0;
        // for(auto i : LeftDrive.get_position_all()) {
        //     avgIME += i;
        // }
        // for(auto i : RightDrive.get_position_all()) {
        //     avgIME += i;
        // }
        // GHUI::console_print(std::to_string(avgIME / 6), 0);
        if(!isNotified && pros::millis() - startTime >= 70000) {
            master.rumble("--------");
            isNotified = true;
        }
        lv_task_handler();
        pros::delay(10);
    }
}