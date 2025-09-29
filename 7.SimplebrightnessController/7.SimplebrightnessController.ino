

int ledChannel = 0;
int frequency = 5000;
int resolution = 8;

int ledPin = 2;

void setup()
{
	ledcSetup(ledChannel, frequency, resolution);
	// now the channel 0 act as PWM generator 
	ledcAttachPin(ledPin, ledChannel);
	// attch the pin to that channel 
}

void loop()
{
	for(int i=0;i<255;i++)
	{
		ledcWrite(ledChannel, i);
		delay(10);
	}

	// from brright to fade 
	for(int i=255;i>=0;i--)
	{
		ledcWrite(ledChannel, i);
		delay(10);
	}


}