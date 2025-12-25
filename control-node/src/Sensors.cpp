#include "Sensors.h"

static const int ARM_BUTTON_PIN = 15;
static const int DISARM_BUTTON_PIN = 18;
static const int PIR_SENSOR_PIN = 33;

void initSensors() {
    pinMode(ARM_BUTTON_PIN, INPUT_PULLUP);
    pinMode(DISARM_BUTTON_PIN, INPUT_PULLUP);
    pinMode(PIR_SENSOR_PIN, INPUT);
}

bool armButtonPressed() {
    static bool lastState = false;

    bool currentState = digitalRead(ARM_BUTTON_PIN) == LOW;

    bool pressedEvent = (currentState && !lastState);
    lastState = currentState;

    return pressedEvent;
}

bool disarmButtonPressed() {
    static bool lastState = false;

    bool currentState = digitalRead(DISARM_BUTTON_PIN) == LOW;

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