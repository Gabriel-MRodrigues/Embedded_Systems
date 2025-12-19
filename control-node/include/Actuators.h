#ifndef ACTUATORS_H
#define ACTUATORS_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "StateMachine.h"

void initActuators();

//LED
void setStatusLED(SystemState state);
void blinkLED(unsigned long onTime, unsigned long offTime);

//LCD
void initLCD();
void setLCDText(String str, int col = 0, int row = 0);
bool i2CAddrTest(uint8_t addr);

//Buzzer
void initBuzzer();
void setTone();
void breakTone();

#endif