#include "main.h"

void RedRings() {
    isRedAlliance = true;
    chassis.setPose({0, 0, 0});
    chassis.moveToPoint(0, 4, 1000, {.maxSpeed = 100});
    pros::delay(50);
    set_lb_pos(LB_SCORED_POSITION - 100, 700);
    pros::delay(650);
    chassis.moveToPoint(0, -4, 1000, {.forwards = false, .minSpeed = 60, .earlyExitRange = 1});
    chassis.turnToPoint(-23.5, -38, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 30, .earlyExitRange = 4});
    chassis.moveToPoint(-23.5, -38, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 15, .earlyExitRange = 4});
    isIntaking = true;
    set_lb_pos(LB_ZEROED_POSITION - 140, 1500);
    chassis.waitUntil(28.5);
    toggleMOGO();
    chassis.turnToPoint(6, -49.6, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(6, -49.6, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-6, -66.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 0.5});
    chassis.moveToPoint(-6, -66.5, 1500, {.maxSpeed = 60, .minSpeed = 5, .earlyExitRange = 0.5});
    chassis.moveToPoint(2, -52, 1000, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-13.5, -58.3, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-13.5, -58.3, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(19, -30, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(45.5, -34.3, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(45.5, -34.3, 200, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    LeftDrive.move(50);
    RightDrive.move(50);
    pros::delay(850);
    LeftDrive.move(-45);
    RightDrive.move(-45);
    pros::delay(350);
    LeftDrive.move(0);
    RightDrive.move(0);
    pros::delay(300);
    toggleIntakeCount();
    pros::delay(100);
    LeftDrive.move(50);
    RightDrive.move(50);
    pros::delay(500);
    toggleIntakeCount();
    pros::delay(250);
    LeftDrive.move(-60);
    RightDrive.move(-60);
    pros::delay(300);
    LeftDrive.move(0);
    RightDrive.move(0); 
    pros::delay(200);

    chassis.turnToPoint(-14.3, 2, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1}); 
    chassis.moveToPoint(-14.3, 2, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 60, .earlyExitRange = 23});
    toggleIntakeCount();
    chassis.moveToPoint(-14.3, 2, 1500, {.maxSpeed = 55});
    chassis.waitUntilDone();
    toggleIntakeCount();
    pros::delay(350);
    LeftDrive.move(-50);
    RightDrive.move(-50);
    pros::delay(500);
    LeftDrive.move(0);
    RightDrive.move(0);
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

double RIGHT_DISTANCE_SENSOR_OFFSET = 3;
void AutonomousSkills() { // 1.0460829493x -52.2281106 plot on desmos
    isRedAlliance = true;
    isColorSort = false;
    chassis.setPose(-61, 0, 90);
    isIntaking = true;
    pros::delay(300);
    isIntaking = false;
    chassis.moveToPoint(-47, 0, 1250, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToPoint(-46, 26, 800, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-46, 26, 1300, {.forwards = false, .maxSpeed = DRIVESPEED});
    isIntaking = true;
    chassis.waitUntil(21.5);
    toggleMOGO();
    chassis.turnToPoint(-23.5, 23.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-23.5, 23.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-12.5, 36, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 30, .earlyExitRange = 2});
    chassis.moveToPoint(-12.5, 36, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 3});
    chassis.moveToPoint(0, 61.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    set_lb_pos(LB_STAGED_POSITION, 1000);
    chassis.turnToPoint(1.6, 70, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(1.6, 70, 400, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    isIntaking = false;
    set_lb_pos(LB_SCORED_POSITION, 800);
    pros::delay(850);
    chassis.moveToPoint(0, 50, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 30, .earlyExitRange = 2});
    isIntaking = true;
    chassis.turnToPoint(-16, 47.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 40, .earlyExitRange = 3});
    set_lb_pos(LB_ZEROED_POSITION, 1200);
    chassis.moveToPoint(-25, 47.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 2});
    chassis.turnToPoint(-57, 47.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 40, .earlyExitRange = 2});
    chassis.moveToPoint(-57, 47.5, 1500, {.maxSpeed = 70});
    pros::delay(200);
    chassis.turnToPoint(-46.5, 63, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 40, .earlyExitRange = 2});
    chassis.moveToPoint(-46.5, 65, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 1});
    chassis.turnToPoint(-70, 68, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.moveToPoint(-70, 68, 400, {.forwards = false, .maxSpeed = DRIVESPEED,.minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-47, 0, 2000, {.maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-47, -26, 1500, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-47, -26, 2500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntil(22);
    toggleMOGO();
    chassis.turnToPoint(-22.5, -21.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-22.5, -21.5, 2000, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-14.5, -50, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-14.5, -50, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-56, -50, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-56, -50, 2000, {.maxSpeed = 80, .minSpeed = 10, .earlyExitRange = 1});
    chassis.swingToPoint(-39.5, -61, lemlib::DriveSide::RIGHT, 1000, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-39.5, -63, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-70, -66.5, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.moveToPoint(-70, -66.5, 500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});

    //reset
    //old
    chassis.moveToPoint(-40, -60, 2000, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-40, -80, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 40, .earlyExitRange = 4});
    chassis.moveToPoint(-40, -80, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    chassis.setPose(chassis.getPose().x, -70, 0);
    //new
    chassis.moveToPoint(-55, -50, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-55, -80, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 40, .earlyExitRange = 4});
    chassis.moveToPoint(-55, -80, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    chassis.setPose(62, chassis.getPose().y, 90);
    chassis.moveToPoint(47, chassis.getPose().y, 1000, {.maxSpeed = DRIVESPEED});
    chassis.setPose(chassis.getPose().x, calculate_reset_distance(RIGHT_DISTANCE_SENSOR_OFFSET, rightResetSensor.get_distance(), 90, chassis.getPose().theta), chassis.getPose().theta);

    // chassis.turnToPoint(0, -62.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    // set_lb_pos(LB_STAGED_POSITION, 1000);
    // chassis.moveToPoint(0, -62.5, 1000, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.turnToPoint(0, -70, 1000, {.maxSpeed = TURNSPEED});
    // chassis.moveToPoint(0, -70, 300, {.maxSpeed = DRIVESPEED});
    // isIntaking = false;
    // set_lb_pos(LB_SCORED_POSITION, 1000);
    // pros::delay(1050);
    // isIntaking = true;
    // chassis.moveToPoint(2, -56, 1000, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.turnToPoint(22.5, -28.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    // set_lb_pos(LB_ZEROED_POSITION, 1000);
    // chassis.moveToPoint(22.5, -28.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
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