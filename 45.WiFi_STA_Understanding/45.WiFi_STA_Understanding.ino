#include <WiFi.h>

const char * ssid = "testing";
const char * password = "12345679";

void setup()
{
	Serial.begin(115200);

	WiFi.mode(WIFI_STA); // access point mode (hotspot)
	WiFi.begin(ssid, password);

	while(WiFi.status() != WL_CONNECTED)
	{
		delay(850);
	}
}

void loop()
{

	Serial.print("Local IP : ");
	Serial.println(WiFi.localIP());

	Serial.print("MAC ADDR : ");
	Serial.println(WiFi.macAddress());

	Serial.print("Received Signal Strength : ");
	Serial.println(WiFi.RSSI());	
	delay(2500);
}
