#include "StateMachine.h"
#include "Sensors.h"
#include "Actuators.h"
#include "Notifications.h"

static SystemState currentState = STATE_IDLE;

//Timing
static unsigned long alertStartTime = 0;
static const unsigned long ALERT_DURATION_MS = 5000;

void initStateMachine() {
    currentState = STATE_IDLE;
    Serial.println("STATE: IDLE");
    clearLCD();
    setLCDText("IDLE");
    setStatusLED(STATE_IDLE);
}

SystemState getCurrentState() {
    return currentState;
}

void setDisarmState() {
    currentState = STATE_DISARM;
    Serial.println("STATE: DISARMED");
    clearLCD();
    setLCDText("DISARMED");
}

void updateStateMachine() {
    switch (currentState) {
        case STATE_IDLE:
            setStatusLED(STATE_IDLE);
            breakTone();
            
            if(armButtonPressed()) {
                currentState = STATE_MONITORING;
                Serial.println("STATE: MONITORING");
                clearLCD();
                setLCDText("MONITORING");
            }
            else if (disarmButtonPressed()) {
                setDisarmState();
            }
            break;
        
        case STATE_MONITORING:
            setStatusLED(STATE_MONITORING);
            breakTone();

            if(motionJustStarted()) { // motion detected by PIR Motion Sensor
                sendDiscordNotification("ALERT: MOTION DETECTED");
                currentState = STATE_ALERT;
                alertStartTime = millis();
                Serial.println("STATE: ALERT");
                clearLCD();
                setLCDText("ALERT");
            }
            else if (disarmButtonPressed()) {
                setDisarmState();
            }
            break;

        case STATE_ALERT: 
            setStatusLED(STATE_ALERT);
            setTone();
            setLCDCountdown(ALERT_DURATION_MS, alertStartTime);

            if(millis() - alertStartTime >= ALERT_DURATION_MS) { // timing - alert duration
                currentState = STATE_MONITORING;
                Serial.println("STATE: MONITORING");
                clearLCD();
                setLCDText("MONITORING");
            }
            else if (disarmButtonPressed()) {
                setDisarmState();
            }
            break;

        case STATE_DISARM:
            setStatusLED(STATE_DISARM);
            breakTone();

            if (disarmButtonPressed() || armButtonPressed()) {
                currentState = STATE_IDLE;
                Serial.println("STATE: IDLE");
                clearLCD();
                setLCDText("IDLE");
            }
            break;

    }
}