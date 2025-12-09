#include <WiFi.h>
#include "esp_wifi.h"

void setup()
{
	Serial.begin(115200);
	WiFi.mode(WIFI_AP_STA);
	WiFi.begin("testing", "12345679");

	while(WiFi.status()!=WL_CONNECTED)
	{
		delay(500);
	}

	Serial.println("Connected to 16 plus Hotspot ");

	WiFi.softAP("Esp32_WiFi", "12345679");
}

void loop()
{
	int numOfDevConn = WiFi.softAPgetStationNum();
	Serial.print("Num of Device Connected :");
	Serial.println(numOfDevConn);

	wifi_sta_list_t stationInfo;
	esp_wifi_ap_get_sta_list(&stationInfo);

	for(int i=0;i<stationInfo.num;i++)
	{
		wifi_sta_info_t wifiSta = stationInfo.sta[i];
		Serial.print(i+1);
		Serial.print(" Device MAC = ");
		for(int j=0;j<6;j++)
		{
			Serial.print(wifiSta.mac[j]);
			if(j<5)
			{
				Serial.print(":");
			}
		}
		Serial.println();
	}
}

/*
ESP32 has NO NAT (Network Address Translation) functionality in Arduino.
Without NAT, ESP32 cannot act as a mini-router.

So even though ESP32 is connected to internet, devices connected to ESP32 do NOT get internet.
*/