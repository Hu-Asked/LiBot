#include "main.h"
#include <cmath>
#include <queue>

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

// extern bool isStaging;
// extern bool isReturning;
// extern bool isZeroing;
extern bool isScoring;
extern bool isMovingLB;
extern bool isIntaking;
extern bool isReverseIntake;

extern bool isClimbingInitiated;
extern bool isClimbing;

extern bool isRedAlliance;
extern bool isColorSort;

extern double lbTarget;
extern double lbLimit;
extern bool exitLB;

void set_lb_pos(double target, double limit);
void STAGE_LADY_BROWN(void* param);
void INTAKE(void* param);
void CLIMB(void* param);

void activateIntake(int speed);
void toggleMOGO();
void toggleDoinker();
void toggleIntakeCount();
void toggleClimb();
void activatelb(int speed);
void movelb(double target, double power, double limit);
double calculate_reset_distance(double offset_in, double distance_mm, double intended_heading, double true_heading);

#endif  // FUNCTIONS_HPP