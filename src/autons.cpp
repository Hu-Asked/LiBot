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
    chassis.moveToPoint(-14, -45, 1500, {.minSpeed = 10, .earlyExitRange = 1});
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
    chassis.moveToPoint(-5, -47, 1250, {.forwards = false, .maxSpeed = 110});
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
    chassis.setPose({53, -37, 270});
    chassis.moveToPoint(14, -49, 1000, {.minSpeed = 10, .earlyExitRange = 1});
    isIntaking = true;
    chassis.turnToHeading(253, 253, {.maxSpeed = 110});
    toggleDoinker();
    pros::delay(100);
    isIntaking = false;
    chassis.moveToPoint(31.5, -43, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleDoinker();
    pros::delay(150);
    chassis.turnToPoint(5, -47, 1000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(5, -47, 1250, {.forwards = false, .maxSpeed = 110});
    chassis.waitUntil(22.5);
    toggleMOGO();
    chassis.turnToPoint(-40.5, -58.25, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 4});
    chassis.moveToPoint(-40.5, -58.25, 1000, {.maxSpeed = DRIVESPEED});

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

void AutonomousSkills() { // 1.0460829493x -52.2281106 plot on desmos
    isRedAlliance = true;
    isColorSort = false;
    chassis.setPose(-61, 0, 90);
    isIntaking = true;
    pros::delay(300);
    chassis.moveToPoint(-47, 0, 1250, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-47, 26, 800, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47, 26, 1300, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(21.5);
    toggleMOGO();
    chassis.turnToPoint(-23.5, 23.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-23.5, 23.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(2, 57, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(2, 57, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-23.5, 51, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPose(-23.5, 51, 270, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-60, 51, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-60, 51, 1500, {.maxSpeed = 90});
    chassis.turnToPoint(-47, 60, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47, 60, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    chassis.turnToPoint(-57, 67, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-57, 67, 750, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.moveToPoint(-44.5, 16.8, 2000, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-43, -23, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-43, -23, 3200, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(30.5);
    toggleMOGO();
    chassis.turnToPoint(-23.5, -23.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-23.5, -23.5, 2000, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(2, -57, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(2, -57, 2500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.turnToPoint(-23.5, -49, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPose(-23.5, -49, 270, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-60, -49, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-60, -49, 2500, {.maxSpeed = 90});
    chassis.turnToPoint(-47.25, -57, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-47.25, -57, 1500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-57, -64, 1200, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-57, -64, 700, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.moveToPoint(30, -49.6, 2000, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    isIntaking = false;
    chassis.turnToPoint(49, 3, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(49, 3, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(50);
    toggleMOGO();
    chassis.turnToPoint(23.4, 21.6, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(23.4, 21.6, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    
    chassis.turnToPoint(23.4, 47, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(23.4, 47, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    
    chassis.turnToPoint(65, 48, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(65, 48, 2000, {.maxSpeed = DRIVESPEED});

    chassis.moveToPoint(23.4, 48, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(46.5, 63.7, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(46.5, 63.7, 1500, {.maxSpeed = DRIVESPEED});

    chassis.turnToPoint(57.8, 66, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.moveToPoint(57.8, 66, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.moveToPoint(23.4, 21.6, 2000, {.maxSpeed = DRIVESPEED});    
    chassis.turnToPoint(56, -14, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(56, -14, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntil(50);
    wingPiston.set_value(true);
    chassis.moveToPoint(64, -60, 2000, {.maxSpeed = DRIVESPEED});
    chassis.moveToPoint(52.3, -35.5, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(15.8, -35.7, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(15.8, -35.7, 1500, {.maxSpeed = DRIVESPEED});
    isClimbingInitiated = true;
    pros::Task climb(CLIMB, nullptr);
    chassis.turnToHeading(315, 1000, {.maxSpeed = TURNSPEED});
    // toggleClimb();
    // isClimbing = true;

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

void curve_example() {
}