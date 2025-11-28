#include <Arduino.h>
#define BTN_PIN 15
#define LED_PIN 12

bool ledState = false;
bool lastButtonState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool currentButtonState = digitalRead(BTN_PIN);

  if(currentButtonState == HIGH && lastButtonState == LOW) {
    ledState = !ledState;
    delay(50);
  }

  lastButtonState = currentButtonState;

  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
}

