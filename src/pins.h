/**
 * Arduino Mega with RAMPS v1.4 (or v1.3) pin assignments
 *
 * Applies to the following boards:
 *
 *  RAMPS_14_EFB (Hotend, Fan, Bed)
 *  RAMPS_14_EEB (Hotend0, Hotend1, Bed)
 *  RAMPS_14_EFF (Hotend, Fan0, Fan1)
 *  RAMPS_14_EEF (Hotend0, Hotend1, Fan)
 *  RAMPS_14_SF  (Spindle, Controller Fan)
 *
 *  RAMPS_13_EFB (Hotend, Fan, Bed)
 *  RAMPS_13_EEB (Hotend0, Hotend1, Bed)
 *  RAMPS_13_EFF (Hotend, Fan0, Fan1)
 *  RAMPS_13_EEF (Hotend0, Hotend1, Fan)
 *  RAMPS_13_SF  (Spindle, Controller Fan)
 *
 *  Other pins_MYBOARD.h files may override these defaults
 *
 *  Differences between
 *  RAMPS_13 | RAMPS_14
 *         7 | 11
 */

#pragma once

// Custom flags and defines for the build

#define BOARD_INFO_NAME "RAMPS 1.6"



// Class Defaults
#define DEFAULT_IN              DP0
#define DEFAULT_OUT             DP1


// Servos
#define SERVO0_PIN              DP11
#define SERVO1_PIN              DP6
#define SERVO2_PIN              DP5
#define SERVO3_PIN              DP4


// Normal & Limit Switches
#define STOP_SWITCH             DP16
#define X_MIN_PIN               DP3
#define X_MAX_PIN               DP2
#define Y_MIN_PIN               DP14
#define Y_MAX_PIN               DP15
#define Z_MIN_PIN               DP18
#define Z_MAX_PIN               DP19


// Z Probe (When not Z_MIN_PIN)
#define Z_MIN_PROBE_PIN         DP32


// Steppers
typedef enum {
    DEFAULT_AXIS                = 0,     // For initializing usage only
    X                           = 1,     // X
    Y                           = 2,     // Y
    Z                           = 3,     // Z
    E0                          = 4,     // HOOK
    E1                          = 5,     // FEED
} AXES;

#define X_STEP_PIN              DP54
#define X_DIR_PIN               DP55
#define X_ENABLE_PIN            DP38
#define X_ES                    1

#define Y_STEP_PIN              DP60
#define Y_DIR_PIN               DP61
#define Y_ENABLE_PIN            DP56
#define Y_ES                    0

#define Z_STEP_PIN              DP46
#define Z_DIR_PIN               DP48
#define Z_ENABLE_PIN            DP62
#define Z_ES                    1

#define E0_STEP_PIN             DP26
#define E0_DIR_PIN              DP28
#define E0_ENABLE_PIN           DP24

#define E1_STEP_PIN             DP36
#define E1_DIR_PIN              DP34
#define E1_ENABLE_PIN           DP30

// DRV8825 Microstep Setup
// MS1  MS2  MS3  Resolution
//  0    0    0      1/1
//  1    0    0      1/2
//  0    1    0      1/4
//  1    1    0      1/8
//  0    0    1      1/16
//  1    0    1      1/32
//  0    1    1      1/32
//  1    1    1      1/32


// Heaters / Fans
#define RAMPS_D8_PIN            DP8
#define RAMPS_D9_PIN            DP9
#define RAMPS_D10_PIN           DP10

#define FAN_PIN                 RAMPS_D9_PIN


// Relays
#define V1                      DP47 // 2 way CULT bleach switch
#define V2                      DP45 // 3 way SHOWER fluid valve
#define V3                      DP43 // 3 way CULT fluid valve
#define V4                      DP41 // 2 way SHOWER bleach switch
#define V5                      DP39 // 2 way fluid container valve
#define V6                      DP37 // 2 way pupae container valve





// Misc. Functions
#define LED_PIN                 DP13
#define FILWIDTH_PIN            DP5 //Analog Input on AUX2
#define FIL_RUNOUT_PIN          DP4
#define PS_ON_PIN               DP12
#define CASE_LIGHT_PIN          DP44


// Software Serial
#define X_SERIAL_TX_PIN         DP40
#define X_SERIAL_RX_PIN         DP63
#define X2_SERIAL_TX_PIN        -1
#define X2_SERIAL_RX_PIN        -1

#define Y_SERIAL_TX_PIN         DP59
#define Y_SERIAL_RX_PIN         DP64
#define Y2_SERIAL_TX_PIN        -1
#define Y2_SERIAL_RX_PIN        -1

#define Z_SERIAL_TX_PIN         DP42
#define Z_SERIAL_RX_PIN         DP65
#define Z2_SERIAL_TX_PIN        -1
#define Z2_SERIAL_RX_PIN        -1

#define E0_SERIAL_TX_PIN        DP44
#define E0_SERIAL_RX_PIN        DP66
#define E1_SERIAL_TX_PIN        -1
#define E1_SERIAL_RX_PIN        -1


// LCDs and Controllers //
// SDA connects to A4, SCL connects to A5 on UNO
// SDA connects to 20, SCL connects to 21 on MEGA2560