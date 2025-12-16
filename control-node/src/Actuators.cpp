#include "Actuators.h"

static const int LED_PIN = 2;

void initActuators() {
    pinMode(LED_PIN, OUTPUT);
}

void setStatusLED(bool on) {
    digitalWrite(LED_PIN, on ? HIGH : LOW);
}