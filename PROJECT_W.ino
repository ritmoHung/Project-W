#include "PROJECT_W.h"

#include "src/config.h"
#include "src/pins.h"
#include "src/macros.h"

void setup() {
  Serial.begin(9600);
  initPins();
}

void loop() {
  larvaCulturing();
  delay(2 * BUFFER);

  pupaSorting();
  delay(2 * BUFFER);

  machineWashing();
  delay(2 * BUFFER);
  
  // dataTest();
}