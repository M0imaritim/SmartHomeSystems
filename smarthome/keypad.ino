// keypad.ino

#include "smart_home.h"

// Arrays and Keypad definitions
byte rowPins[ROWS] = {11, 9, 10, 1};  // Connect to the row pinouts of the keypad
byte colPins[COLS] = {34, 21, 14, 12};  // Connect to the column pinouts of the keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
String enteredCode = "";
String correctCode = "1234";

bool alarmActive = true;

void checkKeypad() {
  char key = keypad.getKey();
  Serial.print("Key pressed: "); Serial.println(key);
  
  if (key) {
    if (key == '*' || key == '#' || key == 'A' || key == 'B' || key == 'C' || key == 'D') {
      if (enteredCode == correctCode) {
        alarmActive = false;
        tempDetected = false;
        gasDetected = false;
        stopAlarm();
        logEvent("Alarm deactivated.");
      }
      enteredCode = "";
    } else {
      enteredCode += key;
    }
  }
  Serial.print("Entered Code: "); Serial.println(enteredCode);
  Serial.print("Alarm Active: "); Serial.println(alarmActive);
}
