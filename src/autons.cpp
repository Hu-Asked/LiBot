#include "main.h"
ASSET(redringrushcurve_txt);
void RedRings() {
    isRedAlliance = true;  
    chassis.setPose(0, 0, 0);
    toggleLeftDoinker();
    chassis.moveToPoint(0, 51, 1500, {.maxSpeed = 127});
    isIntaking = true;
    isSavingRing = true;
    chassis.swingToPoint(15.5, 29.16, lemlib::DriveSide::RIGHT, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 1.5});
    chassis.moveToPoint(15.5, 29.16, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 0.5});
    isIntaking = false;
    isSavingRing = false;
    chassis.waitUntil(17);
    toggleMOGO();
    chassis.waitUntilDone();
    toggleLeftDoinker();
    isIntaking = true;
    pros::delay(150);
    chassis.turnToPoint(-13, 40, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(-13, 40, 1500, {.maxSpeed = 70, .minSpeed = 20, .earlyExitRange = 0.5});
    chassis.turnToPoint(-28, 13.7, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(-28, 13.7, 1500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-38.9, 8.5, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(-38.9, 8.5, 1000, {.maxSpeed = 70});
    chassis.waitUntilDone();
    LeftDrive.move(70);
    RightDrive.move(70);
    pros::delay(500);
    LeftDrive.move(-20);
    RightDrive.move(-20);
    pros::delay(750);
    chassis.swingToPoint(-9, 2, lemlib::DriveSide::RIGHT, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 1.5});
    chassis.moveToPoint(-9, 2, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToPoint(18, 0, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});
    chassis.waitUntilDone();
    toggleIntakeCount();
    chassis.moveToPoint(18, 0, 1500, {.maxSpeed = DRIVESPEED});
    toggleMOGO();
    isSavingRing = true;
    chassis.waitUntilDone();
    toggleIntakeCount();
    pros::delay(50);
    LeftDrive.move(-45);
    RightDrive.move(-45);
    pros::delay(400);
    chassis.moveToPoint(calculate_relative_move_x(10), calculate_relative_move_y(10), 1500, {.maxSpeed = DRIVESPEED});
    toggleRightDoinker();
    chassis.turnToPoint(16.5, -18, 1200, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 0.5});
    chassis.waitUntilDone();
    toggleRightDoinker();
    chassis.moveToPoint(16.5, -18, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 20});
    chassis.waitUntilDone();
    isIntaking = true;
};


void RedMOGO() {
    isRedAlliance = true;
    chassis.setPose(0, 0, 0);
    chassis.turnToPoint(-34.5, -2.2, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-34.5, -2.2, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(24);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToPoint(-27.5, 19.4, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-27.5, 19.4, 1500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-28, -36, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-28, -36, 1500, {.maxSpeed = DRIVESPEED});
}

void RedSAWP() {
    isRedAlliance = true;
    chassis.setPose(0, 0, 0);
    chassis.turnToPoint(-34.5, -2.2, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-34.5, -2.2, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(24);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToPoint(-27.5, 19.4, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-27.5, 19.4, 1500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-28, -36, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-28, -36, 1500, {.maxSpeed = DRIVESPEED});
    // set_lb_pos(LB_ALLIANCESTAKE_POSITION, 1500);
    // double waitForLb = pros::millis();
    // while (pros::millis() - waitForLb < 1500) {
    //     if(exitLB) {
    //         break;
    //     }
    //     pros::delay(5);
    // }
    // chassis.moveToPoint(0, -15, 1500, {.maxSpeed = DRIVESPEED});
}

void BlueRings() {
    
    isRedAlliance = true;  
    chassis.setPose(0, 0, 0);
    toggleLeftDoinker();
    chassis.moveToPoint(0, 51, 1500, {.maxSpeed = 127});
    isIntaking = true;
    isSavingRing = true;
    chassis.swingToPoint(-15.5, 29.16, lemlib::DriveSide::RIGHT, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 1.5});
    chassis.moveToPoint(-15.5, 29.16, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 0.5});
    isIntaking = false;
    isSavingRing = false;
    chassis.waitUntil(17);
    toggleMOGO();
    chassis.waitUntilDone();
    toggleLeftDoinker();
    isIntaking = true;
    pros::delay(150);
    chassis.turnToPoint(13, 40, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(13, 40, 1500, {.maxSpeed = 70, .minSpeed = 20, .earlyExitRange = 0.5});
    chassis.turnToPoint(28, 13.7, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(28, 13.7, 1500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(38.9, 8.5, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(38.9, 8.5, 1000, {.maxSpeed = 70});
    chassis.waitUntilDone();
    LeftDrive.move(70);
    RightDrive.move(70);
    pros::delay(500);
    LeftDrive.move(-20);
    RightDrive.move(-20);
    pros::delay(750);
    chassis.swingToPoint(9, 2, lemlib::DriveSide::RIGHT, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 1.5});
    chassis.moveToPoint(9, 2, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToPoint(-18, 0, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});
    chassis.waitUntilDone();
    toggleIntakeCount();
    chassis.moveToPoint(-18, 0, 1500, {.maxSpeed = DRIVESPEED});
    toggleMOGO();
    isSavingRing = true;
    chassis.waitUntilDone();
    toggleIntakeCount();
    pros::delay(50);
    LeftDrive.move(-45);
    RightDrive.move(-45);
    pros::delay(400);
    chassis.moveToPoint(calculate_relative_move_x(10), calculate_relative_move_y(10), 1500, {.maxSpeed = DRIVESPEED});
    toggleRightDoinker();
    chassis.turnToPoint(-16.5, -18, 1200, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 0.5});
    chassis.waitUntilDone();
    toggleRightDoinker();
    chassis.moveToPoint(-16.5, -18, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 20});
    chassis.waitUntilDone();
    isIntaking = true;
}

void BlueMOGO() {
    isRedAlliance = false;    
    chassis.setPose(0, 0, 0);
    chassis.turnToHeading(44, 1500, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    set_lb_pos(LB_ALLIANCESTAKE_POSITION, 1500);
    double waitForLb = pros::millis();
    chassis.moveToPoint(0, 0, 800, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.turnToPoint(-35, -6, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-35, -6, 1500, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntil(26);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToPoint(-29, -27.3, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-29, -27.3, 1500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-30, 9.5, 1500, {.maxSpeed = TURNSPEED});
    set_lb_pos(LB_BACKPACK_POSITION, 1500);
    chassis.moveToPoint(-30, 9.5, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    LeftDrive.move(35);
    RightDrive.move(35);
}


void BlueSAWP() {
    isRedAlliance = false;
    chassis.setPose(0, 0, 0);
    chassis.turnToPoint(-34.5, -2.2, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-34.5, -2.2, 1500, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntil(24);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToPoint(-27.5, 19.4, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-27.5, 19.4, 1500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-28, -36, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-28, -36, 3000, {.maxSpeed = DRIVESPEED});
}

double LEFT_DISTANCE_SENSOR_OFFSET = 3.3;
ASSET(path2_txt);
void AutonomousSkills() {
    isRedAlliance = true;
    isColorSort = false;
    double waitForLb = 0;
    chassis.setPose(-61.675, 0, 90);
    isIntaking = true;
    pros::delay(500);
    isIntaking = false;
    chassis.moveToPoint(-47, 0, 1250, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToPoint(-46, 27.2, 800, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-46, 27.2, 1300, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntil(21.5);
    toggleMOGO();
    chassis.turnToPoint(-20.5, 25.4, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.moveToPoint(-20.5, 25.4, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    isIntaking = true;
    chassis.turnToPoint(0, 40, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.moveToPoint(0, 40, 2000, {.maxSpeed = DRIVESPEED, .minSpeed = 30, .earlyExitRange = 8});
    chassis.moveToPoint(30, 50, 1500, {.maxSpeed = DRIVESPEED});
    set_lb_pos(LB_STAGED_POSITION, 900);
    chassis.moveToPoint(2, 40, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(1.5, 65, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    isIntaking = false;
    chassis.moveToPoint(1.5, 65, 1200, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    set_lb_pos(LB_BACKPACK_POSITION, 500);
    pros::delay(350);
    isIntaking = true;
    chassis.waitUntilDone();
    set_lb_pos(LB_WALLSTAKE_POSITION, 800);
    waitForLb = pros::millis();
    while (pros::millis() - waitForLb < 800) {
        if(exitLB) {  
            break;
        }
        pros::delay(5);
    }
    chassis.moveToPoint(-4, 43, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-22, 47, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.moveToPoint(-22, 47, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 30, .earlyExitRange = 2});
    chassis.moveToPoint(-60, 48, 1500, {.maxSpeed = 70, .minSpeed = 20, .earlyExitRange = 1});
    chassis.swingToPoint(-48.5, 60.3, lemlib::DriveSide::LEFT, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.moveToPoint(-48.5, 60.3, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToHeading(110, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.waitUntilDone();
    pros::delay(500);
    toggleMOGO();
    isIntaking = false;
    LeftDrive.move(-60);
    RightDrive.move(-60);
    pros::delay(300);
    chassis.moveToPoint(7, 51, 2000, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.moveToPoint(50, 47.65, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 15});
    isColorSort = true;
    isIntaking = true;
    isSavingRing = true;
    chassis.swingToHeading(180, lemlib::DriveSide::LEFT, 1000, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.waitUntilDone();
    isIntaking = false;
    isColorSort = false;
    toggleMOGO();
    LeftDrive.move(-70);
    RightDrive.move(-70);
    pros::delay(600);
    LeftDrive.move(0);
    RightDrive.move(0);
    chassis.setPose(-70 + calculate_reset_distance(LEFT_DISTANCE_SENSOR_OFFSET, leftResetSensor.get_distance(), 180, 180), 68, 180);
}

double target = 0;
void drive_example() {
    chassis.setPose({0, 0, 0});
    pros::Task print_task([]() {
        double start = pros::millis();
        while(true) {
            std::cout << std::to_string(chassis.getPose().y) << " " << std::to_string(target) << " " << std::to_string(pros::millis() - start) << "\n";
            pros::delay(10);
        }
    });
    target = 36;
    chassis.moveToPoint(0, 36, 5000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    target = 0;
    chassis.moveToPoint(0, 0, 5000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    target = 24;
    pros::delay(400);
    chassis.setPose({0, 0, 0});
    chassis.moveToPoint(0, 24, 5000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    target = 0;
    chassis.moveToPoint(0, 0, 5000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
}
void turn_example() {
    chassis.setPose({0, 0, 0});
    pros::Task print_task([]() {
        double start = pros::millis();
        while(true) {
            std::cout << std::to_string(chassis.getPose().theta) << " " << std::to_string(target) << " " << std::to_string(pros::millis() - start) << "\n";
            pros::delay(10);
        }
    });
    target = 45;
    chassis.turnToHeading(45, 2000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    target = 135;
    chassis.turnToHeading(135, 2000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    target = 315;
    chassis.turnToHeading(315, 2000, {.maxSpeed = TURNSPEED});
}

void driveOffLine() {
    isRedAlliance = true;
    chassis.setPose({0, 0, 0});
    chassis.moveToPoint(0, 10, 1200, {.maxSpeed = 60});
}