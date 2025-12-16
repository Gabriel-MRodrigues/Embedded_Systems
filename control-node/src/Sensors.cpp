#include "Sensors.h"

static const int BUTTON_PIN = 15;

void initSensors() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

bool isButtonPressed() {
    // not pressed HIGH
    // pressed LOW
    return digitalRead(BUTTON_PIN) == LOW;
}

bool isButtonPressedOnce() {
    static bool initialized = false;
    static bool lastState;

    bool currentState = isButtonPressed();

    if (!initialized) {
        lastState = currentState;
        initialized = true;
        return false;
    }

    bool pressedEvent = (currentState && !lastState);
    lastState = currentState;

    return pressedEvent;
}