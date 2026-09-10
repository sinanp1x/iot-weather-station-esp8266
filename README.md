# IoT-Based Weather Station Using ESP32

An IoT-based weather monitoring system that uses an **ESP32** and **DHT22 sensor** to measure temperature and humidity, upload the readings to **ThingSpeak**, visualize the data using live graphs, and generate email alerts when predefined environmental thresholds are exceeded.

## Features

* 🌡️ Temperature monitoring using DHT22
* 💧 Humidity monitoring using DHT22
* 📡 Wi-Fi connectivity using ESP32
* ☁️ Cloud data upload to ThingSpeak
* 📊 Live temperature and humidity graphs
* 📧 Email alerts for threshold conditions
* 🖥️ Serial Monitor output for system status

## System Architecture

```text
DHT22 Sensor
     │
     ▼
   ESP32
     │
     │ Wi-Fi
     ▼
ThingSpeak Cloud
     │
     ├── Temperature Graph
     ├── Humidity Graph
     │
     └── Alert System
             │
             ▼
        Email Notification
```

## Hardware

* ESP32 development board
* DHT22 temperature and humidity sensor
* Jumper wires
* Breadboard
* USB cable

## Software & Services

* Arduino IDE
* Arduino ESP32 board package
* DHT sensor library
* ThingSpeak
* MATLAB Analysis / ThingSpeak React
* Wi-Fi network

## Working Principle

The DHT22 sensor measures the surrounding temperature and humidity. The ESP32 reads these values and connects to a Wi-Fi network.

The measured data is then uploaded to ThingSpeak using the ThingSpeak API. ThingSpeak stores and displays the sensor readings through live graphs.

The system also checks predefined threshold values. If conditions such as high humidity or high temperature are detected, an alert is generated and an email notification is sent.

## Thresholds

The demonstration uses threshold conditions such as:

| Parameter   | Condition  |
| ----------- | ---------- |
| Temperature | Above 35°C |
| Temperature | Below 10°C |
| Humidity    | Above 85%  |

These values can be modified in the Arduino code according to the application requirements.

## Project Structure

```text
iot-weather-station-esp32/
│
├── iot_weather_station.ino
├── README.md
├── LICENSE
│
└── images/
    ├── system-architecture.png
    ├── serial-monitor.png
    ├── thingspeak-graphs.png
    └── email-alert.png
```

## Setup

1. Install Arduino IDE.
2. Install the ESP32 board package.
3. Install the required DHT and ThingSpeak libraries.
4. Connect the DHT22 sensor to the ESP32.
5. Enter your Wi-Fi credentials in the Arduino code.
6. Configure your ThingSpeak channel and Write API Key.
7. Upload the code to the ESP32.
8. Open the Serial Monitor to verify sensor readings and ThingSpeak updates.
9. Configure the ThingSpeak alert system for email notifications.

> **Note:** Do not upload real Wi-Fi passwords, API keys, or other private credentials to a public GitHub repository. Use placeholders in the source code.

## Results

The completed system demonstrates:

* Successful acquisition of temperature and humidity data.
* Successful Wi-Fi communication.
* Successful ThingSpeak cloud updates.
* Live visualization of sensor data.
* Email notification when the configured humidity threshold is exceeded.

## Future Improvements

Possible improvements include:

* Adding additional environmental sensors.
* Adding a display for local monitoring.
* Implementing multiple alert conditions.
* Adding more advanced data analysis.
* Creating a dedicated web or mobile dashboard.
* Improving the alert and notification system.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

## Author

**Muhammed Sinan P** aka Sinanp1x

Academic IoT Weather Station Project
