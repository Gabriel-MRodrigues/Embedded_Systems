#include "Sensors.h"

static const int BUTTON_PIN = 15;

void initSensors() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

bool isButtonPressed() {
    return digitalRead(BUTTON_PIN) == LOW;
}