#include "Actuators.h"

static const int LED_PIN = 2;

void initActuators() {
    pinMode(LED_PIN, OUTPUT);
}

void setStatusLED(bool on) {
    // LOW LED On
    // HIGH LED off
    digitalWrite(LED_PIN, on ? LOW : HIGH);
}