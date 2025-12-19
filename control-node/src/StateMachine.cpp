#include "StateMachine.h"
#include "Sensors.h"
#include "Actuators.h"

static SystemState currentState = STATE_IDLE;

//Timing
static unsigned long alertStartTime = 0;
static const unsigned long ALERT_DURATION_MS = 5000;

void initStateMachine() {
    currentState = STATE_IDLE;
    Serial.println("STATE: IDLE");
    setLCDText("IDLE");
    setStatusLED(STATE_IDLE);
}

SystemState getCurrentState() {
    return currentState;
}

void updateStateMachine() {
    switch (currentState) {
        case STATE_IDLE:
            setStatusLED(STATE_IDLE);
            breakTone();
            
            if(isButtonPressedOnce()) {
                currentState = STATE_MONITORING;
                Serial.println("STATE: MONITORING");
                setLCDText("MONITORING");
            }
            break;
        
        case STATE_MONITORING:
            setStatusLED(STATE_MONITORING);
            breakTone();

            if(motionJustStarted()) { // motion detected by PIR Motion Sensor
                currentState = STATE_ALERT;
                alertStartTime = millis();
                Serial.println("STATE: ALERT");
                setLCDText("ALERT");
            } 
            break;

        case STATE_ALERT: 
            setStatusLED(STATE_ALERT);
            setTone();

            if(millis() - alertStartTime >= ALERT_DURATION_MS) { // timing - alert duration
                currentState = STATE_MONITORING;
                Serial.println("STATE: MONITORING");
                setLCDText("MONITORING");
            }
            break;

        case STATE_MANUAL_OVERRIDE:
            setStatusLED(STATE_MANUAL_OVERRIDE);
            // do something
            break;

    }
}