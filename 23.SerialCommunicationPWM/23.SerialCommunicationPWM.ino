int ledPin = 0;

int button = 0;

int channel = 0;
int frequency = 5000;
int resolution = 8;

void setup()
{
	ledcSetup(channel, frequency, resolution);
	ledcAttachPin(ledPin, channel );
}

void loop()
{
	if(digitalRead(ledPin)==LOW)
	{
		delay(100);
	}

}