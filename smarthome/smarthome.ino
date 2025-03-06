// main.ino
#include "smart_home.h"

const char* ssid = "";
const char* password = "";

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

  initializeKeypad();
  
  timeClient.begin();
  
  logEvent("Smart home system started.");
}

void loop() {

  timeClient.update();
  checkKeypad();

  if (!alarmActive) {
  // Stop further processing
    return; // Exit loop early
   }
   
  readSensors();  
  
  
  updateBuzzer(); 
  updateLED();
  
}
void readSensors() {
  static unsigned long previousMillis = 0; // Store the last sensor read time
  const unsigned long interval = 5000;   // 30 seconds interval (in milliseconds)

  unsigned long currentMillis = millis(); // Get the current time

  // Check if 30 seconds have passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Update the last read time

    // Call your sensor reading functions here
    readGasSensor();
    readTemperatureSensor();
  
  }
}


void logEvent(String eventMessage) {
  String timeStamp = timeClient.getFormattedTime();
  Serial.println("[" + timeStamp + "] " + eventMessage);
  
}
