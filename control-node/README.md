# ESP32 Alarm Control Node

A simple alarm system built with an **ESP32**, designed as a control node that monitors motion, triggers alerts, and allows manual user interaction.  
This project evolved from a general control node into a fully functional **alarm system with states, sensors, actuators, and notifications**.

---

## 📌 Features

- Finite State Machine (FSM) architecture
- Motion detection using a PIR sensor
- Visual status indication using built-in LED
- Alert using a buzzer
- LCD display for system state and alert countdown
- Wi-Fi connectivity
- Discord webhook notifications

---

## 🧠 System States

| State        | Description                   |
| ------------ | ----------------------------- |
| `IDLE`       | System is inactive            |
| `MONITORING` | Monitoring for motion         |
| `ALERT`      | Motion detected, alarm active |
| `DISARM`     | System manually disarmed      |

State transitions are handled through a centralized **state machine**.

---

## 🧰 Hardware Components

- ESP32 (Freenove ESP32 WROVER)
- PIR Motion Sensor
- Push Buttons (Arm / Disarm)
- Buzzer
- I2C LCD Display (16x2)
- Wi-Fi connection

---

## 🔨 Hardware Pin Plan

- LED - GPIO 2
- Alarm Button - GPIO 15
- Disarm Button - GPIO 18
- PIR Motion Sensor - GPIO 33
- Buzzer - GPIO 4
- LCD SDA - GPIO 13
- LCD SCK - GPIO 14

---

## 🥅 Hardware Connection Diagram

<img src="/control-node/docs/images/Hardware_Connection_Diagram.png" alt="Connection_Diagram" width="550"/>

---

## 🧩 Software Architecture

The project is structured in a **modular way**:

```bash
/control-node
|
├── /docs
│   ├── images/
│   |   ├── Hardware_Connection_Diagram.png
│   ├── Hardware_Pin_Plan.txt
|
├── /include                # Directory to include project header files
│   ├── Actuators.h         # Output components (Buzzer, LED, LCD)
|   ├── Notifications.h     # WiFi connectivity and Discord Notifications
|   ├── Sensors.h           # Input components (Buttons, PIR Sensor)
|   └── StateMachine.h      # Handles state transitions and system logic
|
├── /src
│   ├── Actuators.cpp       # Implementation of Output components
|   ├── main.cpp            # Entry point
|   ├── Notifications.cpp   # Implementation of notifications
|   ├── Sensors.cpp         # Implementation of Input components
|   └── StateMachine.cpp    # Implementation of state transitions
|
├── .gitignore
├── env-extra.py            # Script to grab sensitive data (variables) from .env file
├── platformio.ini          # PlatformIO project configuration file
│
└── README.md
```

---

## 🌐 WiFi & Environment variables

Sensitive data is stored using environment vairables:

- **WIFI_SSID**
- **WIFI_PASSWORD**
- **DISCORD_WEBHOOK_PATH_URL**

These are injected at build time using **platformio.ini** and a **.env** file through a **python** script.

---

## 📡 Discord Notifications

When an alert is triggered, the system sends a message to a **Discord** channel using a **webhook**.

---

## 🛠 Development Tools

- PlatformIO
- Arduino Framework
- ESP32
- LiquidCrystal Library

---

## 📈 Future Improvements

- Add **mobile app** or **web dashboard**
- Support many **sensors**

---

## 👤 Author

**Gabriel Mendes Rodrigues**

**ESP32 / Embedded Systems Project**
