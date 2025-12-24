#include <Arduino.h>
#include "Sensors.h"
#include "Actuators.h"
#include "StateMachine.h"
#include "Notifications.h"

static const int SERIAL_BAUD_RATE = 9600;

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);

  connectWifi();

  initSensors();
  initActuators();
  initStateMachine();
}

void loop() {
  updateStateMachine();
}