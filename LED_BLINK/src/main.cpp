#include <Arduino.h>
#define LED_YELLOW_PIN 15
#define DELAY 1000
#define LED_GREEN_PIN 4
#define LED_RED_PIN 0


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_RED_PIN, HIGH);
  delay(5000);
  digitalWrite(LED_RED_PIN, LOW);
  delay(1000);

  digitalWrite(LED_YELLOW_PIN, HIGH);
  delay(2000);
  digitalWrite(LED_YELLOW_PIN, LOW);
  delay(1000);

  digitalWrite(LED_GREEN_PIN, HIGH);
  delay(5000);
  digitalWrite(LED_GREEN_PIN , LOW);
  delay(1000);
}

