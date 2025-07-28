#include <Arduino.h>

#include "Firebase.h"
#include "WiFi.h"

char *WIFI_SSID = "";
char *WIFI_PASSWORD = "";
char *FIREBASE_URL = "";
String HOSTNAME = "ESP32";

void connectWifi();
void connectEspTouch();

void setup() {
    Serial.begin(115200);

    connectEspTouch();
    // connectWifi();
}

void loop() {
    // connectWifi();
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    // String payload = "{";

    // payload.concat("\"status\":");
    // payload.concat(i);
    // payload.concat("}");

    // Firebase::post(FIREBASE_POST.c_str(), payload);
    // Firebase::put(FIREBASE_PUT.c_str(), payload);
    // Firebase::patch(FIREBASE_URL.c_str(), payload);
    // i++;

    delay(5000);
    connectEspTouch();
}

void connectWifi() {
    WiFi.mode(WIFI_MODE_NULL);
    WiFi.disconnect();
    WiFi.setHostname(HOSTNAME.c_str());

    WiFi.begin(WIFI_SSID.c_str(), WIFI_PASSWORD.c_str());
    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
}

// esp touch
void connectEspTouch() {
    WiFi.disconnect(true, true);
    WiFi.mode(WIFI_MODE_STA);
    WiFi.setHostname(HOSTNAME.c_str());
    WiFi.stopSmartConfig();

    WiFi.beginSmartConfig();
    Serial.print("Waiting for ESP Touch");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to ESP Touch");
}