#include <Arduino.h>
#include "Sensors.h"

const int LED_PIN = 2;
const int SERIAL_BAUD_RATE = 9600;

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);

  pinMode(LED_PIN, OUTPUT);
  initSensors();
}

void loop() {
  if (isButtonPressed()) { // pressed
    Serial.println("BUTTON PIN - LOW");
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    Serial.println("BUTTON PIN - HIGH");
    digitalWrite(LED_PIN, LOW);
  }
}