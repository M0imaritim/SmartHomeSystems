// main.ino
#include "smart_home.h"

const char* ssid = "Jerry";
const char* password = "1234#56789";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 0, 60000);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  dht.begin();
  
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  timeClient.begin();
  
  logEvent("Smart home system started.");
}

void loop() {
  timeClient.update();
  
  readGasSensor();
  readTemperatureSensor();
  
  updateLED();
  updateBuzzer();  // Handle the LED blinking and buzzer
  checkKeypad();         // Check keypad for deactivating the alarm
  
}

void logEvent(String eventMessage) {
  String timeStamp = timeClient.getFormattedTime();
  Serial.println("[" + timeStamp + "] " + eventMessage);
}
