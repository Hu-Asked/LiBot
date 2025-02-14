#pragma once
#include "main.h"

#ifndef AUTONS_HPP
#define AUTONS_HPP

extern const int DRIVE_SPEED;
extern const int TURN_SPEED;
extern const int SWING_SPEED;

void RedRings();
void RedMOGO();
void RedSAWP();
void BlueRings();
void BlueMOGO();
void BlueSAWP();
void AutonomousSkills();

void drive_example();
void turn_example();
void driveOffLine();

#endif