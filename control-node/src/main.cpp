#include <Arduino.h>
#include "Sensors.h"
#include "Actuators.h"

static const int SERIAL_BAUD_RATE = 9600;

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);

  initSensors();
  initActuators();
}

void loop() {
  setStatusLED(isButtonPressed());
}