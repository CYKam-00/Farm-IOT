#include <Arduino.h>
#include "esp_smartconfig.h"
#include "WiFi.h"
#include "Firebase.h"

char *WIFI_SSID = "";
char *WIFI_PASSWORD = "";
char *FIREBASE_URL = "";
char *NAME = "";
int i = 0;

void setup()
{
	Serial.begin(115200);

	WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
	Serial.print("Connecting to WiFi");

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	Serial.println("\nConnected to WiFi");
}

void loop()
{
	updateStatus(FIREBASE_URL, i);
	i++;
	delay(15000);
}