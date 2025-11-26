#include <WiFi.h>

const char * ssid = "testing";
const char * password = "12345679";

void setup()
{
	Serial.begin(115200);
	Serial.print("WiFi code ");
	
	WiFi.mode(WIFI_STA); // station mode 
	WiFi.begin(ssid, password); // ssid and password 
	
	Serial.print("Connecting");
	while(WiFi.status() != WL_CONNECTED )
	{
		delay(500);
	}

}

void loop()
{
	Serial.println("\nConnected!");
	Serial.print("IP Address: ");
	Serial.println(WiFi.localIP());

	Serial.print("MAC Address: ");
	Serial.println(WiFi.macAddress());

	Serial.print("Signal Strength (RSSI): ");
	Serial.println(WiFi.RSSI());
	delay(2500);
}