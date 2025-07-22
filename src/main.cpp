#include <Arduino.h>

#include "Firebase.h"
#include "WiFi.h"
#include "esp_smartconfig.h"
#include "WiFi.h"
#include "Firebase.h"

char *WIFI_SSID = "";
char *WIFI_PASSWORD = "";
char *FIREBASE_URL = "";
char *NAME = "";
int i = 0;

void connectWifi();

void setup() {
	Serial.begin(115200);

	ESP.restart();
	connectWifi();
}

void loop() {
    // String payload = "{";

    // payload.concat("\"status\":");
    // payload.concat(i);
    // payload.concat("}");

    // Firebase::post(FIREBASE_POST.c_str(), payload);
    // Firebase::put(FIREBASE_PUT.c_str(), payload);
    // Firebase::patch(FIREBASE_URL.c_str(), payload);
    // i++;

	
    delay(1000);
}

void connectWifi() {
    WiFi.begin(WIFI_SSID.c_str(), WIFI_PASSWORD.c_str());
	Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	Serial.println("\nConnected to WiFi");
}