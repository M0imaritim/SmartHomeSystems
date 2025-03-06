#include "smart_home.h"
// temp_sensor.ino

bool tempDetected = false;

void readTemperatureSensor() {
  float temperature = dht.readTemperature();
  
  if (temperature > 300.0) {  // Threshold for over temperature
    tempDetected = true;
    alarmActive = true;
    logEvent("Over temperature detected.");
  } else {
    tempDetected = false;
  }
}
