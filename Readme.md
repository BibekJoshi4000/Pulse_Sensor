# Pulse Sensor with ESP32

This program uses an ESP32 microcontroller and a pulse sensor to measure the heart rate and send the data to a remote server or the ThingSpeak platform.

## Prerequisites

- ESP32 microcontroller
- Pulse sensor
- Arduino IDE (or compatible IDE)
- WiFi network credentials
- ThingSpeak account 

## Hardware Setup

1. Connect the power and ground pins of the pulse sensor to the 3.3V and GND pins on the ESP32, respectively.
2. Connect the signal pin of the pulse sensor to a digital pin on the ESP32 (e.g., pin 32).
3. Ensure that the ESP32 is properly connected to your computer.

## Software Setup

1. Install the Arduino IDE and open it.
2. Install the required libraries:
   - For ThingSpeak: WiFi, ThingSpeak, and ESP32 ThingSpeak libraries
3. Set up your WiFi network credentials by modifying the `ssid` and `password` variables in the code.
4. Set up your ThingSpeak account and obtain the API key.
5. Modify the code to select the appropriate data upload method:
   - For ThingSpeak: Update the `ssid`, `password`, `server`, `apiKey`, and `fieldId` variables with your ThingSpeak credentials.
6. Upload the code to your ESP32.

## Usage

1. Make sure the ESP32 is powered on and connected to the WiFi network.
2. The program will read the heart rate from the pulse sensor and send it to the ThingSpeak at regular intervals.
3. View the heart rate data on ThingSpeak platform.

## Troubleshooting

- If you encounter any issues, double-check your hardware connections and WiFi credentials.
- Verify that the required libraries are installed correctly.
- For ThingSpeak, make sure your account and API key are valid and that you have created the necessary channel and fields.
