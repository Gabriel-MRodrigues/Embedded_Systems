#ifndef ACTUATORS_H
#define ACTUATORS_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

void initActuators();

//LED
void setStatusLED(bool on);

//LCD
void initLCD();
void setLCDText(String str, int col = 0, int row = 0);
bool i2CAddrTest(uint8_t addr);

#endif