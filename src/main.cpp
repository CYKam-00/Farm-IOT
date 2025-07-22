#include <Arduino.h>

#include "Firebase.h"
#include "WiFi.h"
#include "esp_smartconfig.h"





char *WIFI_SSID = "";
char *WIFI_PASSWORD = "";
char *FIREBASE_URL = "";
String HOSTNAME = "ESP32";
int i = 0;

void connectWifi();

void setup() {
	Serial.begin(115200);

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