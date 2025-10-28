int ledPin = 2;

int button =0;

int ledChannel = 0;
int frequency = 5000;
int resolution = 8;

void setup()
{
	Serial.begin(115200);
	ledcSetup(ledChannel, frequency, resolution);
	ledcAttachPin(ledPin, ledChannel);
}

int counter = 0;

void loop()
{
	if(digitalRead(button) == LOW )
	{
		counter++;
		Serial.println("Button Pressed ");
		delay(500);
	}

	if(counter>5)
	{
		for(int dutyCycle=0; dutyCycle<255;dutyCycle++)
		{
			ledcWrite(ledChannel, dutyCycle);
		}
	}
	else if(counter > 25)
	{
		Serial.println("Counter reached 25 ");
		Serial.println("Setting 0 to ledChannel");
		ledcWrite(ledChannel, 0);
		counter=0;
		sleep(4);
	}

}