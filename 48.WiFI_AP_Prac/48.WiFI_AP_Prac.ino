#include <WiFi.h>
#include "esp_wifi.h"

void setup()
{
	Serial.begin(115200);
	WiFi.mode(WIFI_AP);
	WiFi.softAP("ESP_32_WiFi" , "12345679");

	Serial.print("Hotspot Turned on ");
}

void loop()
{
	Serial.println("List Of Connected devices : ");
	int numberOfDevicesConnected = WiFi.softAPgetStationNum();
	Serial.print("Number Of Devices Connected");
	Serial.print(numberOfDevicesConnected);

	wifi_sta_list_t connectionlist;
	esp_wifi_ap_get_sta_list(&connectionlist);

	for(int i=0;i<connectionlist.num;i++)
	{
		wifi_sta_info_t indSta = connectionlist.sta[i] ;

		Serial.print("Device : " );
		Serial.println(i+1);

		Serial.print("MAC = " );
		for(int j=0;j<6;j++)
		{
			Serial.print(indSta.mac[j]);
			if(j<=5)
			{	
				Serial.print(":");
			}
		}
		Serial.println();
	}
	sleep(4);
}