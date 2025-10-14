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
	float humidity = dht.readHumidity();
	float temp = dht.readTemperature();
	
	// Check if reading failed
	if (isnan(humidity) || isnan(temp)) {
		Serial.println("Failed to read from DHT sensor!");
		delay(2000);
		return;
	}

	
	Serial.printf("Temparature : %f\n", temp);
	Serial.printf("Humidity : %f\n", humidity);
	delay(1000);
}