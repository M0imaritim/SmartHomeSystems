// smart_home.h

#ifndef SMART_HOME_H
#define SMART_HOME_H

#include <Keypad.h>
#include <DHT.h>
#include <Wire.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// Constants for the number of rows and columns
const byte ROWS = 4;
const byte COLS = 4;

// DHT sensor settings
#define DHTPIN 39
#define DHTTYPE DHT22
extern DHT dht;

// MQ-2 sensor settings
#define MQ2PIN 15  
extern int gasLevelThreshold;

// Keypad settings
extern byte rowPins[ROWS];
extern byte colPins[COLS];
extern char hexaKeys[ROWS][COLS];
extern Keypad keypad;
extern String enteredCode;
extern String correctCode;
extern bool alarmActive = true;

// Buzzer and LED settings
#define BUZZER_PIN 5
#define LED_PIN 33


// Timing and alarm
extern bool gasDetected;
extern bool tempDetected;

// NTP settings
extern const char* ssid;
extern const char* password;
extern WiFiUDP ntpUDP;
extern NTPClient timeClient;

// Function declarations
void initializeKeypad();
void readSensors(); 
void updateLED();
void updateBuzzer();
void checkKeypad();
void stopAlarm();
void logEvent(String eventMessage);

#endif