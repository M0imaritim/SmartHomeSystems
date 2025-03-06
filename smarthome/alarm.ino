// alarm.ino
#include "smart_home.h"

void updateLED() {
  if (alarmActive){
      if (tempDetected && gasDetected) {
        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);  // 100 ms on and off if both gas and over temperature are detected
      } 
      else if (tempDetected) {
        digitalWrite(LED_PIN, HIGH);
        delay(500);
        digitalWrite(LED_PIN, LOW);
        delay(500);  // 500 ms for temperature detection
      }
      else if (gasDetected) {
        digitalWrite(LED_PIN, HIGH);
        delay(1000);
        digitalWrite(LED_PIN, LOW);
        delay(1000);
      }   
  else {
        digitalWrite(LED_PIN, LOW);
      } 
      } }

void updateBuzzer() {
  if (alarmActive) {
    if (gasDetected || tempDetected) {
    tone(BUZZER_PIN, 1000);
    }
    else {
    noTone(BUZZER_PIN);
  }
  } }

void stopAlarm() {
  digitalWrite(BUZZER_PIN, LOW);  
  digitalWrite(LED_PIN, LOW);     
}
