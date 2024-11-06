#pragma once
#include "main.h"

#ifndef AUTONS_HPP
#define AUTONS_HPP

extern const int DRIVE_SPEED;
extern const int TURN_SPEED;
extern const int SWING_SPEED;

void RedRings();
void RedMOGO();
void RedMOGO2();
void BlueRings();
void BlueMOGO();
void BlueMOGO2();
void AutonomousSkills();

void drive_example();
void turn_example();
void curve_example();
void interfered_example();

void default_constants();

#endif  // AUTONS_HPP