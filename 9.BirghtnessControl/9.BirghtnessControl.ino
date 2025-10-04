
int ledPin = 4;

int ledChannel = 0;
int frequency = 5000;
int resolution = 8;

void setup()
{
	ledcSetup(ledChannel, frequency, resolution);
	ledcAttachPin(ledPin, ledChannel);
}

void loop()
{
	for(int i=0;i<255;i++)
	{
		ledcWrite(ledChannel, i);
		delay(10);
	}

	for(int i=255;i>0;i--)
	{
		ledcWrite(ledChannel, i);
		delay(10);

	}

	
}