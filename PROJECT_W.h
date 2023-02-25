#pragma once

#include <DIO2.h>
#include "src/config.h"
#include "src/pins.h"
#include "src/macros.h"
#include "src/stepper.h"
#include "src/endstops.h"

#if HAS_WIRED_LCD
  #include "src/lcd.h"
#endif

Stepper sX(X);
Stepper sZ(Z);
Stepper sHook(E0);
Stepper sFeed(E1);
LCD LCD(255);
#define dl 15000
unsigned long currentTime = 0;

const int layerData[8][4] = {
  {C1_HEIGHT, CULT_ORIGIN, CULT_OPEN_POS, C1_POS},
  {C2_HEIGHT, CULT_ORIGIN, CULT_OPEN_POS, C2_POS},
  {SHOWER_HEIGHT, FILTER_ORIGIN, SHOWER_OPEN_POS, SHOWER_POS},
  {SPREADER_HEIGHT, FILTER_ORIGIN, FILTER_OPEN_POS, WOOD_POS},
  {F1_HEIGHT, FILTER_ORIGIN, FILTER_OPEN_POS, F1_POS},
  {FP_HEIGHT, FILTER_ORIGIN, FILTER_OPEN_POS, FP_POS},
  {F2_HEIGHT, FILTER_ORIGIN, FILTER_OPEN_POS, PLASTIC_POS},
  {F3_HEIGHT, FILTER_ORIGIN, FILTER_OPEN_POS, PLASTIC_POS},
};

void initPins() {
  // LCD
  LCD.init();
  LCD.write(0, 0, CLR, "INITIALIZING");
  LCD.write(1, 0, RMN, ">");

  // Class Defaults
  IN(DEFAULT_IN);
  OUT(DEFAULT_OUT);

  // Endstops & Switches
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "ENDSTOPS");
  IN(STOP_SWITCH);
  
  IN(X_MIN_PIN);
  IN(X_MAX_PIN);

  IN(Y_MIN_PIN);
  IN(Y_MAX_PIN);

  IN(Z_MIN_PIN);
  IN(Z_MAX_PIN);

  // Fans
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "DISSIPATION FAN");
  OUT(FAN_PIN);
  OPEN(FAN_PIN);

  // Stepper Motors
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "MOTOR PINS");
  OUT(X_STEP_PIN);
  OUT(X_DIR_PIN);
  OUT(X_ENABLE_PIN);

  OUT(Y_STEP_PIN);
  OUT(Y_DIR_PIN);
  OUT(Y_ENABLE_PIN);

  OUT(Z_STEP_PIN);
  OUT(Z_DIR_PIN);
  OUT(Z_ENABLE_PIN);

  OUT(E0_STEP_PIN);
  OUT(E0_DIR_PIN);
  OUT(E0_ENABLE_PIN);

  OUT(E1_STEP_PIN);
  OUT(E1_DIR_PIN);
  OUT(E1_ENABLE_PIN);

  DIS(X_ENABLE_PIN);
  DIS(Y_ENABLE_PIN);
  DIS(Z_ENABLE_PIN);
  DIS(E0_ENABLE_PIN);
  DIS(E1_ENABLE_PIN);

  // Relays
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "VALVE RELAYS");
  OUT(V1);
  OUT(V2);
  OUT(V3);
  OUT(V4);
  OUT(V5);
  OUT(V6);

  // Motors
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "X MOTOR");
  sX.init();
  LCD.write(1, 2, RMN, "Z MOTOR");
  sZ.init();
  LCD.write(1, 2, RMN, "E0 MOTOR");
  sHook.init();
  LCD.write(1, 2, RMN, "E1 MOTOR");
  sFeed.init();
}

void resetPosition(bool x, bool z, bool hook, bool feed) {
  if(feed) sFeed.setPosition(0);
  if(hook) sHook.setPosition(H_DOWN);
  if(x) sX.origin();
  if(z) sZ.origin();
}

void dataTest() {
  // Height Test
  // Runs through first layer to last
  //sX.setPosition(130);
  LCD.clear();
  for(int layer = SHOWER; layer <= F2; layer++) {
    LCD.write(0, 0, RMN, "LAYER ");
    LCD.write(1, 0, RMN, String(layer + 1));
    sZ.setPosition(layerData[layer][HEIGHT]);
    if(layer == SHOWER) sX.setPosition(170);
    delay(dl);
  }
  resetPosition(1, 0, 1, 1);
  
  // X Axis Test
  LCD.write(0, 0, CLR, "X Axis Test");
  sZ.setPosition(98);

  LCD.write(0, 0, CLR, "CULTURING");
  LCD.write(1, 0, RMN, "ORIGIN");
  sX.setPosition(CULT_ORIGIN);
  delay(dl);

  LCD.write(0, 0, CLR, "CULTURING");
  LCD.write(1, 0, RMN, "OPEN POS");
  sX.setPosition(CULT_OPEN_POS);
  delay(dl);

  LCD.write(0, 0, CLR, "CULT 1");
  LCD.write(1, 0, RMN, "POS");
  sX.setPosition(C1_POS);
  delay(dl);

  LCD.write(0, 0, CLR, "CULT 2");
  LCD.write(1, 0, RMN, "POS");
  sX.setPosition(C2_POS);
  delay(dl);

  LCD.write(0, 0, CLR, "FILTERS");
  LCD.write(1, 0, RMN, "ORIGIN");
  sX.setPosition(FILTER_ORIGIN);
  delay(dl);

  LCD.write(0, 0, CLR, "FILTERS");
  LCD.write(1, 0, RMN, "OPEN POS");
  sX.setPosition(FILTER_OPEN_POS);
  delay(dl);

  LCD.write(0, 0, CLR, "F1");
  LCD.write(1, 0, RMN, "POS");
  sX.setPosition(F1_POS);
  delay(dl);

  LCD.write(0, 0, CLR, "FP");
  LCD.write(1, 0, RMN, "POS");
  sX.setPosition(FP_POS);
  delay(dl);

  LCD.write(0, 0, CLR, "SHOWER");
  LCD.write(1, 0, RMN, "POS");
  sX.setPosition(SHOWER_POS);
  delay(dl);

  LCD.write(0, 0, CLR, "HOOK ON WOOD");
  LCD.write(1, 0, RMN, "POS");
  sX.setPosition(WOOD_POS);
  delay(dl);

  LCD.write(0, 0, CLR, "HOOK ON PLASTIC");
  LCD.write(1, 0, RMN, "POS");
  sX.setPosition(PLASTIC_POS);
  delay(dl);

  // Reset
  LCD.write(0, 0, CLR, "DONE!");
  LCD.write(1, 0, RMN, "RESET POSITION");
  resetPosition(1, 1, 1, 1);
  delay(dl);
  
}

void openLayer(int layer, int shoot, bool rotate) {
  if(shoot == 1 || shoot == -1 || layer >= 0 || layer < 8) {
    // X-axis hook stays inside tray's hook
    if(shoot == 1) sHook.setPosition(H_UP);
    else sHook.setPosition(H_DOWN);
    sZ.setPosition(layerData[layer][HEIGHT] + shoot * Z_OFFSET);
    sX.setPosition(layerData[layer][CLOSE_POS]);
    
    sZ.setPosition(layerData[layer][HEIGHT]);
    sX.setPosition(layerData[layer][OPEN_POS]);

    // Optional - Rotates filter
    if(rotate) {
      if(shoot == 1) sHook.setPosition(H_UP + FILTER_ANGLE);
      else sHook.setPosition(H_DOWN + FILTER_ANGLE);
    }
  }
  else return;
}

void closeLayer(int layer, int shoot, bool rotate) {
  if(shoot == 1 || shoot == -1 || layer >= 0 || layer < 8) {
    // Optional - Rotates filter
    if(rotate) {
      if(shoot == 1) {
        sHook.setPosition(H_UP - FIX_ANGLE);
        delay(FILTER_ROTATE_BUFFER);
        sHook.setPosition(H_UP);
      }
      else {
        sHook.setPosition(H_DOWN - FIX_ANGLE);
        delay(FILTER_ROTATE_BUFFER);
        sHook.setPosition(H_DOWN);
      }
    }
    
    // X-axis hook stays inside tray's hook
    sX.setPosition(layerData[layer][CLOSE_POS]);
    sZ.setPosition(layerData[layer][HEIGHT] + shoot * Z_OFFSET);
    sX.setPosition(layerData[layer][ORIGIN]);
  }  
  else return;
}

void larvaCulturing() {
  LCD.write(0, 0, CLR, "LARVA CULTURING");
  LCD.write(1, 0, RMN, ">");

  // C1 tray filling, needs overshoot b/c small height difference
  LCD.write(1, 2, RMN, "FILLING C1");
  openLayer(C1, OVERSHOOT, 0);
  sFeed.setPosition(C1_ANGLE);
  
  OPEN(V5);
  OPEN(V6);
  delay(FILL_IN);
  CLOSE(V5);
  CLOSE(V6);
  delay(VALVE);

  sFeed.setPosition(0);
  closeLayer(C1, OVERSHOOT, 0);

  // C2 tray filling, undershoot
  LCD.write(1, 2, RMN, "FILLING C2");
  openLayer(C2, UNDERSHOOT, 0);
  sFeed.setPosition(C2_ANGLE);

  OPEN(V5);
  OPEN(V6);
  delay(FILL_IN);
  CLOSE(V5);
  CLOSE(V6);
  delay(VALVE);

  sFeed.setPosition(0);
  closeLayer(C2, UNDERSHOOT, 0);

  // Reset
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "DONE! RESET");
  resetPosition(1, 1, 1, 1);
}

void pupaSorting() {
  LCD.write(0, 0, CLR, "PUPA SORTING");
  LCD.write(1, 0, RMN, ">");

  // Manually release CULT contents & filtering
  LCD.write(1, 2, RMN, "RELEASE MN VLV");
  WATER(V3);
  delay(FILL_IN);
  BLEACH(V3);
  delay(VALVE);

  // Main filter process
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "REMOVE LARVA");
  WATER(V2);
  delay(FILTERING);
  // Opens FP to continue sorting
  openLayer(FP, UNDERSHOOT, 0);
  // Rotating F1 layer filter only
  // openLayer(F1, OVERSHOOT, 0, 1)
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "MAIN SORTING");
  sZ.setPosition(F1_HEIGHT - Z_OFFSET);
  sX.setPosition(layerData[F1][CLOSE_POS]);
  sZ.setPosition(F1_HEIGHT);
  // Apply an offset so that the filter rotates correctly
  sX.setPosition(layerData[F1][CLOSE_POS] - FILTER_OFFSET);
  sHook.setPosition(H_DOWN + FILTER_ANGLE);
  delay(FILTERING);

  BLEACH(V2);
  delay(VALVE);

  // Rotates back & close FP
  closeLayer(F1, UNDERSHOOT, 1);
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "CLOSING FP");
  // FP suffers structure deformation. Hook needs more degrees CCW to close FP.
  sHook.setPosition(H_DOWN + 15);
  sX.setPosition(layerData[FP][OPEN_POS]);
  sZ.setPosition(FP_HEIGHT);
  closeLayer(FP, UNDERSHOOT, 0);
  sHook.setPosition(H_DOWN + 15);

  // Reset
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "DONE! RESET");
  resetPosition(1, 1, 1, 1);
}

void machineWashing() {
  LCD.write(0, 0, CLR, "MACHINE WASHING");
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "DISPOSE");

  // Dispose female pupae from F1, F2 and (F3)
  openLayer(SHOWER, OVERSHOOT, 0);
  sZ.setPosition(SHOWER_HEIGHT + Z_OFFSET);
  for(int layer = F1; layer <= F2; layer++) {
    if(layer == FP) continue;
    else {
      if(layer == F1) LCD.write(1, 10, RMN, "F1");
      if(layer == F2) LCD.write(1, 10, RMN, "F2");      
      openLayer(layer, UNDERSHOOT, 1);

      WATER(V2);
      delay(CLEANING / 2);
      BLEACH(V2);
      delay(VALVE);

      closeLayer(layer, UNDERSHOOT, 1);
    }
  }
  // Manually remove femle pupae being collected to the bottom tray

  // Manually open hand valves of C1 & C2
  // Cleaning C1, C2 and buffer with bleach
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "C/BFR w BLEACH");
  BLEACH(V3);
  BLEACH(V2);
  delay(VALVE / 2);
  OPEN(V1);
  OPEN(V4);
  delay(CLEANING);
  CLOSE(V1);
  CLOSE(V4);
  delay(VALVE);

  // Cleaning all but FP and buffer with bleach and water
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "C/FLTR w WATER");
  openLayer(FP, UNDERSHOOT, 0);
  sZ.setPosition(SHOWER_HEIGHT + Z_OFFSET);
  sHook.setPosition(H_UP);
  sX.setPosition(SHOWER_OPEN_POS);
  sZ.setPosition(SHOWER_HEIGHT);
  closeLayer(SHOWER, OVERSHOOT, 0);

  OPEN(V4);  // Bleach
  delay(CLEANING);  // Filters only
  CLOSE(V4);  // Always close bleach switch to avoid future issues
  WATER(V3);
  WATER(V2);  // Water immediately flow through
  delay(CLEANING);  // Filters and CULTs
  BLEACH(V3);
  BLEACH(V2);  // Closes all fluid

  // Cleaning buffer with water
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "BFR w WATER");
  sHook.setPosition(H_DOWN);
  sX.setPosition(layerData[FP][OPEN_POS]);
  // FP suffers structure deformation. Hook needs more degrees CCW to close FP.
  sHook.setPosition(H_DOWN + 15);
  sZ.setPosition(FP_HEIGHT);
  closeLayer(FP, UNDERSHOOT, 0);
  sHook.setPosition(H_DOWN - 15);
  openLayer(SHOWER, OVERSHOOT, 0);

  WATER(V2);
  delay(CLEANING / 2);
  BLEACH(V2);
  closeLayer(SHOWER, OVERSHOOT, 0);

  // Reset
  LCD.clearLine(1);
  LCD.write(1, 0, RMN, ">");
  LCD.write(1, 2, RMN, "DONE! RESET");
  resetPosition(1, 1, 1, 1);
}