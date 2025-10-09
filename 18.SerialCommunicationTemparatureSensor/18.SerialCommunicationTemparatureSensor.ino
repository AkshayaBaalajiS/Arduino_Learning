
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);


void setup()
{
	Serial.begin(115200);
	dht.begin();
	Serial.println("DHT initialized through dht.begin()");
}

void loop()
{
	double humidity = dht.readHumidity();
	double temparature = dht.readTemperature();

	if(isnan(humidity) || isnan(temparature))
	{
		Serial.println("Failed to read temparature || humidity data ");
	} 
}