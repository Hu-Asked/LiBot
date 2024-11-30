#include "declare.hpp"

const double gearRatio = 36.0/48.0;
const double trackWidth = 11.942;

const float DRIVESPEED = 115.0f;
const int TURNSPEED = 115.0f;

// PIDController pidH(0.023, 0.011, 0.144);
// PIDController pidD(0.21, 0, 0.03);

//          PID
lemlib::ControllerSettings lateralController( 9.5, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              7, // derivative gain (kD) 
                                              0, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              127 // maximum acceleration (slew)
);

lemlib::ControllerSettings angularController( 3, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              16, // derivative gain (kD)
                                              0, // anti windup
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

pros::MotorGroup LeftDrive({-1, -2, -3}, pros::MotorGearset::blue, pros::MotorUnits::degrees);
pros::MotorGroup RightDrive({4, 5, 6}, pros::MotorGearset::blue, pros::MotorUnits::degrees);

lemlib::Drivetrain driveTrain(&LeftDrive, &RightDrive, trackWidth, lemlib::Omniwheel::NEW_325, 450, 8);

pros::IMU imu(7);

//          ODOMETRY
pros::Rotation horizontal_encoder(-16);
pros::Rotation vertical_encoder(-15);

lemlib::TrackingWheel horizontalTrackingWheel(&horizontal_encoder, lemlib::Omniwheel::NEW_2, -1.64);
lemlib::TrackingWheel verticalTrackingWheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, -0.769);

lemlib::OdomSensors sensors(&verticalTrackingWheel, //vertical tracking wheel
                            nullptr,
                            &horizontalTrackingWheel, //horizontal tracking wheel
                            nullptr,
                            &imu
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

pros::ADIDigitalOut clampPiston('A');
pros::ADIDigitalOut doinkerPiston('B');
pros::ADIDigitalOut intakeSizePiston('C');


pros::Motor intake1(-14, pros::MotorGearset::blue, pros::MotorUnits::degrees);

pros::Optical colorSensor(13);

//LadyBrown
PIDController pidlb(0.00036, 0.00001, 0.00017);
pros::Motor lb1(-11, pros::MotorGearset::blue, pros::MotorUnits::degrees);
pros::Motor lb2(12, pros::MotorGearset::blue, pros::MotorUnits::degrees);
pros::Rotation lb_encoder(-17);

//Climb
pros::ADIDigitalOut climbPTO('H'); 
pros::ADIDigitalOut climbPiston('G'); 
pros::ADIDigitalIn bumperSwitch('F');


