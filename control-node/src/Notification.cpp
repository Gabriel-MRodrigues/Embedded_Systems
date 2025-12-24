#include "Notifications.h"
#define XSTR(x) #x
#define STR(x) XSTR(x)

const char* ssid = STR(WIFI_SSID);
const char* password = STR(WIFI_PASSWORD);

static unsigned long connectStartTime = 0;
const static unsigned long TRY_CONNECT_DURATION_MS = 500;

const String DISCORD_WEBHOOK_BASE_URL = "https://discordapp.com/api/webhooks/";
const String webhookURL = DISCORD_WEBHOOK_BASE_URL + STR(DISCORD_WEBHOOK_PATH_URL);
static HTTPClient http;

void connectWifi() {
    WiFi.begin(ssid, password);
    Serial.print("Connecting ");
    while (WiFi.status() != WL_CONNECTED) {
        if (millis() - connectStartTime >= TRY_CONNECT_DURATION_MS) {
            connectStartTime = millis();
            Serial.print(".");
        }
    }

    Serial.println("\nConnected to Wi-Fi");
}

void sendDiscordNotification(String message) {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Wi-Fi not connected");
        return;
    } 
    http.begin(webhookURL);
    http.addHeader("Content-Type", "application/json");

    String payload = "{\"content\":\"" + message + "\"}";
    int httpResponseCode = http.POST(payload);

    if (httpResponseCode > 0) {
        Serial.printf("HTTP Response code: %d\n", httpResponseCode);
    }
    else {
        Serial.print("Error sending message");
    }

    http.end();
}