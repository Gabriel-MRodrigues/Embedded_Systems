#include "Sensors.h"

static const int BUTTON_PIN = 15;
static const int PIR_SENSOR_PIN = 33;

void initSensors() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(PIR_SENSOR_PIN, INPUT);
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

bool motionJustStarted() {
    static bool lastState = false;
    bool currentState = digitalRead(PIR_SENSOR_PIN) == HIGH;

    bool triggered = (currentState && !lastState);
    lastState = currentState;

    return triggered;
}