#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <Arduino.h>

enum SystemState {
    STATE_IDLE,
    STATE_MONITORING,
    STATE_ALERT,
    STATE_MANUAL_OVERRIDE
};

void initStateMachine();

void updateStateMachine();

SystemState getCurrentState();

#endif