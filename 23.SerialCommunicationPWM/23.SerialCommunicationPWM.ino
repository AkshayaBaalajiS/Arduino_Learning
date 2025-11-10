int ledPin = 0;

int button = 0;

int channel = 0;
int frequency = 5000;
int resolution = 8;

void setup()
{
	ledcSetup(channel, frequency, resolution);
	ledcAttachPin(ledPin, channel );
	Serial.begin(115200);
}

void loop()
{
	if(digitalRead(ledPin)==LOW)
	{
		delay(100);
		Serial.println("Hi OUTPUT");
	}

}