#include <WiFi.h>
#include "esp_wifi.h"

const char * ssid = "testing";
const char * pass = "12345679";

void setup()
{
	Serial.begin(115200);
	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, pass);

	while(WiFi.status() != WL_CONNECTED)
	{
		delay(500);
	}
}

void loop()
{
	Serial.print("MAC Addrress : ");
	Serial.println(WiFi.macAddress());

	Serial.print("IP Addrress : ");
	Serial.println(WiFi.localIP());


	Serial.print("Signal Strength  : ");
	Serial.println(WiFi.RSSI());
	delay(2500);
}