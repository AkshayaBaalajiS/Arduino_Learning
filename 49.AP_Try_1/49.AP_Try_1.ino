#include <WiFi.h>
#include "esp_wifi.h"

void setup()
{
	Serial.begin(115200);
	WiFi.mode(WIFI_AP);
	WiFi.softAP("Esp32_WiFi", "12345679");
	Serial.print("WiFi Enabled ");
}

void loop()
{
	int numOfUser = WiFi.softAPgetStationNum();
	Serial.print("No of Users : ");
	Serial.println(numOfUser);
	
	wifi_sta_list_t userList;
	esp_wifi_ap_get_sta_list(&userList);

	for(int i=0;i<userList.num;i++)
	{
		wifi_sta_info_t infoSta = userList.sta[i];
		Serial.print("User : ") ;
		Serial.println(i+1);

		Serial.print("Mac : ") ;

		
		
		for(int j=0;j<6;j++)
		{
			Serial.print(infoSta.mac[i]);
			if(j<=5)
			{
				Serial.print(":");
			}
		}
		Serial.println();
	}
}