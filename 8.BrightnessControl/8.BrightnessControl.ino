int ledPin = 2;

int ledChannel = 0;
int frequncy = 5000;
int resolution = 8;

void setup()
{
	ledcSetup(ledChannel, frequncy, resolution);
	ledcAttachPin(ledPin, ledChannel);
}

void loop()
{
	for(int i=0;i<255;i++)
	{
		ledcWrite(ledChannel, i);
		delay(10);
	}
	for(int i=255;i>=0;i--)
	{
		ledcWrite(ledChannel, i);
		delay(10);
	}
	

}