#include "main.h"

void RedRings() {
    isRedAlliance = true;  
    chassis.setPose(0, 0, 0);
    toggleLeftDoinker();
    chassis.moveToPoint(1.5, 50, 1500);
    isIntaking = true;
    isSavingRing = true;
    chassis.waitUntilDone();
    pros::delay(150);
    chassis.swingToPoint(18.5, 21.5, lemlib::DriveSide::RIGHT, 700, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 70, .earlyExitRange = 2});
    chassis.moveToPoint(18.5, 21.5, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 35, .earlyExitRange = 0.5});
    chassis.waitUntil(17);
    toggleMOGO();
    chassis.waitUntilDone();
    toggleLeftDoinker();
    isSavingRing = false;
    isIntaking = true;
    pros::delay(50);
    chassis.turnToPoint(-17, 40, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 0.5});
    isIntaking = true;
    chassis.moveToPoint(-17, 40, 1500, {.maxSpeed = 70, .minSpeed = 20, .earlyExitRange = 3});
    chassis.turnToPoint(-30, 14, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(-30, 14, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 3});
    chassis.turnToPoint(-41, 9.1, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});
    chassis.waitUntilDone();
    LeftDrive.move(65);
    RightDrive.move(65);
    pros::delay(900);
    LeftDrive.move(-25);
    RightDrive.move(-25);
    pros::delay(450);
    LeftDrive.move(0);
    RightDrive.move(0);
    pros::delay(250);
    chassis.swingToPoint(-7.25, 5, lemlib::DriveSide::RIGHT, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 1.5});
    chassis.moveToPoint(-7.25, 5, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToPoint(18, -1.9, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});
    chassis.waitUntilDone();
    toggleIntakeCount();
    chassis.moveToPoint(18, -1.9, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntilDone();
    pros::delay(50);
    toggleIntakeCount();
    pros::delay(20);
    LeftDrive.move(-50);
    RightDrive.move(-50);
    pros::delay(350);
    LeftDrive.move(0);
    RightDrive.move(0);
    //quals
    chassis.turnToPoint(25.3, 14.9, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(25.3, 14.9, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntil(5);
    activatelb(50);
    //Elims
    // chassis.turnToPoint(56.3, -31, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 3});
    // chassis.moveToPoint(56.3, -31, 2500, {.forwards = false, .maxSpeed = DRIVESPEED});
};


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
    chassis.setPose(0, 0, 0);
    toggleRightDoinker();
    chassis.moveToPoint(-0.5, 50, 1500);
    isIntaking = true;
    isSavingRing = true;
    chassis.waitUntilDone();
    pros::delay(150);
    chassis.swingToPoint(-17, 18.5, lemlib::DriveSide::LEFT, 700, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 70, .earlyExitRange = 2});
    chassis.moveToPoint(-17, 18.5, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 35, .earlyExitRange = 0.5});
    chassis.waitUntil(17);
    toggleMOGO();
    chassis.waitUntilDone();
    toggleRightDoinker();
    isSavingRing = false;
    isIntaking = true;
    pros::delay(50);
    isIntaking = true;
    chassis.moveToPoint(12.5, 42.1, 1500, {.maxSpeed = 70, .minSpeed = 20, .earlyExitRange = 3});
    chassis.turnToPoint(32.5, 14, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(32.5, 14, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 3});
    chassis.turnToPoint(40, 8, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 40, .earlyExitRange = 1});
    chassis.waitUntilDone();
    LeftDrive.move(65);
    RightDrive.move(65);
    pros::delay(900);
    LeftDrive.move(-25);
    RightDrive.move(-25);
    pros::delay(450);
    LeftDrive.move(0);
    RightDrive.move(0);
    pros::delay(250);
    chassis.swingToPoint(12.5, 6.5, lemlib::DriveSide::LEFT, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 1.5});
    chassis.moveToPoint(12.5, 6.5, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToPoint(-15.5, -3, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1});   //-17.5, -0.7
    chassis.waitUntilDone();
    toggleIntakeCount();
    chassis.moveToPoint(-17.5, -0.7, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20});
    chassis.waitUntilDone();
    pros::delay(500);
    toggleIntakeCount();
    pros::delay(20);
    LeftDrive.move(-45);
    RightDrive.move(-45);
    pros::delay(360);
    LeftDrive.move(0);
    RightDrive.move(0);
    pros::delay(500);
    //quals
    chassis.turnToPoint(-23.7, 12, 1500, {.maxSpeed = TURNSPEED});
    chassis.moveToPoint(-23.7, 12, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntil(5);
    activatelb(50);
    //Elims
    // chassis.turnToPoint(-58, -35, 1000, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 3});
    // chassis.moveToPoint(-58, -35, 2500, {.forwards = false, .maxSpeed = DRIVESPEED});
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
    pros::delay(400);
    isIntaking = false;
    chassis.moveToPoint(-47, 0, 1250, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToPoint(-46, 27.2, 800, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.moveToPoint(-46, 27.2, 1300, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntil(21.5);
    toggleMOGO();
    chassis.turnToPoint(-20.5, 25.4, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.moveToPoint(-20.5, 25.4, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    isIntaking = true;
    chassis.turnToPoint(0, 40, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.moveToPoint(0, 40, 2000, {.maxSpeed = DRIVESPEED, .minSpeed = 30, .earlyExitRange = 8});
    chassis.moveToPoint(31.5, 48, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 30});
    chassis.waitUntil(20);
    set_lb_pos(LB_STAGED_POSITION, 900);
    pros::delay(500);
    chassis.moveToPoint(5, 38, 1500, {.forwards = false, .maxSpeed = 90});
    chassis.turnToPoint(4, 65, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 25, .earlyExitRange = 1.5});
    isIntaking = false;
    pros::delay(40);
    intake1.move_relative(30, 200);
    pros::delay(40);
    set_lb_pos(LB_BACKPACK_POSITION, 500);
    chassis.moveToPoint(4, 65, 1200, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
    pros::delay(250);
    isIntaking = true;
    chassis.waitUntilDone();
    set_lb_pos(LB_WALLSTAKE_POSITION, 800);
    waitForLb = pros::millis();
    while (pros::millis() - waitForLb < 800) {
        if(exitLB) {  
            break;
        }
        pros::delay(5);
    }
    chassis.moveToPoint(-4, 43, 1500, {.forwards = false, .maxSpeed = DRIVESPEED});
    chassis.turnToPoint(-22, 47, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.moveToPoint(-22, 47, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 30, .earlyExitRange = 2});
    chassis.moveToPoint(-60, 48, 1500, {.maxSpeed = 70, .minSpeed = 20, .earlyExitRange = 1});
    chassis.swingToPoint(-48.5, 60.3, lemlib::DriveSide::LEFT, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.moveToPoint(-48.5, 60.3, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToHeading(110, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.waitUntilDone();
    LeftDrive.move(60);
    RightDrive.move(60);
    pros::delay(200);
    LeftDrive.move(0);
    RightDrive.move(0);
    pros::delay(300);
    toggleMOGO();
    isIntaking = false;
    LeftDrive.move(-80);
    RightDrive.move(-80);
    pros::delay(400);
    chassis.moveToPoint(7, 51, 2000, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.moveToPoint(56, 48, 1500, {.maxSpeed = 100, .minSpeed = 30, .earlyExitRange = 0.5});
    set_lb_pos(LB_STAGED_POSITION, 1500);
    isIntaking = true;
    chassis.turnToPoint(68, 19.5, 1500, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.moveToPoint(68, 19.5, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 0.2});
    chassis.waitUntil(25.5);
    toggleMOGO();
    toggleRightDoinker();
    chassis.turnToPoint(70.5, 45, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 2});
    chassis.moveToPoint(70.5, 45, 1500, {.maxSpeed = 70, .minSpeed = 40, .earlyExitRange = 11.5});
    chassis.moveToPoint(56, 58, 1500, {.maxSpeed = 70, .minSpeed = 30, .earlyExitRange = 1.5});
    chassis.turnToPoint(66, 61.7, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 2});
    chassis.waitUntilDone();
    toggleMOGO();
    chassis.moveToPoint(66, 61.7, 600, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 2});
    toggleRightDoinker();
    chassis.moveToPoint(53, 40, 2000, {.maxSpeed = 70, .minSpeed = 15, .earlyExitRange = 1.5});
    chassis.turnToPoint(54, -6, 1500, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.moveToPoint(54, -6, 1500, {.forwards = false, .maxSpeed = 80, .minSpeed = 20, .earlyExitRange = 0.5});
    chassis.waitUntil(30.5);
    toggleMOGO();
    isIntaking = false;
    chassis.turnToPoint(66, -3.2, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 15, .earlyExitRange = 1.5});
    chassis.moveToPoint(66, -3.2, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 30, .earlyExitRange = 1.5});
    chassis.waitUntilDone();
    LeftDrive.move(60);
    RightDrive.move(60);
    intake1.move_relative(30, 200);
    pros::delay(600);
    LeftDrive.move(0);
    RightDrive.move(0);
    chassis.moveToPoint(calculate_relative_move_x(-8), calculate_relative_move_y(-8), 1500, {.forwards = false, .maxSpeed = 85});
    chassis.waitUntilDone();
    set_lb_pos(LB_ALLIANCESTAKE_POSITION, 900);
    waitForLb = pros::millis();
    while (pros::millis() - waitForLb < 910) {
        if(exitLB) {  
            break;
        }
        pros::delay(5);
    }
    chassis.moveToPoint(calculate_relative_move_x(-5), calculate_relative_move_y(-5), 600, {.forwards = false, .maxSpeed = 85, .minSpeed = 35, .earlyExitRange = 1.5});
    isIntaking = true;
    isColorSort = true;
    chassis.turnToPoint(30, 23.25, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    set_lb_pos(LB_ZEROED_POSITION, 1500);
    chassis.moveToPoint(30, 23.25, 1500, {.maxSpeed = DRIVESPEED});
    isColorSort = false;
    chassis.waitUntilDone();
    pros::delay(400);
    chassis.turnToPoint(6, -1, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 0.5});
    chassis.waitUntilDone();
    isIntaking = false;
    chassis.moveToPoint(6, -1, 1500, {.maxSpeed = DRIVESPEED});
    chassis.waitUntil(20);
    isIntaking = true;
    chassis.waitUntilDone();
    pros::delay(300);
    isIntaking = false;
    chassis.moveToPoint(-21, -27, 1500, {.maxSpeed = 80, .minSpeed = 40, .earlyExitRange = 0.5});
    chassis.waitUntilDone();
    isIntaking = true;
    chassis.moveToPoint(-44.25, -48.4, 2500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 0.5});
    chassis.turnToPoint(-56, -50.6, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.moveToPoint(-56, -50.6, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 0.3});
    chassis.turnToPoint(-48, -63.9, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.moveToPoint(-48, -63.9, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.turnToPoint(-60, -64.5, 1500, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 10, .earlyExitRange = 1.5});
    chassis.waitUntilDone();
    pros::delay(300);
    toggleMOGO();
    isIntaking = false;
    set_lb_pos(LB_STAGED_POSITION, 1200);
    chassis.moveToPoint(-56.6, -64.5, 900, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.moveToPoint(-35, -54, 2000, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    isIntaking = true;
    chassis.turnToHeading(0, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.waitUntilDone();
    toggleMOGO();
    isIntaking = false;
    chassis.waitUntilDone();
    LeftDrive.move(-60);
    RightDrive.move(-60);
    pros::delay(900);
    LeftDrive.move(0);
    RightDrive.move(0);

    pros::delay(50);
    chassis.setPose(chassis.getPose().x, -68, 0);
    pros::delay(20);
    chassis.moveToPoint(chassis.getPose().x, -53, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 10, .earlyExitRange = 1});
    toggleLeftDoinker();
    chassis.waitUntilDone();
    chassis.setPose(-70 + calculate_reset_distance(LEFT_DISTANCE_SENSOR_OFFSET, leftResetSensor.get_distance(), 0, chassis.getPose().theta), chassis.getPose().y, chassis.getPose().theta);
    pros::delay(20);
    toggleLeftDoinker();
    toggleMOGO();
    set_lb_pos(LB_STAGED_POSITION, 1200);
    chassis.swingToPoint(-18.5, -42.6, lemlib::DriveSide::LEFT, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 40, .earlyExitRange = 1.5});
    isIntaking = true;
    chassis.moveToPoint(-18.5, -42.6, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToPoint(-50, -23.7, 1500, {.forwards = false, .maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.moveToPoint(-50, -23.7, 1500, {.forwards = false, .maxSpeed = 70, .minSpeed = 20, .earlyExitRange = 0.5});
    chassis.waitUntil(25);
    toggleMOGO();
    chassis.moveToPoint(0, -40, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1});
    isIntaking = false;
    pros::delay(40);
    intake1.move_relative(25, 200);
    pros::delay(70);
    set_lb_pos(LB_BACKPACK_POSITION, 1500);
    chassis.turnToPoint(1, -70, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.moveToPoint(1, -70, 1100, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1});
    pros::delay(300);
    isIntaking = true;
    chassis.waitUntilDone();
    set_lb_pos(LB_WALLSTAKE_POSITION - 40, 800);
    waitForLb = pros::millis();
    while (pros::millis() - waitForLb < 800) {
        if(exitLB) {  
            break;
        }
        pros::delay(5);
    }
    LeftDrive.move(-80);
    RightDrive.move(-80);
    pros::delay(300);
    chassis.turnToPoint(25, -47, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 40, .earlyExitRange = 1.5});
    chassis.moveToPoint(25, -47, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
    set_lb_pos(LB_BACKPACK_POSITION, 1500);
    chassis.turnToPoint(27, -22, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.moveToPoint(27, -22, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.turnToPoint(46, -45, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 25, .earlyExitRange = 1.5});
    chassis.moveToPoint(46, -45, 1500, {.maxSpeed = 75, .minSpeed = 25, .earlyExitRange = 0.5});
    chassis.turnToPoint(63.5, -47, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.moveToPoint(63.5, -47, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 25, .earlyExitRange = 0.5});
    chassis.moveToPoint(29, -49.3, 1500, {.forwards = false, .maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToPoint(47, -58, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.waitUntilDone();
    toggleRightDoinker();
    chassis.moveToPoint(47, -58, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 20, .earlyExitRange = 1});
    chassis.swingToHeading(-35, lemlib::DriveSide::LEFT, 1500, {.maxSpeed = DRIVESPEED, .minSpeed = 50, .earlyExitRange = 4});
    chassis.waitUntilDone();
    toggleMOGO();
    LeftDrive.move(-70);
    RightDrive.move(-70);
    pros::delay(700);
    set_lb_pos(LB_WALLSTAKE_POSITION, 1500);
    chassis.moveToPoint(25, -26.5, 1500, {.maxSpeed = 90, .minSpeed = 20, .earlyExitRange = 1.5});
    chassis.turnToHeading(132, 1500, {.maxSpeed = TURNSPEED, .minSpeed = 20, .earlyExitRange = 0.5});
    chassis.waitUntilDone();
    LeftDrive.move(-60);
    RightDrive.move(-60);
    pros::delay(1300);
    LeftDrive.move(30);
    RightDrive.move(30);
    pros::delay(200);
    LeftDrive.move(-30);
    RightDrive.move(-30);
    pros::delay(200);
    LeftDrive.move(30);
    RightDrive.move(30);
    pros::delay(200);
    LeftDrive.move(-30);
    RightDrive.move(-30);
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