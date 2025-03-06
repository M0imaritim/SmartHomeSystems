# Smart Home Security System

## 📌 Overview

This project is a **Smart Home Security System** utilizing sensors, a keypad, and an alarm system to monitor environmental conditions and detect security threats. The system integrates **Wi-Fi connectivity** to sync with **Network Time Protocol (NTP)** for accurate timestamping of events.

## 🚀 Features

- **Gas Leak Detection**: MQ-2 sensor monitors gas levels and triggers an alarm if the threshold is exceeded.
- **Temperature Monitoring**: DHT22 sensor checks temperature levels and alerts when exceeding safe limits.
- **Keypad Authentication**: Users enter a security code via a 4x4 keypad to arm/disarm the system.
- **Buzzer & LED Alerts**: Audible and visual alerts for security breaches or environmental hazards.
- **Event Logging**: Records key security events with timestamps.
- **Wi-Fi Enabled**: Synchronizes time via NTP for precise event logging.

## 🛠️ Components Used

- **DHT22** - Temperature and humidity sensor
- **MQ-2** - Gas sensor for detecting LPG, smoke, etc.
- **4x4 Keypad** - User authentication interface
- **Buzzer** - Alarm system
- **LED** - Visual indicator
- **ESP32** - Microcontroller with Wi-Fi support

## 📁 File Structure

```
├── smart_home.h       # Header file with sensor configurations and function declarations
├── smart_home.ino     # Main Arduino script implementing the system logic
└── README.md          # Project documentation
```

## 📜 Setup & Usage

1. **Connect Hardware**: Assemble the components according to circuit schematics.
2. **Install Dependencies**:
   - Install **Arduino IDE**
   - Add the required libraries:
     - `Keypad.h`
     - `DHT.h`
     - `Wire.h`
     - `WiFi.h`
     - `NTPClient.h`
3. **Configure Wi-Fi**:
   - Update `ssid` and `password` in `smart_home.h`
4. **Upload Code**:
   - Flash `smart_home.ino` onto your ESP32 board.
5. **Monitor Serial Output**:
   - Use the Serial Monitor to debug and check real-time sensor readings.

## 🔧 Functions

| Function                  | Description                                             |
| ------------------------- | ------------------------------------------------------- |
| `setupSensors()`          | Initializes sensors and components.                     |
| `readGasSensor()`         | Reads gas sensor data and triggers alarm if necessary.  |
| `readTemperatureSensor()` | Monitors temperature and triggers an alert if too high. |
| `updateLED()`             | Controls LED status based on alarm conditions.          |
| `updateBuzzer()`          | Activates or deactivates the buzzer for alarms.         |
| `checkKeypad()`           | Reads user input and verifies the security code.        |
| `stopAlarm()`             | Deactivates the alarm when the correct code is entered. |
| `logEvent()`              | Logs security events with timestamps.                   |

## 📌 Future Improvements

- **Mobile App Integration** for remote control and notifications.
- **Cloud Logging** for historical data analysis.
- **More Sensors** for enhanced security and automation.

---

🌟 **Like this project?** Give it a ⭐ !!
