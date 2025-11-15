int ledPin = 2;
int ledPin1 = 4;
int button =0;

int channel = 5;
int frequency = 5000;
int resolution =8;

void setup()
{
	pinMode(ledPin, OUTPUT);
	pinMode(button, INPUT_PULLUP);
	ledcSetup(channel, frequency, resolution);
	ledcAttachPin(ledPin, channel);
	Serial.begin(115200);
}
int counter = 0; 

void loop()
{
	if(digitalRead(button)==LOW)
	{
		counter++;
		int constant = 10;
		int dutyCycle = constant * counter;
		if(dutyCycle>255)		
		{
			Serial.println("DutyCycle reached max ");
		}
		else
		{
			ledcWrite(channel, dutyCycle);
		}
		Serial.println("Button Clicked \n Counter Incremented... ");
		// sleep(2);
		delay(900);

	}
	else
	{
		Serial.println("Button Not Clicked ");
	}
}