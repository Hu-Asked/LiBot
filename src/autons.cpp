#include "main.h"

void RedRings() {
    isRedAlliance = true;
    chassis.setPose({-62, 40.5, -90});
    chassis.moveToPoint(-49, 40.5, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-22, 22, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-22, 22, 3000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(26);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToPoint(-4, 40, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-4, 40, 2000, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-3, 51, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-3, 51, 2000, {.maxSpeed = DRIVESPEED});
    pros::delay(500);
    chassis.moveToPoint(-23.5, 23.5, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-23.5, 47, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-23.5, 45, 1500, {.maxSpeed = DRIVESPEED});
    pros::delay(100);
    chassis.turnToPoint(-47, 0, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47, 0, 1500, {.maxSpeed = DRIVESPEED});
    //activateDoinker();
    //do some sweep, turn to 90 degrees, then score alliance maybe go to ladder.
}

void RedMOGO() {
    isRedAlliance = true;
    chassis.setPose({-50, -60, 90});
    chassis.moveToPoint(-10, -60, 800, {.maxSpeed = 120});
    chassis.turnToHeading(20, 400, {.maxSpeed = 100});
    chassis.waitUntilDone();
    toggleDoinker();
    pros::delay(200);
    chassis.turnToHeading(-30, 1000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    toggleDoinker();
    chassis.turnToHeading(-27, 500, {.maxSpeed = 60});
    chassis.turnToHeading(185, 1000, {.direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = 90});
    chassis.moveToPoint(-10, -36, 1250, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(20);
    toggleMOGO();
    isIntaking = true;
    pros::delay(200);
    chassis.turnToPoint(-22, -46, 1000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.moveToPoint(-22, -46, 1000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    isIntaking = false;
    chassis.turnToPoint(-23.5, -18, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-23.5, -18, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(22);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToPoint(42.5, -4.5, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(42.5, -4.5, 1200, {.maxSpeed = 80});
    toggleIntakeCount();
    chassis.waitUntilDone();
    toggleIntakeCount();
    pros::delay(600);
    chassis.moveToPose(25, -55, 0, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
}

void RedMOGO2() {
}

void BlueRings() {
    isRedAlliance = false;
    chassis.setPose({51, 40.5, 90});
    chassis.turnToPoint(22, 22, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(22, 22, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(28);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToPoint(7.8, 39.351, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(7.8, 39.351, 2000, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(5.835, 52.3, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(5.835, 52.3, 2000, {.maxSpeed = DRIVESPEED});
    pros::delay(500);
    chassis.moveToPoint(23.5, 23.5, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(23.5, 47, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(23.5, 45, 1500, {.maxSpeed = DRIVESPEED});
    pros::delay(200);
    chassis.turnToPoint(47, 0, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(47, 0, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    pros::delay(150);  
    isIntaking = false;
    toggleDoinker();
    chassis.turnToPoint(60, -2, 1500, {.forwards = false,.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(60, -2, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.moveToPoint(58.8, -2, 2000, {.maxSpeed = 30});
    chassis.waitUntil(0.5);
    isIntaking = true;
    pros::delay(600);
    chassis.moveToPoint(30, 0, 1500, {.maxSpeed = 80});
}

void BlueMOGO() {
    isRedAlliance = false;
    chassis.setPose({49, -60, 270});
    chassis.moveToPoint(12, -60, 1000, {.maxSpeed = DRIVESPEED, .earlyExitRange = 36});
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
    pros::delay(200);
    chassis.turnToPoint(24, -46, 1000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.moveToPoint(23.5, -47.154, 1000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    isIntaking = false;
    chassis.turnToPoint(23.5, -18, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(23.5, -18, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(22);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToPoint(42.5, -4.5, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(42.5, -4.5, 1200, {.maxSpeed = 80});
    toggleIntakeCount();
    chassis.waitUntilDone();
    toggleIntakeCount();
    pros::delay(600);
    chassis.moveToPose(25, -55, 0, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
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

void AutonomousSkills() {
    isRedAlliance = true;
    chassis.setPose(-59, 0, 90);
    isIntaking = true;
    pros::delay(500);
    chassis.moveToPoint(-47, 0, 1250, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-47, 27, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47, 27, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(23);
    toggleMOGO();
    chassis.turnToPoint(-23.5, 23.5, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-23.5, 23.5, 1500, {.maxSpeed = DRIVESPEED});
    isIntaking = true;
    chassis.turnToPoint(-2, 57, 1250, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-2, 57, 2000, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-23.5, 49, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPose(-23.5, 49, 270, 2000, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-60, 49, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-60, 49, 2500, {.maxSpeed = 70});
    chassis.turnToPoint(-47.25, 57, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47.25, 57, 2500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-58.25, 64, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    isIntaking = false;
    isReverseIntake = true;
    chassis.moveToPoint(-58.25, 64, 2500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    pros::delay(100);
    chassis.moveToPoint(-44.5, 16.8, 2000, {.maxSpeed = DRIVESPEED});
    isReverseIntake = false;
    isIntaking = true;
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
    chassis.turnToPoint(-47.25, -57, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47.25, -57, 1500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-58.25, -64, 1200, {.forwards = false, .maxSpeed = TURNSPEED});
    isIntaking = false;
    isReverseIntake = true;
    chassis.moveToPoint(-58.25, -64, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.turnToPoint(23.5, -47, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(23.5, -47, 1500, {.maxSpeed = DRIVESPEED});
    isReverseIntake = false;
    isIntaking = true;
    chassis.waitUntilDone();
    isStaging = true;
    chassis.moveToPoint(0, -47, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    isIntaking = false;
    chassis.turnToPoint(0, -60, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(0, -60, 1500, {.maxSpeed = DRIVESPEED});
    isScoring = true;
    chassis.moveToPoint(0, -47, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .earlyExitRange = 5});
    chassis.turnToPoint(23.5, -23.5, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(23.5, -23.5, 1500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(50, 2.7, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(50, 2.7, 2000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(34);
    toggleMOGO();

}

void drive_example() {
    chassis.moveToPose(0, 24, 0, 10000, {.maxSpeed = DRIVESPEED});
}

void turn_example() {
    chassis.turnToHeading(90, 1000, {.maxSpeed = TURNSPEED});
}

void curve_example() {
}
