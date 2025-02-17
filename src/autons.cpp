#include "main.h"
ASSET(redringrushcurve_txt);
void RedRings() {
    isRedAlliance = true;  
    chassis.setPose(-52, 46.3, 90);
    chassis.moveToPoint(-5, 42.2, 1500, {.maxSpeed = 127, .minSpeed = 100, .earlyExitRange = 7});
    isIntaking = true;
    toggleLeftDoinker();
    chassis.waitUntil(18);
    isIntaking = false;
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.swingToPoint(-22.15, 19.75, lemlib::DriveSide::RIGHT, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 3});
    chassis.moveToPoint(-22.15, 19.75, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1});
    chassis.waitUntil(18);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToHeading(0, 1000, {.maxSpeed = 80, .minSpeed = 40, .earlyExitRange = 1});
    chassis.waitUntilDone();
    toggleLeftDoinker();
    pros::delay(200);
    chassis.moveToPoint(-26.3, 36, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 15, .earlyExitRange = 1.5});
    chassis.turnToPoint(-53.875, 32.6, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1.5});
    chassis.moveToPoint(-53.875, 32.6, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.waitUntilDone();
    pros::delay(2000);
    chassis.turnToPoint(-45.4, 12.85, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1.5});
    chassis.moveToPoint(-45.4, 12.85, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
}

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
    isRedAlliance = false;  
    chassis.setPose(52, 46.3, 270);
    chassis.moveToPoint(5, 43, 1500, {.maxSpeed = 127, .minSpeed = 100, .earlyExitRange = 7});
    isIntaking = true;
    toggleRightDoinker();
    chassis.waitUntil(18);
    isIntaking = false;
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.swingToPoint(16.1, 19.3, lemlib::DriveSide::LEFT, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 30, .earlyExitRange = 2});
    chassis.moveToPoint(16.1, 19.3, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntil(22);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToHeading(0, 1000, {.maxSpeed = 80, .minSpeed = 40, .earlyExitRange = 1});
    chassis.waitUntilDone();
    toggleRightDoinker();
    pros::delay(200);
    chassis.moveToPoint(24.5, 40, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 15, .earlyExitRange = 1.5});
    chassis.turnToPoint(53.875, 42.5, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1.5});
    chassis.moveToPoint(53.875, 42.5, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.waitUntilDone();
    pros::delay(2000);
    chassis.turnToPoint(45.4, 12.85, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1.5});
    chassis.moveToPoint(45.4, 12.85, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
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
    chassis.turnToPoint(0, 43, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.moveToPoint(0, 43, 2000, {.maxSpeed = DRIVESPEED, .minSpeed = 30, .earlyExitRange = 3});
    chassis.moveToPoint(30, 50, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    set_lb_pos(LB_STAGED_POSITION, 900);
    chassis.moveToPoint(2, 44, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(1, 65, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    isIntaking = false;
    chassis.moveToPoint(1, 65, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    set_lb_pos(LB_BACKPACK_POSITION, 500);
    chassis.waitUntilDone();
    set_lb_pos(LB_WALLSTAKE_POSITION, 800);
    isIntaking = true;
    waitForLb = pros::millis();
    while (pros::millis() - waitForLb < 800) {
        if(exitLB) {
            break;
        }
        pros::delay(5);
    }
    chassis.moveToPoint(1, 40, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    // chassis.turnToPoint(-26, 47, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    // chassis.moveToPoint(-26, 47, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 60, .earlyExitRange = 1.5});
    // chassis.moveToPoint(-64, 47, 1500, {.maxSpeed = 70, .minSpeed = 20, .earlyExitRange = 1});
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