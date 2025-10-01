int ledPin = 2;

int ledChannel = 0;
int frequncy = 5000; // frequency is how fast the turn on and off should happen
int resolution = 8;  // how long this should happen 

void setup()
{
	ledcSetup(ledChannel, frequncy, resolution); // for making the channel as PWM generator 
	ledcAttachPin(ledPin, ledChannel);  // for attaching the PIN to channel 
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