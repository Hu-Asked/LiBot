#include "declare.hpp"

const double gearRatio = 36.0/48.0;
const double trackWidth = 11.4173;

const float DRIVESPEED = 120.0f;
const int TURNSPEED = 120.0f;

// PIDController pidH(0.023, 0.011, 0.144);
// PIDController pidD(0.21, 0, 0.03);

pros::Controller master(pros::E_CONTROLLER_MASTER);

//          PID
lemlib::ControllerSettings lateralController( 7, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3.4, // derivative gain (kD) 
                                              0, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              127 // maximum acceleration (slew)
);

lemlib::ControllerSettings angularController( 2.23, // proportional gain (kP) 
                                              0.38, // integral gain (kI)
                                              12.5, // derivative gain (kD)
                                              5, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              127 // maximum acceleration (slew)
);

//          DRIVETRAIN  

// pros::Motor m1(1, pros::MotorGearset::blue, pros::MotorUnits::degrees);
// pros::Motor m2(2, pros::MotorGearset::blue, pros::MotorUnits::degrees);
// pros::Motor m3(8, pros::MotorGearset::blue, pros::MotorUnits::degrees);

// pros::Motor m4(4, pros::MotorGearset::blue, pros::MotorUnits::degrees);
// pros::Motor m5(10, pros::MotorGearset::blue, pros::MotorUnits::degrees);
// pros::Motor m6(6, pros::MotorGearset::blue, pros::MotorUnits::degrees);

pros::MotorGroup LeftDrive({-18, -19, 20}, pros::MotorGearset::blue, pros::MotorUnits::degrees);
pros::MotorGroup RightDrive({15, 16, -17}, pros::MotorGearset::blue, pros::MotorUnits::degrees);

lemlib::Drivetrain driveTrain(&LeftDrive, &RightDrive, trackWidth, lemlib::Omniwheel::NEW_275, 450, 2);

pros::IMU imu(14);

//          ODOMETRY
pros::Rotation horizontal_encoder(12);
pros::Rotation vertical_encoder(13);

lemlib::TrackingWheel horizontalTrackingWheel(&horizontal_encoder, lemlib::Omniwheel::NEW_2, 0.07874);
lemlib::TrackingWheel verticalTrackingWheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, 0.905512);

lemlib::OdomSensors sensors(&verticalTrackingWheel, //vertical tracking wheel
                            nullptr,
                            &horizontalTrackingWheel, //horizontal tracking wheel
                            nullptr,
                            &imu,
                            360/356.761905
);

//          JOYSTICK CURVING

lemlib::ExpoDriveCurve throttle_curve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steer_curve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

lemlib::Chassis chassis(driveTrain, 
                        lateralController, 
                        angularController, 
                        sensors, 
                        &throttle_curve, 
                        &steer_curve
);

//          OTHER

pros::Distance leftResetSensor(7);

pros::ADIDigitalOut clampPiston('A');
pros::ADIDigitalOut leftDoinkerPiston('H');
pros::ADIDigitalOut rightDoinkerPiston('G');
pros::ADIDigitalOut climbReleasePiston('B');
// pros::ADIDigitalOut intakeSizePiston('F');


pros::Motor intake1(-10, pros::MotorGearset::blue, pros::MotorUnits::degrees);

pros::Optical colorSensor(6);
pros::Distance distanceSensor(8);

//LadyBrown
lemlib::PID pidlb(0.007, 0, 0, 0.0003, true);
pros::Motor lb1(9, pros::MotorGearset::green, pros::MotorUnits::degrees);
pros::Motor lb2(-4, pros::MotorGearset::green, pros::MotorUnits::degrees);
// pros::Rotation lb_encoder(-6);

//Climb
pros::ADIDigitalOut climbPTO('F'); 
// pros::ADIDigitalOut climbPiston('G');
// pros::ADIDigitalOut wingPiston('H');


