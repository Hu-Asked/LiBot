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
    chassis.moveToPoint(-14.5, -37, 1000, {.maxSpeed = DRIVESPEED});
    chassis.turnToHeading(100, 400, {.maxSpeed = TURNSPEED});
    toggleDoinker();
    chassis.turnToHeading(172, 1200, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    toggleDoinker();
    pros::delay(300);
    chassis.turnToHeading(0, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-8, -58, 1250, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(19);
    toggleMOGO();
    isIntaking = true;
    pros::delay(700);
    chassis.turnToPoint(-27.2, -48.2, 1000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.moveToPoint(-27.2, -48.2, 1000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    isIntaking = false;
    chassis.turnToPoint(-17, -20, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-17, -20, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(23);
    toggleMOGO();
    chassis.turnToPoint(-39, -52, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-39, -52, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntil(8);
    isIntaking = true;
}

void RedMOGO2() {
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
    chassis.moveToPoint(12, -60, 1000, {.maxSpeed = 127, .earlyExitRange = 36});
    chassis.turnToHeading(300, 300, {.maxSpeed = 110});
    toggleDoinker();
    chassis.turnToHeading(350, 1000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    toggleDoinker();
    chassis.turnToHeading(340, 500, {.maxSpeed = 70});
    chassis.turnToHeading(180, 1000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed = 90});
    chassis.moveToPoint(10, -36, 1250, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(20);
    toggleMOGO();
    isIntaking = true;
    pros::delay(700);
    chassis.turnToPoint(17.5, -43, 1000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.moveToPoint(17.5, -43, 1000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    isIntaking = false;
    chassis.turnToPoint(17.5, -17, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(17.5, -17, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(23);
    toggleMOGO();
    chassis.turnToPoint(39, -52, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(39, -52, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntil(8);
    isIntaking = true;
}

void BlueMOGO2() {
    isRedAlliance = false;
    chassis.setPose(51.5, -30, 90);
    chassis.moveToPoint(35, -30, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(22, -22, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(22, -22, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(10);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToPoint(23.5, -47, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(23.5, -47, 1000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    pros::delay(250);
    toggleMOGO();
    chassis.turnToPoint(41, -10, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(41, -10, 1000, {.maxSpeed = DRIVESPEED});
    toggleIntakeCount();
    chassis.waitUntilDone();
    toggleIntakeCount();
    pros::delay(600);
    isIntaking = false;
    chassis.turnToHeading(90, 650, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    toggleDoinker();
    pros::delay(400);
    chassis.turnToPoint(60, -2, 1000, {.forwards = false, .direction = AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(60, -2, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    toggleDoinker();
    chassis.moveToPose(57, -2, 1000, 90, {.maxSpeed = 60});
    chassis.waitUntilDone();
    isIntaking = true;
    pros::delay(1500);
    chassis.moveToPoint(30, 0, 1500, {.maxSpeed = DRIVESPEED});
}

ASSET(skillsfirstpath_txt);
ASSET(skillssecondpath_txt);
ASSET(skillsthirdpath_txt);
void AutonomousSkills() {
    isRedAlliance = true;
    chassis.setPose(-60.5, 0, 90);
    isIntaking = true;
    pros::delay(500);
    chassis.moveToPoint(-47, 0, 1250, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-47, 27, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-46, 27, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(23);
    toggleMOGO();
    chassis.turnToPoint(-18, 23.5, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-18, 23.5, 1500, {.maxSpeed = DRIVESPEED});
    isIntaking = true;
    chassis.turnToPoint(2, 59, 1250, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(2, 59, 2000, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-23.5, 50, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPose(-23.5, 50, 270, 2000, {.maxSpeed = DRIVESPEED});
    // chassis.turnToPoint(-60, 49, 1500, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-60, 49, 2500, {.maxSpeed = 70});
    // chassis.turnToPoint(-47, 60, 1000, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-47, 60, 1500, {.maxSpeed = DRIVESPEED});
    // chassis.turnToPoint(-58.25, 64, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-58.25, 64, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    // chassis.waitUntilDone();
    // isIntaking = false;
    // isReverseIntake = true;
    // toggleMOGO();
    // // pros::delay(100);
    // chassis.moveToPoint(-44.5, 16.8, 2000, {.maxSpeed = DRIVESPEED});
    // isReverseIntake = false;
    // isIntaking = true;
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
    // chassis.turnToPoint(-47.25, -57, 1000, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-47.25, -57, 1500, {.maxSpeed = DRIVESPEED});
    // chassis.turnToPoint(-58.25, -64, 1200, {.forwards = false, .maxSpeed = TURNSPEED});
    // isIntaking = false;
    // isReverseIntake = true;
    // chassis.moveToPoint(-58.25, -64, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    // chassis.waitUntilDone();
    // toggleMOGO();
    // chassis.turnToPoint(23.5, -47, 1000, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(23.5, -47, 1500, {.maxSpeed = DRIVESPEED});
}

void drive_example() {
    chassis.moveToPoint(0, 48, 10000, {.maxSpeed = DRIVESPEED});
}

void turn_example() {
    chassis.turnToHeading(90, 1000, {.maxSpeed = TURNSPEED});
}

void curve_example() {
}
