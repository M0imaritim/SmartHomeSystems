#include "smart_home.h"
// gas_sensor.ino

int gasLevelThreshold = 1000;  // Arbitrary threshold for gas detection
bool gasDetected = false;

void readGasSensor() {
  int gasLevel = analogRead(MQ2PIN);
  
  if (gasLevel > gasLevelThreshold) {
    gasDetected = true;
    alarmActive = true;
    logEvent("Gas detected.");
  } else {
    gasDetected = false;
  }
}
