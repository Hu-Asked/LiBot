#include "main.h"

void RedRings() {
    isRedAlliance = true;
    chassis.setPose({-51, 36.25, 90});
    isIntaking = true;
    chassis.moveToPoint(-21, 36.25, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 25, .earlyExitRange = 3});
    chassis.moveToPoint(-6, 41.8, 1500, {.maxSpeed = DRIVESPEED});
    chassis.moveToPoint(-22.5, 19, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    pros::delay(100);
    isIntaking = false;
    chassis.waitUntil(21.8);
    toggleMOGO();
    isIntaking = true;
    chassis.moveToPoint(-23, 47, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-4, 51.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-4, 51.5, 1500, {.maxSpeed = DRIVESPEED});
    chassis.moveToPoint(-47, 48, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-62.7, 61, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-62.7, 61, 1250, {.maxSpeed = DRIVESPEED});
    chassis.moveToPoint(-55, 54.5, 1000, {.forwards = false, .maxSpeed = 110});
    chassis.waitUntilDone();
    toggleIntakeCount();
    chassis.moveToPoint(-62.7, 61, 900, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleIntakeCount();
    chassis.moveToPoint(-55.7, 50, 1000, {.forwards = false, .maxSpeed = 60});
    chassis.turnToPoint(-51.65, 26, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-51.65, 26, 1250, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    set_lb_pos(LB_STAGED_POSITION, 1200);
    chassis.moveToPoint(-54.5, 8.8, 1500, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-70, -7.7, 1300, {.maxSpeed = TURNSPEED});
    isIntaking = false;
    set_lb_pos(LB_SCORED_POSITION, 1200);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(-47.5, 21, 1000, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    
    // chassis.turnToPoint(-41.7, 6.6, 1000, {.maxSpeed = TURNSPEED});
    // toggleIntakeCount();
    // isIntaking = true;
    // chassis.moveToPoint(-41.7, 6.6, 1000, {.maxSpeed = DRIVESPEED});
    // chassis.waitUntilDone();
    // toggleIntakeCount();
    // chassis.moveToPoint(-44, 18.3, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
}

void RedMOGO() {
    isRedAlliance = true;
    chassis.setPose(-52, -60, 90);
    chassis.moveToPoint(-13, -44.8, 2000, {.minSpeed = 10, .earlyExitRange = 1});
    isIntaking = true;
    chassis.turnToHeading(77, 600, {.minSpeed = 60, .earlyExitRange = 3});
    toggleDoinker();
    isIntaking = false;
    chassis.moveToPoint(-31.5, -47, 4000, {.forwards = false});
    chassis.waitUntilDone();
    toggleDoinker();
    pros::delay(350);
    chassis.turnToPoint(-10, -47, 1000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = 90});
    chassis.moveToPoint(-10, -47, 1500, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntil(16);
    toggleMOGO();
    chassis.moveToPoint(-36, -55, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    isIntaking = true;
    chassis.turnToHeading(37, 1000, {.direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    pros::delay(150);
    toggleMOGO();
    chassis.turnToPoint(-22.3, -20.3, 1300, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-22.3, -20.3, 2000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(29.7);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToPoint(-48, -27.8, 1000, {.minSpeed = 20, .earlyExitRange = 2});
    chassis.moveToPoint(-48, -27.8, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    chassis.moveToPoint(-55, -47, 1500);
    chassis.waitUntilDone();
    toggleDoinker();
    chassis.moveToPoint(-61 , -60, 1000, {.minSpeed = 30});
    chassis.turnToHeading(90, 1000, {.minSpeed = 80});
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
    chassis.moveToPoint(15.1, -50.5, 1000, {.minSpeed = 20, .earlyExitRange = 1});
    isIntaking = true;
    chassis.turnToHeading(254, 300, {.minSpeed = 40,});
    toggleDoinker();
    pros::delay(60);
    isIntaking = false;
    chassis.moveToPoint(31.5, -43, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleDoinker();
    pros::delay(350);
    chassis.turnToPoint(13, -48, 1000, {.forwards = false, .maxSpeed = 90});
    chassis.moveToPoint(13, -48, 1250, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntil(15);
    toggleMOGO();
    chassis.turnToPoint(26.25, -58.25, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 4});
    isIntaking = true;
    chassis.moveToPoint(26.25, -58.25, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    pros::delay(300);
    toggleMOGO();
    chassis.turnToPoint(23.5, -22, 1000, {.forwards = false, .maxSpeed = 90});
    chassis.moveToPoint(23.5, -22, 1250, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntil(27.3);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToPoint(39, -30.2, 1000, {.minSpeed = 20, .earlyExitRange = 4});
    chassis.moveToPoint(39, -30.2, 1500, {.minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(55.275, -49, 1000, {.minSpeed = 20, .earlyExitRange = 4});
    chassis.moveToPoint(55.275, -49, 1500, {.minSpeed = 50, .earlyExitRange = 1});
    chassis.moveToPoint(60, -55, 1000, {.minSpeed = 60, .earlyExitRange = 2});
    chassis.waitUntilDone();
    toggleDoinker();
    chassis.moveToPoint(57.5, -64, 1000, {.minSpeed = 50, .earlyExitRange = 2});
    chassis.turnToHeading(70, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 127});
    chassis.waitUntilDone();
    toggleDoinker();
    chassis.moveToPoint(52, -64, 500, {.forwards = false , .minSpeed = 120, .earlyExitRange = 1});
    chassis.moveToPoint(65, -64, 1000, {.minSpeed = 100});
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
    pros::delay(700);
    chassis.moveToPoint(-47, 0, 1250, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-46, 26, 800, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-46, 26, 1300, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(21.5);
    toggleMOGO();
    chassis.turnToPoint(-23.5, 23.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-23.5, 23.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(0, 61.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 8});
    chassis.moveToPoint(0, 61.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-16, 48, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPose(-25, 48, 270, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 1});
    chassis.turnToPoint(-56.3, 46.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-56.3, 46.5, 1500, {.maxSpeed = 85});
    pros::delay(200);
    // chassis.waitUntilDone();
    // chassis.turnToPoint(-57, 67, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-57, 67, 750, {.forwards = false, .maxSpeed = DRIVESPEED});
    // chassis.waitUntilDone();
    // toggleMOGO();
    // chassis.moveToPoint(-44.5, 16.8, 2000, {.maxSpeed = DRIVESPEED});
    // chassis.turnToPoint(-43, -23, 1500, {.forwards = false, .maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-43, -23, 3200, {.forwards = false, .maxSpeed = DRIVESPEED});
    // chassis.waitUntil(30.5);
    // toggleMOGO();
    // chassis.turnToPoint(-23.5, -23.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.moveToPoint(-23.5, -23.5, 2000, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.turnToPoint(2, -57, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.moveToPoint(2, -57, 2500, {.maxSpeed = DRIVESPEED});
    // chassis.waitUntilDone();
    // pros::delay(200);
    // chassis.turnToPoint(-23.5, -49, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.moveToPose(-23.5, -49, 270, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.turnToPoint(-60, -49, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.moveToPoint(-60, -49, 2500, {.maxSpeed = 90});
    // chassis.turnToPoint(-47.25, -57, 1000, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-47.25, -57, 1500, {.maxSpeed = DRIVESPEED});
    // chassis.turnToPoint(-57, -64, 1200, {.forwards = false, .maxSpeed = TURNSPEED});
    // chassis.moveToPoint(-57, -64, 700, {.forwards = false, .maxSpeed = DRIVESPEED});
    // chassis.waitUntilDone();
    // toggleMOGO();
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