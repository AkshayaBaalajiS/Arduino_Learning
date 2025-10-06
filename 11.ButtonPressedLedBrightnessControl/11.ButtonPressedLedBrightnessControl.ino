int ledPin = 4 ;

int ledChannel  = 0;
int frequency = 5000;
int resolution = 8;

int button = 0;

void setup()
{
	pinMode(button, INPUT_PULLUP);
	ledcSetup(ledChannel, frequency, resolution);
	ledcAttachPin(ledPin, ledChannel);
	// pinMode(ledPin, OUTPUT); // this is not needed 
}

void loop()
{
	if(digitalRead(button) == LOW)
	{
		for(int dutyCycle=0;dutyCycle<255;dutyCycle++)
		{
			ledcWrite(ledChannel, dutyCycle);
			delay(10);
		}

		for(int dutyCycle=255;dutyCycle>0;dutyCycle--)
		{
			ledcWrite(ledChannel, dutyCycle);
			delay(10);
		}
	}
	else
	{
		digitalWrite(ledPin, LOW);
	}
}