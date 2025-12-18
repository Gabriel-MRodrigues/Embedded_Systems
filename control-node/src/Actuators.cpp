#include "Actuators.h"

//LED
static const int LED_PIN = 2;

//LCD
static const int SDA_PIN = 13;
static const int SCK_PIN = 14;
LiquidCrystal_I2C lcd(0x27,16,2);

//BUZZER
static const int BUZZER_PIN = 4;
static const int BUZZER_CHANNEL = 0;
static const int BUZZER_FREQ = 1000;
static const int BUZZER_RESOLUTION = 8;
static bool buzzerInitialized = false;
static bool buzzerActive = false;


void initActuators() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    initLCD();
    initBuzzer();
}

void setStatusLED(bool on) {
    // LOW LED On
    // HIGH LED off
    digitalWrite(LED_PIN, on ? LOW : HIGH);
}

void initLCD() {
    Wire.begin(SDA_PIN, SCK_PIN);
    if (!i2CAddrTest(0x27)) {
        lcd = LiquidCrystal_I2C(0x3F, 16, 2);
    }
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
}

void setLCDText(String str, int col, int row) {
    lcd.clear();

    // col range is 0 to 15
    if (col > 15) col = 15;
    else if (col < 0) col = 0;

    // row range is 0 to 1
    if (row > 1) row = 1;
    else if (row < 0) row = 0; 

    lcd.setCursor(col, row);
    lcd.print(str);
}

bool i2CAddrTest(uint8_t addr) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
        return true;
    }
    return false;
}

void initBuzzer() {
    ledcSetup(BUZZER_CHANNEL, BUZZER_FREQ, BUZZER_RESOLUTION);
    ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL);
    buzzerInitialized = true;
}

void setTone() {
    if (!buzzerInitialized) return;

    if (!buzzerActive) {
        ledcWrite(BUZZER_CHANNEL, 128);
        buzzerActive = true;
    }
}

void breakTone() {
    if (!buzzerInitialized) return;

    if (buzzerActive) {
        ledcWrite(BUZZER_CHANNEL, 0);
        buzzerActive = false;
    }
}