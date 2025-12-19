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

void setStatusLED(SystemState state) {
    // LOW LED On
    // HIGH LED off
    switch (state) {
        case STATE_IDLE:
            digitalWrite(LED_PIN, HIGH);
            break;
        case STATE_MONITORING:
            digitalWrite(LED_PIN, LOW);
            break;
        case STATE_ALERT:
            blinkLED(250, 250);
            break;
        case STATE_MANUAL_OVERRIDE:
            blinkLED(1000, 1000);
            break;
    }
}

void blinkLED(unsigned long onTime, unsigned long offTime) {
    static unsigned long previousMillis = 0;
    static bool ledState = LOW;
    unsigned long currentMillis = millis();

    if (ledState && (currentMillis - previousMillis >= onTime)) {
        ledState = LOW;
        previousMillis = currentMillis;
        digitalWrite(LED_PIN, ledState);
    }
    else if (!ledState && (currentMillis - previousMillis >= offTime)) {
        ledState = HIGH;
        previousMillis = currentMillis;
        digitalWrite(LED_PIN, ledState);
    }
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