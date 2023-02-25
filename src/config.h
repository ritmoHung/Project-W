#pragma once

#include "macros.h"
#include "pins.h"

	

// A need-fix format
///////////////////////////////////////////////////////////////
//                         NEEDS FIX                         //
///////////////////////////////////////////////////////////////

// Steppers
#define INIT_OFFSET          10    // mm
#define PERIOD               200   // ms
#define PI                   3.1415926535897932384626433832795

#define X_STEP_MODE          16
#define X_FULL_STEPS         200
#define X_GEAR_RADIUS        0.8 * 13
#define X_GEAR_RATIO         1
#define X_RATIO              (X_STEP_MODE * X_FULL_STEPS) / (PI * X_GEAR_RADIUS * X_GEAR_RATIO)

#define Y_STEP_MODE          32
#define Y_FULL_STEPS         200
#define Y_GEAR_RADIUS        1
#define Y_GEAR_RATIO         360   // Uses degrees
#define Y_RATIO              (Y_STEP_MODE * Y_FULL_STEPS) / (Y_GEAR_RATIO)

#define Z_STEP_MODE          8
#define Z_FULL_STEPS         200
#define Z_GEAR_RADIUS        1
#define Z_GEAR_RATIO         5
#define Z_RATIO              (Z_STEP_MODE * Z_FULL_STEPS) / (Z_GEAR_RATIO)

#define E0_STEP_MODE         32
#define E0_FULL_STEPS        200
#define E0_GEAR_RADIUS       1
#define E0_GEAR_RATIO        360   // Hook uses degrees
#define E0_RATIO             (E0_STEP_MODE * E0_FULL_STEPS) / (E0_GEAR_RATIO)

#define E1_STEP_MODE         32
#define E1_FULL_STEPS        200
#define E1_GEAR_RADIUS       1     // Feed uses degrees
#define E1_GEAR_RATIO        360
#define E1_RATIO             (E1_STEP_MODE * E1_FULL_STEPS) / (E1_GEAR_RATIO)

#define ENABLE               0
#define DISABLE              !ENABLE
#define POSITIVE             1
#define NEGATIVE             !POSITIVE
#define OVERSHOOT            1
#define UNDERSHOOT           -1
#define CLR                  1
#define RMN                  0
#define CCW                  POSITIVE
#define CW                   NEGATIVE

// Devices, Layer Heights & Angles
// 0 - ORIGIN - OPEN_POS - POS (mm)
#define C1                   0
#define C2                   1
#define SHOWER               2
#define SPREADER             3
#define F1                   4
#define FP                   5
#define F2                   6
#define F3                   7
#define HEIGHT               0
#define ORIGIN               1
#define OPEN_POS             2
#define CLOSE_POS            3

#define THICKNESS            3
#define FILTER_OFFSET        5
#define Z_OFFSET             20
#define CULT_ORIGIN          120
#define FILTER_ORIGIN        14

#define CULT_OPEN_POS        90
#define SHOWER_OPEN_POS      67
#define FILTER_OPEN_POS      14

#define C1_POS               175
#define C2_POS               175
#define SHOWER_POS           209
#define F1_POS               196
#define FP_POS               209
#define WOOD_POS             212
#define PLASTIC_POS          194

#define C1_ANGLE             -22.5
#define C2_ANGLE             -45

#define C1_HEIGHT            0
#define C2_HEIGHT            32   
#define SHOWER_HEIGHT        135    // SHOWER
#define SPREADER_HEIGHT      188    // WOOD
#define F1_HEIGHT            253    // PLASTIC
#define FP_HEIGHT            314    // WOOD
#define F2_HEIGHT            364    // PLASTIC
#define F3_HEIGHT            365    // PLASTIC

#define H_DOWN               0
#define H_UP                 185    // 180 * (180 / 175)
#define FIX_ANGLE            20
#define FILTER_ANGLE         245

// Delay Time
#define BUFFER               1500
#define VALVE                10000
#define FILL_IN              15000
#define FILTERING            3000   //30000
#define SEVEN_DAYS           (1000 * 60 * 60 * 24 * 7)
#define CLEANING             10000  //60000
#define FILTER_ROTATE_BUFFER 1500

// LCDs and Controllers (Switches/...)
#define HAS_CONTROL_SWITCH   1
#define HAS_WIRED_LCD        1