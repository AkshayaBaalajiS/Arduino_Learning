int ledPin = 4;
int ledButton = 0;
int ledPin1 = 5;

int channel  = 0 ;
int resolution = 8;
int frequency = 5000;

#include "DHT.h"

#define DHTPIN 2        // GPIO connected to DHT22
#define DHTTYPE DHT22   // DHT11 or DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
	// pinMode(ledPin1, OUTPUT);
	// pinMode(ledButton, INPUT_PULLUP);

	// ledcSetup(channel, frequency, resolution );
	// ledcAttachPin(ledPin, channel);
	dht.begin();
	Serial.begin(115200);
}

int counter=0;
void loop()
{
	// if(digitalRead(ledButton) == LOW)
	// {
	// 	Serial.println("Button Pressed ");
	// 	Serial.println("LedPin Made to light ");
	// 	digitalWrite(ledPin1, HIGH);
	// 	counter++;
	// 	for(int dutyCycle = 0; dutyCycle<25; dutyCycle++)
	// 	{
	// 		int modCycle = dutyCycle * 10;
	// 		ledcWrite(channel, modCycle);
	// 		// delay(700);
	// 		Serial.print("Duty Cycle set to " );
	// 		Serial.print(modCycle);
	// 		Serial.println("");
	// 	}
	// }
	// if(counter > 15)
	// {
	// 	Serial.println("Counter reached 15");
	// 	digitalWrite(ledPin1, LOW);
	// 	ledcWrite(channel, 0);	
	// 	counter = 0;
	// 	sleep(3);
	// }

	int temperature = dht.readTemperature();
	int humidity = dht.readHumidity();


	if (isnan(humidity) || isnan(temperature)) {
	Serial.println("Failed to read from DHT sensor!");
	return;
	  }

	  Serial.print("Humidity: ");
	  Serial.print(humidity);
	  Serial.print("%  |  temperature: ");
	  Serial.print(temperature);
	  Serial.println("°C");

	  delay(2000); // DHT22 updates every ~2 seconds
}
