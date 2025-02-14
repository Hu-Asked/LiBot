#pragma once

#define PROS_USE_SIMPLE_NAMES

#include "main.h"

extern const double wheelDiameter;
extern const double gearRatio;
extern const double trackWidth;
extern const float DRIVESPEED;
extern const int TURNSPEED;

// extern PIDController pidH;
// extern PIDController pidD;

extern pros::Controller master;

extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;

extern pros::Motor m1;
extern pros::Motor m2;
extern pros::Motor m3;

extern pros::Motor m4;
extern pros::Motor m5;
extern pros::Motor m6;

extern pros::MotorGroup LeftDrive;
extern pros::MotorGroup RightDrive;

extern lemlib::Chassis chassis;

extern pros::IMU imu;

extern pros::Distance leftResetSensor;

extern pros::ADIDigitalOut clampPiston;
extern pros::ADIDigitalOut leftDoinkerPiston;
extern pros::ADIDigitalOut rightDoinkerPiston;
extern pros::ADIDigitalOut climbReleasePiston;
// extern pros::ADIDigitalOut intakeSizePiston;

extern pros::Motor intake1;

extern pros::Optical colorSensor;

extern lemlib::PID pidlb;
extern pros::Motor lb1;
extern pros::Motor lb2;
extern pros::Rotation lb_encoder;


extern pros::ADIDigitalOut climbPTO; 
// extern pros::ADIDigitalOut climbPiston; 
// extern pros::ADIDigitalOut wingPiston;
extern pros::Distance distanceSensor;


