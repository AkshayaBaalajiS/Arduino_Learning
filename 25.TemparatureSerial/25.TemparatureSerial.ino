#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
	dht.begin();
	Serial.begin(115200);
}

void loop()
{
	double temp = dht.readTemperature();
	double hum = dht.readHumidity();
		
	if(isnan(temp) || isnan(hum))
	{
		Serial.println("Issue on temparature sensor");
	}
	else
	{
		Serial.print("Temparature ^C  = " );
		Serial.println(temp);
		Serial.print("Humidity % =" );
		Serial.println(hum);	
	}
	sleep(2);

}	