#include <WiFi.h>
#include "esp_wifi.h"

const char * ssid = "testing" ;
const char * pass = "12345679";

 void setup()
 {
 	WiFi.mode(WIFI_AP_STA);
 	WiFi.begin(ssid, pass);
 	while(WiFi.status()!=WL_CONNECTED)
 	{
 		delay(150);
 	}
 	WiFi.softAP("testingESPWiFi","12345679");

 	Serial.begin(115200);
 }

 void loop()
 {	
 	int numberOfDev = WiFi.softAPgetStationNum();
 	Serial.print("Num of Dev :");
 	Serial.println(numberOfDev);

 	wifi_sta_list_t wifilist ;
 	esp_wifi_ap_get_sta_list(&wifilist);

 	for(int i=0;i<wifilist.num;i++)
 	{
 		wifi_sta_info_t wifilistInfo = wifilist.sta[i];
 		
 		Serial.print("MAC : ");
 		for(int k=0;k<6;k++)
 		{
 			Serial.print(wifilistInfo.mac[k]);
 			if(k<5)
 			{
 				Serial.print(":");
 			}
 		}
 		Serial.println();
 	}

 	
 }