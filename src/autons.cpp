#include "main.h"

void RedRings() {
    isRedAlliance = true;
    chassis.setPose({0, 0, 0});
    chassis.moveToPoint(0, 4, 1000, {.maxSpeed = 100});
    pros::delay(50);
    set_lb_pos(860 - 90, 500);
    pros::delay(450);
    chassis.moveToPoint(0, -4, 1000, {.forwards = false, .minSpeed = 60, .earlyExitRange = 1});
    chassis.turnToPoint(-23.5, -38, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 30, .earlyExitRange = 4});
    chassis.moveToPoint(-23.5, -38, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 15, .earlyExitRange = 6});
    isIntaking = true;
    set_lb_pos(LB_ZEROED_POSITION - 150, 1200);
    chassis.waitUntil(28.5);
    toggleMOGO();
    chassis.turnToPoint(-16.7, -54, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 2});
    chassis.moveToPoint(-16.7, -54, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-3.5, -68.2, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 2});
    chassis.moveToPoint(-3.5, -68.2, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 5, .earlyExitRange = 1});
    // lb1.tare_position();
    // lb2.tare_position();
    chassis.moveToPoint(-19, -38.5, 1000, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-3.5, -49.6, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-3.5, -49.6, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(32.9, -32, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(32.9, -32, 2200, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToHeading(93, 1000, {.minSpeed = 20, .earlyExitRange = 1});
    chassis.waitUntilDone();
    double pointX = calculate_relative_move_x(30);
    double pointY = calculate_relative_move_y(30);
    chassis.moveToPoint(pointX, pointY, 850, {.maxSpeed = 80, .minSpeed = 80, .earlyExitRange = 1});
    chassis.waitUntilDone();
    LeftDrive.move(-35);
    RightDrive.move(-35);
    pros::delay(307);
    LeftDrive.move(0);
    RightDrive.move(0);
    pros::delay(100);
    toggleIntakeCount();
    pros::delay(50);
    chassis.moveToPoint(pointX, pointY, 600, {.maxSpeed = 60, .minSpeed = 60, .earlyExitRange = 1});
    pros::delay(500);
    toggleIntakeCount();
    chassis.moveToPoint(calculate_relative_move_x(-20), calculate_relative_move_y(-20), 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-12, -4.9, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-12, -4.9, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 20});
    toggleIntakeCount();
    chassis.moveToPoint(-13, -3.4, 1500, {.maxSpeed = 45, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    toggleIntakeCount();
    chassis.moveToPoint(calculate_relative_move_x(-15), calculate_relative_move_y(-15), 1500, {.forwards = false, .maxSpeed = 45, .minSpeed = 20});
}

void RedMOGO() {
    isRedAlliance = true;
    chassis.setPose(-52, -60, 90);
    chassis.moveToPoint(-13, -44.8, 2000, {.minSpeed = 10, .earlyExitRange = 1});
    isIntaking = true;
    chassis.turnToHeading(77, 600, {.minSpeed = 60, .earlyExitRange = 3});
    toggleLeftDoinker();
    isIntaking = false;
    chassis.moveToPoint(-31.5, -47, 4000, {.forwards = false});
    chassis.waitUntilDone();
    toggleLeftDoinker();
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
    toggleLeftDoinker();
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
    chassis.setPose({0, 0, 0});
    chassis.moveToPoint(0, 4, 1000, {.maxSpeed = 100});
    pros::delay(50);
    set_lb_pos(860 - 90, 500);
    pros::delay(450);
    chassis.moveToPoint(0, -4, 1000, {.forwards = false, .minSpeed = 60, .earlyExitRange = 1});
    chassis.turnToPoint(23.5, -38, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 30, .earlyExitRange = 4});
    chassis.moveToPoint(23.5, -38, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 15, .earlyExitRange = 6});
    isIntaking = true;
    set_lb_pos(LB_ZEROED_POSITION - 150, 1200);
    chassis.waitUntil(28.5);
    toggleMOGO();
    chassis.turnToPoint(25, -54, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 2});
    chassis.moveToPoint(25, -54, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.turnToPoint(13, -69, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 2});
    chassis.moveToPoint(13, -69, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 5, .earlyExitRange = 1});
    // lb1.tare_position();
    // lb2.tare_position();
    chassis.moveToPoint(19, -38.5, 1000, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(3.5, -49.6, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(3.5, -49.6, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-32.9, -32, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-32.9, -32, 2200, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToHeading(267, 450, {.minSpeed = 35, .earlyExitRange = 1});
    chassis.waitUntilDone();
    double pointX = calculate_relative_move_x(30);
    double pointY = calculate_relative_move_y(30);
    chassis.moveToPoint(pointX, pointY, 850, {.maxSpeed = 80, .minSpeed = 80, .earlyExitRange = 1});
    chassis.waitUntilDone();
    LeftDrive.move(-35);
    RightDrive.move(-35);
    pros::delay(307);
    LeftDrive.move(0);
    RightDrive.move(0);
    pros::delay(100);
    toggleIntakeCount();
    pros::delay(50);
    chassis.moveToPoint(pointX, pointY, 600, {.maxSpeed = 60, .minSpeed = 60, .earlyExitRange = 1});
    pros::delay(500);
    toggleIntakeCount();
    chassis.moveToPoint(calculate_relative_move_x(-20), calculate_relative_move_y(-20), 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(14.5, 2.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(14.5, 2.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 20});
    toggleIntakeCount();
    chassis.moveToPoint(14.5, 2.5, 1500, {.maxSpeed = 45, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    toggleIntakeCount();
    chassis.moveToPoint(calculate_relative_move_x(-15), calculate_relative_move_y(-15), 1500, {.forwards = false, .maxSpeed = 45, .minSpeed = 20});
}

void BlueMOGO() {
    isRedAlliance = false;
    chassis.setPose({53, -37, 270});
    chassis.moveToPoint(15.1, -50.5, 1000, {.minSpeed = 20, .earlyExitRange = 1});
    isIntaking = true;
    chassis.turnToHeading(254, 300, {.minSpeed = 40,});
    toggleLeftDoinker();
    pros::delay(60);
    isIntaking = false;
    chassis.moveToPoint(31.5, -43, 1000, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    toggleLeftDoinker();
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
    toggleLeftDoinker();
    chassis.moveToPoint(57.5, -64, 1000, {.minSpeed = 50, .earlyExitRange = 2});
    chassis.turnToHeading(70, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 127});
    chassis.waitUntilDone();
    toggleLeftDoinker();
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

double LEFT_DISTANCE_SENSOR_OFFSET = 3.3;
ASSET(path2_txt);
void AutonomousSkills() { // 1.0460829493x -52.2281106 plot on desmos
    isRedAlliance = true;
    isColorSort = false;
    double waitForLb = 0;
    
    chassis.setPose(-61, 0, 90);
    isIntaking = true;
    pros::delay(500);
    isIntaking = false;
    chassis.moveToPoint(-47, 0, 1250, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToPoint(-46, 27.2, 800, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-46, 27.2, 1300, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(21.7);
    toggleMOGO();
    chassis.turnToPoint(-20, 25.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    isIntaking = true;
    chassis.moveToPoint(-20, 25.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-12.5, 36, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 30, .earlyExitRange = 2});
    chassis.moveToPoint(-12.5, 36, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 3});
    chassis.moveToPoint(0, 59.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    set_lb_pos(LB_STAGED_POSITION, 800);
    chassis.turnToPoint(1, 72.5, 1000, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(1, 72.5, 300, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    isIntaking = false;
    intake1.move_relative(-50, 60);
    set_lb_pos(LB_WALLSTAKE_POSITION, 600);
    waitForLb = pros::millis();
    while (pros::millis() - waitForLb < 650) {
        if(exitLB) {
            break;
        }
        pros::delay(5);
    }
    chassis.moveToPoint(0, 50, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 30, .earlyExitRange = 2});
    chassis.turnToPoint(-20, 47, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    isIntaking = true;
    set_lb_pos(LB_ZEROED_POSITION, 1000);
    chassis.moveToPoint(-20, 47, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-62, 47, 2500, {.maxSpeed = 75, .minSpeed = 10, .earlyExitRange = 1});
    chassis.swingToPoint(-49, 60, lemlib::DriveSide::LEFT, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-49, 60, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-54, 65.5, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    pros::delay(450);
    toggleMOGO();
    isIntaking = false;
    chassis.moveToPoint(-54, 65.5, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-47, 2, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-49, -27.7, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    chassis.moveToPoint(-49, -27.7, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 0.2});
    chassis.waitUntil(20.7);
    toggleMOGO();
    chassis.turnToPoint(-20, -22.4, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    isIntaking = true;                      
    chassis.follow(path2_txt, 6, 7500);

    // chassis.moveToPoint(-20, -22.4, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.turnToPoint(-15.8, -48, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.moveToPoint(-15.8, -48, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.turnToPoint(-55.8, -52, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.moveToPoint(-55.8, -52, 2500, {.maxSpeed = 75, .minSpeed = 10, .earlyExitRange = 1});
    
    chassis.swingToPoint(-45.75, -59, lemlib::DriveSide::RIGHT, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-45.75, -59, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-55.25, -60, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    pros::delay(450);
    toggleMOGO();
    isIntaking = false;
    chassis.moveToPoint(-55.25, -60, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-40, -59, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-40, -80, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-40, -80, 600, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    
    chassis.setPose(chassis.getPose().x, -68, 0);
    pros::delay(50);
    chassis.moveToPoint(chassis.getPose().x, -35, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    toggleLeftDoinker();
    chassis.waitUntilDone();
    // the reset_distance represents the tracking center's distance from the wall, so figure out a way to translate that into an actual coordinate 
    chassis.setPose(-70 + calculate_reset_distance(LEFT_DISTANCE_SENSOR_OFFSET, leftResetSensor.get_distance(), 0, chassis.getPose().theta), chassis.getPose().y, chassis.getPose().theta);
    pros::delay(50);
    toggleLeftDoinker();
    chassis.turnToPoint(1, -61.75, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    set_lb_pos(LB_STAGED_POSITION, 900);
    chassis.moveToPoint(1, -61.75, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(7, -75, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(7, -75, 300, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    set_lb_pos(LB_WALLSTAKE_POSITION, 600);
    waitForLb = pros::millis();
    while (pros::millis() - waitForLb < 650) {
        if(exitLB) {
            break;
        }
        pros::delay(5);
    }
    chassis.moveToPoint(0, -51, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(25, -48.7, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(25, -48.7, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    set_lb_pos(LB_STAGED_POSITION, 1000);
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.turnToPoint(25.9, -28.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    isIntaking = false;
    set_lb_pos(LB_STAGED_POSITION + 200, 800);
    chassis.moveToPoint(25.9, -28.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    pros::delay(200);
    isIntaking = true;
    chassis.turnToPoint(55.5, -1.65, 1000, {.forwards = false, .maxSpeed = TURNSPEED});
    isIntaking = false;
    chassis.moveToPoint(55.5, -1.65, 1500, {.forwards = false, .maxSpeed = 100, .minSpeed = 15});
    chassis.waitUntil(24.6);
    toggleMOGO();
    isIntaking = true;
    chassis.turnToPoint(70, 0, 1000, {.maxSpeed = TURNSPEED});
    chassis.waitUntilDone();
    set_lb_pos(LB_ALLIANCESTAKE_POSITION, 500);
    waitForLb = pros::millis();
    while (pros::millis() - waitForLb < 550) {
        if(exitLB) {
            break;
        }
        pros::delay(5);
    }
    set_lb_pos(LB_ZEROED_POSITION, 1200);
    chassis.turnToPoint(25.5, 21, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(25.5, 21, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(47.7, 49, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.moveToPoint(47.7, 49, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.turnToPoint(47.3, 63, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.moveToPoint(47.3, 63, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1});
    // chassis.moveToPoint(47.7, 49, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1});
    // chassis.turnToPoint(63, 53, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 1});
    // chassis.moveToPoint(63, 53, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.turnToPoint(66.7, 62, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    pros::delay(300);
    toggleMOGO();
    isIntaking = false;
    chassis.moveToPoint(66.7, 62, 1000, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(38.8, 27, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.turnToPoint(27, 50.85, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.moveToPoint(27, 50.85, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    // isIntaking = false;
    chassis.turnToPoint(66, -16.37, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(66, -16.37, 1700, {.maxSpeed = 127, .minSpeed = 127, .earlyExitRange = 4});
    chassis.moveToPoint(72, -63, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    double rX = calculate_relative_move_x(-12);
    double rY = calculate_relative_move_y(-12);
    chassis.moveToPoint(rX, rY, 1500, {.forwards = false, .maxSpeed = 70, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(5, -59, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    isIntaking = true;
    chassis.moveToPoint(5, -59, 2000, {.maxSpeed = DRIVESPEED});
    pros::delay(600);
    isIntaking = false;
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