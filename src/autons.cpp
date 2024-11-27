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
    chassis.setPose({-53, -37, 90});
    chassis.moveToPoint(-14.5, -37, 1000, {.maxSpeed = 127, .minSpeed = 60, .earlyExitRange = 4});
    chassis.turnToHeading(100, 400, {.maxSpeed = TURNSPEED});
    pros::delay(100);
    toggleDoinker();
    chassis.moveToPoint(-31, -37, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleDoinker();
    pros::delay(200);
    chassis.turnToPoint(-17, -14, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-17, -14, 1250, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(20);
    toggleMOGO();
    chassis.turnToPoint(-35, -14, 800, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-35, -14, 1000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    isIntaking = true;
    pros::delay(800);
    chassis.turnToHeading(180, 800, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    pros::delay(100);
    chassis.turnToPoint(-4.5, -43, 1300, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-4.5, -43, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(30);
    toggleMOGO();
    chassis.turnToPoint(-23.5, -51, 800, {.maxSpeed = TURNSPEED});
    isIntaking = true;
    chassis.moveToPoint(-23.5, -51, 1000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    pros::delay(900);
    isIntaking = false;
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
    chassis.moveToPoint(25, -60, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToHeading(270, 500, {.maxSpeed = 80});
    toggleDoinker();
    pros::delay(150);
    chassis.turnToPoint(2, -54.6, 1200, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(2, -54.6, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
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

ASSET(skillsfirstpath_txt);
ASSET(skillssecondpath_txt);
ASSET(skillsthirdpath_txt);
void AutonomousSkills() {
    isRedAlliance = true;
    chassis.setPose(-61, 0, 90);
    isIntaking = true;
    pros::delay(300);
    chassis.moveToPoint(-47, 0, 1250, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-47, 27, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47, 27, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(23);
    toggleMOGO();
    chassis.turnToPoint(-18, 23.5, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-18, 23.5, 1500, {.maxSpeed = DRIVESPEED});
    isIntaking = true;
    chassis.turnToPoint(2, 59, 1250, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(2, 59, 2000, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-23.5, 51, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPose(-23.5, 51, 270, 2000, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-60, 51, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-60, 51, 2500, {.maxSpeed = 70});
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.turnToPoint(-47, 60, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47, 60, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.turnToPoint(-58.25, 64, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-58.25, 64, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    isIntaking = false;
    isReverseIntake = true;
    toggleMOGO();
    pros::delay(100);
    chassis.moveToPoint(-44.5, 16.8, 2000, {.maxSpeed = DRIVESPEED});
    isReverseIntake = false;
    isIntaking = true;
    chassis.setPose(chassis.getPose().x, chassis.getPose().y + 3, chassis.getPose().theta, false);
    chassis.turnToPoint(-47.5, -25, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47.5, -25, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(30);
    toggleMOGO();
    chassis.turnToPoint(-23.5, -23.5, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-23.5, -23.5, 2000, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-2, -57, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-2, -57, 2500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-23.5, -49, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPose(-23.5, -49, 270, 2000, {.maxSpeed = 70});
    chassis.turnToPoint(-60, -49, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-60, -49, 2500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.turnToPoint(-47.25, -57, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47.25, -57, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.turnToPoint(-58.25, -64, 1200, {.forwards = false, .maxSpeed = TURNSPEED});
    isIntaking = false;
    isReverseIntake = true;
    chassis.moveToPoint(-58.25, -64, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    pros::delay(100);
    chassis.moveToPoint(44, -27, 1500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(48, 6.6, 1200, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(48, 6.6, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(18);
    toggleMOGO();
    chassis.turnToPoint(44, 39.5, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(44, 39.5, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(59, 57, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(59, 57, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.turnToPoint(44, 39.5, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(44, 39.5, 1500, {.maxSpeed = DRIVESPEED});
    
    chassis.turnToPoint(57, -19, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(57, -19, 1500, {.maxSpeed = DRIVESPEED});
    
    chassis.turnToPoint(60, -55, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(60, -55, 1500, {.maxSpeed = DRIVESPEED});
}

void drive_example() {
    chassis.moveToPoint(0, 48, 10000, {.maxSpeed = DRIVESPEED});
}

void turn_example() {
    chassis.turnToHeading(90, 1000, {.maxSpeed = TURNSPEED});
}

void curve_example() {
}