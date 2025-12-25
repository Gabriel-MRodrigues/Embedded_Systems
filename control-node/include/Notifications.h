#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

void connectWifi();

void sendDiscordNotification(String message);

#endif