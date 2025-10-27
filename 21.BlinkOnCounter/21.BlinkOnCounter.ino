int ledPin = 2;
int button = 0;

int ledChannel = 0;
int frequency = 5000;
int resolution = 8;

void setup()
{
	Serial.begin(115200);
	ledcSetup(ledChannel, frequency, resolution);
	ledcAttachPin(ledPin, ledChannel);
	pinMode(button, INPUT_PULLUP);
}

int counter = 0;
void loop()
{
	if(digitalRead(button) == LOW)
	{
		counter++;
		delay(500);
	}

	if(counter >=5)
	{
		for(int i=0;i<255;i++)
		{
			ledcWrite(ledChannel, i);
			delay(100);
		}
	}
	if(counter>10)
	{
		ledcWrite(ledChannel, 0);
		sleep(2);
	}
}


