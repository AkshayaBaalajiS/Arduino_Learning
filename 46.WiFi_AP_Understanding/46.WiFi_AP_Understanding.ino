#include <WiFi.h>

#include "esp_wifi.h"

void setup()
{
	Serial.begin(115200);

	WiFi.mode(WIFI_AP);
	WiFi.softAP("ESP32_WiFi", "12345679");

	Serial.println("Hotspot Turned On ");
}

void loop()
{
	Serial.println("Listing the devices connected ");

	delay(5000); // check every 5 seconds

	int numberOfConnDev = WiFi.softAPgetStationNum();
	Serial.print("Num of devices connected = " );
	Serial.println(numberOfConnDev);

	// Detailed Station 
	wifi_sta_list_t station_det;
	esp_wifi_ap_get_sta_list(&station_det);

	Serial.println("Device Details ");
	for(int i=0;i<station_det.num;i++)
	{
		wifi_sta_info_t station = station_det.sta[i];
		Serial.print("Device ");
		Serial.println(i+1);

		Serial.print("MAC : " );
		for(int j = 0; j < 6; j++) {
	      Serial.printf("%02X", station.mac[j]);
	      if (j < 5) Serial.print(":");
	    }
	}


}

/*

MAC is 6 bytes (48 bits)

Example MAC address:

7A:9C:23:11:3F:AA


Inside ESP32, it is stored like this:

Byte Index	Value (Hex)
0	7A
1	9C
2	23
3	11
4	3F
5	AA

So the MAC is stored as:

uint8_t mac[6];


Thus we must access each byte individually → that's why we loop 6 times.

⭐ 2️⃣ We need to print each byte in HEX format

The MAC must be displayed in:

Hexadecimal (00–FF)

With 2 digits per byte

Uppercase format

With colon separators

station.mac[j] gives you one byte.
%02X prints it as two-digit HEX.


*/