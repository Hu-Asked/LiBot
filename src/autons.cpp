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
    chassis.moveToPoint(-46, 27.2, 1300, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.waitUntil(21.7);
    toggleMOGO();
    chassis.turnToPoint(-20, 25.5, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    set_lb_pos(LB_STAGED_POSITION, 800);
    isIntaking = true;
    chassis.moveToPoint(-20, 25.5, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(4, 44.2, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 30, .earlyExitRange = 2});
    chassis.moveToPoint(4, 44.2, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 3});
    chassis.turnToPoint(1, 72.5, 1000, {.maxSpeed = TURNSPEED});
    isIntaking = false;
    chassis.moveToPoint(1, 72.5, 800, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    intake1.move_relative(-25, 400);
    set_lb_pos(LB_WALLSTAKE_POSITION, 600);
    waitForLb = pros::millis();
    while (pros::millis() - waitForLb < 650) {
        LeftDrive.move(-30);
        RightDrive.move(-30);
        if(pros::millis() - waitForLb >= 200) {
            isIntaking = true;
        }
        if(exitLB) {
            break;
        }
        pros::delay(5);
    }
    double rX = -8;
    double rY = -8;
    chassis.moveToPoint(rX, rY, 1500, {.forwards = false, .maxSpeed = 60, .minSpeed = 30, .earlyExitRange = 2});
    chassis.turnToPoint(-20, 47, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
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
    chassis.follow(path2_txt, 7, 8500);

    // chassis.moveToPoint(-20, -22.4, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.turnToPoint(-15.8, -48, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.moveToPoint(-15.8, -48, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.turnToPoint(-55.8, -52, 1000, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    // chassis.moveToPoint(-55.8, -52, 2500, {.maxSpeed = 75, .minSpeed = 10, .earlyExitRange = 1});
    
    chassis.swingToPoint(-46, -61, lemlib::DriveSide::RIGHT, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-46, -61, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(-55.25, -60, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    pros::delay(450);
    toggleMOGO();
    isIntaking = false;
    chassis.moveToPoint(-60.6, -61, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 0.5});
    
    
    chassis.moveToPoint(-40, -59, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    toggleMOGO();
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
    toggleMOGO();
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
    rX = calculate_relative_move_x(-12);
    rY = calculate_relative_move_y(-12);
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

void driveOffLine() {
    isRedAlliance = true;
    chassis.setPose({0, 0, 0});
    chassis.moveToPoint(0, 20, 1200, {.maxSpeed = 60});
}