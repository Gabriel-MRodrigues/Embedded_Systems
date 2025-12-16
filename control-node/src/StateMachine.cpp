#include "StateMachine.h"
#include "Sensors.h"
#include "Actuators.h"

static SystemState currentState = STATE_IDLE;

void initStateMachine() {
    currentState = STATE_IDLE;
    Serial.println("STATE: IDLE");
    setStatusLED(false);
}

SystemState getCurrentState() {
    return currentState;
}

void updateStateMachine() {
    switch (currentState) {
        case STATE_IDLE:
            setStatusLED(false);
            
            if(isButtonPressedOnce()) {
                currentState = STATE_MONITORING;
                Serial.println("STATE: MONITORING");
            }
            break;
        
        case STATE_MONITORING:
            setStatusLED(true);

            if(isButtonPressedOnce()) { // motion detected by PIR Motion Sensor
                currentState = STATE_IDLE;
                Serial.println("STATE: IDLE");
            } 
            break;

        case STATE_ALERT: 
            setStatusLED(true);
            // do something with buzzer
            if(false) { // timing - alert duration
                currentState = STATE_MONITORING;
                Serial.println("STATE: MONITORING");
            }
            break;

        case STATE_MANUAL_OVERRIDE:
            setStatusLED(false);
            // do something
            break;

    }
}