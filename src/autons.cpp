#include "main.h"

void RedRings() {
    isRedAlliance = true;
    chassis.setPose({-54, 18.5, 180});
    pros::delay(1800);
    chassis.turnToPoint(-50, 10, 500, {.maxSpeed = TURNSPEED});
    toggleIntakeCount();
    // isIntaking = true;
    chassis.moveToPoint(-50, 10, 800, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleIntakeCount();
    // pros::delay(840);
    // isIntaking = false;
    chassis.moveToPoint(-44, -3, 600, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleDoinker();
    chassis.turnToHeading(230, 800, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed = TURNSPEED});
    chassis.turnToPoint(-70, 0, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    pros::delay(500);
    toggleDoinker();
    chassis.moveToPoint(-70, 0, 1250, {.forwards = false, .maxSpeed = 80, .minSpeed = 60, .earlyExitRange = 15});
    chassis.turnToHeading(-249, 600, {.maxSpeed = TURNSPEED});
    isIntaking = true;
    pros::delay(700);
    isIntaking = false;
    chassis.turnToPoint(-37, 37, 1000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    isIntaking = true;
    chassis.moveToPoint(-37, 37, 1500, {.maxSpeed = DRIVESPEED});
    // pros::delay(900);
    // isIntaking = false;
    chassis.turnToPoint(-15.8, 18.3, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-15.8, 18.3, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(23);
    toggleMOGO();
    chassis.turnToPoint(-18, 46, 800, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-18, 46, 1000, {.maxSpeed = DRIVESPEED});
    // isIntaking = true;
    chassis.waitUntilDone();
    isIntaking = false;
    chassis.turnToPoint(-3, 46.44, 700, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    isIntaking = true;
    chassis.moveToPoint(-3, 46.44, 850, {.maxSpeed = DRIVESPEED});
    pros::delay(500);
    chassis.moveToPoint(-16, 42, 700, {.forwards = false, .maxSpeed = DRIVESPEED});
}

void RedMOGO() {
    isRedAlliance = true;
    chassis.setPose(-52, -60, 90);
    chassis.moveToPoint(-14, -45, 1500, {.minSpeed = 127, .earlyExitRange = 6});
    isIntaking = true;
    chassis.turnToHeading(73, 350);
    toggleDoinker();
    pros::delay(100);
    isIntaking = false;
    chassis.moveToPoint(-31.5, -51, 1000, {.forwards = false, .maxSpeed = 127});
    chassis.waitUntilDone();
    toggleDoinker();
    pros::delay(150);
    chassis.turnToPoint(-5, -47, 1000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-5, -47, 1250, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(22.5);
    toggleMOGO();
    chassis.moveToPoint(-40.5, -58.25, 1000, {.maxSpeed = DRIVESPEED});
    isIntaking = true;
    chassis.turnToPoint(-55, -47.5, 800, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.moveToPoint(-55, -47.5, 1000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    isIntaking = false;
    chassis.turnToHeading(200, 800);
    chassis.waitUntilDone();
    toggleDoinker();
    chassis.moveToPoint(-56.5, -54, 1200);
    chassis.turnToHeading(140, 1000);
    chassis.waitUntilDone();
    toggleDoinker();
    chassis.moveToPoint(-57.5, -17, 900, {.forwards = false,.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    pros::delay(150);
    chassis.turnToPoint(-14, -17, 800, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-14, -17, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(41);
    toggleMOGO();
    chassis.moveToPoint(-30, -17, 1000, {.maxSpeed = DRIVESPEED});
    isIntaking = true;
}

void RedMOGO2() {
    isRedAlliance = true;
    chassis.setPose(-55, 40, 270);
    chassis.turnToPoint(-19, 19, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-19, 19, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(34);
    toggleMOGO();
    chassis.turnToPoint(-8, 37, 800, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    isIntaking = true;
    chassis.moveToPoint(-8, 37, 1200, {.maxSpeed = DRIVESPEED});
    pros::delay(500);
    chassis.moveToPoint(-19, 19, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-23.5, 47, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-23.5, 47, 1000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.turnToPoint(-7.5, 51.5, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-7.5, 51.5, 1000, {.maxSpeed = DRIVESPEED});
    pros::delay(600);
    chassis.moveToPoint(-23.5, 47, 800, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-12, 8, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-12, 8, 1000, {.maxSpeed = DRIVESPEED});
    isScoring = true;
}

void BlueRings() {
    isRedAlliance = false;
    chassis.setPose({54, 18.5, 180});
    chassis.turnToPoint(50, 9, 500, {.maxSpeed = TURNSPEED});
    toggleIntakeCount();
    isIntaking = true;
    chassis.moveToPoint(50, 9, 800, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleIntakeCount();
    pros::delay(840);
    isIntaking = false;
    chassis.moveToPoint(44, -3, 600, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleDoinker();
    chassis.turnToHeading(0, 800, {.direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = TURNSPEED});
    chassis.turnToPoint(70, 0, 1000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = TURNSPEED});
    pros::delay(500);
    toggleDoinker();
    chassis.moveToPoint(70, 0, 1250, {.forwards = false, .maxSpeed = 80, .minSpeed = 60, .earlyExitRange = 14.9});
    chassis.turnToHeading(250, 1000, {.maxSpeed = TURNSPEED});
    isIntaking = true;
    pros::delay(700);
    isIntaking = false;
    chassis.turnToPoint(40, 30, 1000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    isIntaking = true;
    chassis.moveToPoint(40, 30, 1500, {.maxSpeed = DRIVESPEED});
    pros::delay(900);
    isIntaking = false;
    chassis.moveToPoint(35, 37.8, 600, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(15.8, 18.3, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(15.8, 18.3, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(23);
    toggleMOGO();
    chassis.turnToPoint(18, 46, 800, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(18, 46, 1000, {.maxSpeed = DRIVESPEED});
    isIntaking = true;
    chassis.turnToPoint(3, 46.44, 700, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(3, 46.44, 700, {.maxSpeed = DRIVESPEED});
    pros::delay(500);
    chassis.moveToPoint(16, 42, 700, {.forwards = false, .maxSpeed = DRIVESPEED});
}

void BlueMOGO() {
    isRedAlliance = false;
    chassis.setPose({52, -60, 270});
    chassis.moveToPoint(13, -60, 1000, {.maxSpeed = 127});
    chassis.turnToHeading(280, 300, {.maxSpeed = 110});
    toggleDoinker();
    chassis.moveToPoint(30, -60, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToHeading(240, 750, {.maxSpeed = 80});
    chassis.turnToPoint(4, -58.7, 1200, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = TURNSPEED});
    toggleDoinker();
    chassis.moveToPoint(4, -58.7, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(15);
    toggleMOGO();
    chassis.turnToPoint(15, -47.3, 1000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    isIntaking = true;
    chassis.moveToPoint(15, -47.3, 1200, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    isIntaking = false;
    chassis.turnToPoint(18, -18, 1000, {.forwards = false, .direction = AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(18, -18, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(22);
    toggleMOGO();
    chassis.turnToPoint(45, -30, 1000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    isIntaking = true;
    chassis.moveToPoint(45, -30, 1000, {.maxSpeed = DRIVESPEED});
    // pros::delay(200);
    // chassis.turnToPoint(20, -12, 1000, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(20, -12, 1000, {.maxSpeed = DRIVESPEED});
    // isScoring = true;
}

void BlueMOGO2() {
    isRedAlliance = false;
    chassis.setPose(55, 40, 90);
    chassis.turnToPoint(19, 19, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(19, 19, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(34);
    toggleMOGO();
    chassis.turnToPoint(8, 37, 800, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    isIntaking = true;
    chassis.moveToPoint(8, 37, 1200, {.maxSpeed = DRIVESPEED});
    pros::delay(500);
    chassis.moveToPoint(19, 19, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(23.5, 47, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(23.5, 47, 1000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.turnToPoint(7.5, 51.5, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(7.5, 51.5, 1000, {.maxSpeed = DRIVESPEED});
    pros::delay(600);
    chassis.moveToPoint(23.5, 47, 800, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(12, 8, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(12, 8, 1000, {.maxSpeed = DRIVESPEED});
    isScoring = true;
}

void AutonomousSkills() {
    isRedAlliance = true;
    isColorSort = false;
    chassis.setPose(-61, 0, 90);
    isIntaking = true;
    pros::delay(300);
    chassis.moveToPoint(-47, 0, 1250, {.maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 2});
    chassis.turnToPoint(-47, 27, 800, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47, 27, 1300, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(23);
    toggleMOGO();
    chassis.turnToPoint(-23.5, 23.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 60, .earlyExitRange = 2});
    chassis.moveToPoint(-23.5, 23.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 60, .earlyExitRange = 3});
    chassis.turnToPoint(5, 47, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 70, .earlyExitRange = 2});
    chassis.moveToPoint(5, 47, 1500, {.maxSpeed = DRIVESPEED});
    isStaging = true;
    chassis.turnToPoint(5, 70, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(5, 70, 1000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    isScoring = true;
    pros::delay(1000);
    chassis.moveToPoint(5, 51, 1000, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 60, .earlyExitRange = 4});
    isZeroing = true;
    chassis.turnToPoint(-23.5, 51, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPose(-23.5, 51, 270, 1500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-60, 51, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-60, 51, 1500, {.maxSpeed = 90});
    chassis.turnToPoint(-47, 60, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47, 60, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    chassis.turnToPoint(-58.25, 64, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-58.25, 64, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    // isIntaking = false;
    // isReverseIntake = true;
    // toggleMOGO();
    // pros::delay(100);
    // chassis.moveToPoint(-44.5, 16.8, 2000, {.maxSpeed = DRIVESPEED});
    // isReverseIntake = false;
    // isIntaking = true;
    // chassis.setPose(chassis.getPose().x, chassis.getPose().y + 3, chassis.getPose().theta, false);
    // chassis.turnToPoint(-47.5, -25, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-47.5, -25, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    // chassis.waitUntil(30);
    // toggleMOGO();
    // chassis.turnToPoint(-23.5, -23.5, 1000, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-23.5, -23.5, 2000, {.maxSpeed = DRIVESPEED});
    // chassis.turnToPoint(-2, -57, 1500, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-2, -57, 2500, {.maxSpeed = DRIVESPEED});
    // chassis.turnToPoint(-23.5, -49, 1000, {.maxSpeed = TURNSPEED});
    // chassis.moveToPose(-23.5, -49, 270, 2000, {.maxSpeed = 70});
    // chassis.turnToPoint(-60, -49, 1500, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-60, -49, 2500, {.maxSpeed = DRIVESPEED});
    // chassis.waitUntilDone();
    // pros::delay(500);
    // chassis.turnToPoint(-47.25, -57, 1000, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-47.25, -57, 1500, {.maxSpeed = DRIVESPEED});
    // chassis.waitUntilDone();
    // pros::delay(500);
    // chassis.turnToPoint(-58.25, -64, 1200, {.forwards = false, .maxSpeed = TURNSPEED});
    // isIntaking = false;
    // isReverseIntake = true;
    // chassis.moveToPoint(-58.25, -64, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    // chassis.waitUntilDone();
    // toggleMOGO();
    // pros::delay(100);
    // chassis.moveToPoint(44, -27, 1500, {.maxSpeed = DRIVESPEED});
    // chassis.turnToPoint(48, 6.6, 1200, {.forwards = false, .maxSpeed = TURNSPEED});
    // chassis.moveToPoint(48, 6.6, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    // chassis.waitUntil(18);
    // toggleMOGO();
    // chassis.turnToPoint(44, 39.5, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    // chassis.moveToPoint(44, 39.5, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    // chassis.turnToPoint(59, 57, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    // chassis.moveToPoint(59, 57, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    // chassis.waitUntilDone();
    // toggleMOGO();
    // chassis.turnToPoint(44, 39.5, 1000, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(44, 39.5, 1500, {.maxSpeed = DRIVESPEED});
    
    // chassis.turnToPoint(57, -19, 1000, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(57, -19, 1500, {.maxSpeed = DRIVESPEED});
    
    // chassis.turnToPoint(60, -55, 1000, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(60, -55, 1500, {.maxSpeed = DRIVESPEED});
}
double target = 0;
void drive_example() {
    pros::Task print_task([]() {
        double start = pros::millis();
        while(true) {
            std::cout << std::to_string(chassis.getPose().x) << std::to_string(target) << std::to_string(pros::millis() - start) << "\n";
            pros::delay(10);
        }
    });
    target = 48;
    chassis.moveToPoint(0, 48, 5000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    pros::delay(500);
    target = 0;
    chassis.moveToPoint(0, 0, 5000, {.forwards = false, .maxSpeed = DRIVESPEED});
    pros::delay(500);
    target = 24;
    chassis.setPose({0, 0, 0});
    chassis.moveToPoint(0, 24, 5000, {.maxSpeed = DRIVESPEED});
    pros::delay(500);
    target = 0;
    chassis.moveToPoint(0, 0, 5000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
}
void turn_example() {
    pros::Task print_task([]() {
        double start = pros::millis();
        while(true) {
            std::cout << std::to_string(chassis.getPose().theta) << std::to_string(target) << std::to_string(pros::millis() - start) << "\n";
            pros::delay(10);
        }
    });
    target = 45;
    chassis.turnToHeading(45, 4000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    pros::delay(500);
    target = 90;
    chassis.turnToHeading(90, 4000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    pros::delay(500);
    target = 90;
    chassis.turnToHeading(135, 4000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    pros::delay(500);
    target = 180;
    chassis.turnToHeading(180, 4000, {.maxSpeed = TURNSPEED});
    pros::delay(500);
    target = 45;
    chassis.turnToHeading(45, 4000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    pros::delay(500);
    target = 90;
    chassis.turnToHeading(90, 4000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    pros::delay(500);
    target = 90;
    chassis.turnToHeading(135, 4000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    pros::delay(500);
    target = 180;
    chassis.turnToHeading(180, 4000, {.maxSpeed = TURNSPEED});
}

void curve_example() {
}