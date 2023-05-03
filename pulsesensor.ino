#include <WiFi.h>
#include <ThingSpeak.h> // including thingspeak library

const char* ssid = "your_SSID"; // wifi ssid
const char* password = "your_PASSWORD"; //wifi password
const char* server = "api.thingspeak.com";
const String apiKey = "your_API_key"; // you thingspeak API key
const int fieldId = 1; // ID of the field to which you want to send the heart rate data

WiFiClient client;

const int pulseSensor = 32; // assuming the pulse sensor is connected to digital pin 32
volatile int bpm;
volatile int pulseCount;
volatile int pulseLast;
volatile int pulseNow;
volatile int pulseSum;

void IRAM_ATTR isr() {
  pulseCount++;
}

void setup() {
  pinMode(pulseSensor, INPUT);
  attachInterrupt(pulseSensor, isr, RISING);
  WiFi.begin(ssid, password);
  Serial.begin(9600);
  ThingSpeak.begin(client);
}

void loop() {
  pulseCount = 0;
  pulseSum = 0;
  pulseLast = 0;
  delay(1000);

  cli(); // disable interrupts
  pulseNow = pulseCount;
  sei(); // enable interrupts

  pulseSum += pulseNow;
  bpm = pulseSum * 60 / 2; // calculate beats per minute (BPM)

  // Send the BPM to ThingSpeak
  ThingSpeak.writeField(channelNumber, fieldId, bpm, apiKey);

  // Wait for 20 seconds before sending the next data point
  delay(20000);
}