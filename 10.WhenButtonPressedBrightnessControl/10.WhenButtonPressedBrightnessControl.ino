
int ledPin = 2;
int button = 0;

int ledChannel = 0;
int frequency = 5000;
int resolution = 8;


void setup()
{
	ledcSetup(ledChannel, frequency, resolution);
	ledcAttachPin(ledPin, ledChannel);

	pinMode(button, INPUT_PULLUP);
}

void loop()
{
	if(digitalRead(button) == LOW)
	{
		for(int dutyCycle=0;dutyCycle<255;dutyCycle++)
		{
			ledcWrite(ledChannel, dutyCycle);
		}
		for(int dutyCycle=255;dutyCycle>0;dutyCycle--)
		{
			ledcWrite(ledChannel, dutyCycle);
		}	
	}
}
