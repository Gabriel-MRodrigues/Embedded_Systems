#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

void initSensors();

bool armButtonPressed();
bool disarmButtonPressed();

bool motionJustStarted();

#endif