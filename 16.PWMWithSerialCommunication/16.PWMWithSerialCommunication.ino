int button = 0;
int ledPin = 2;

int ledChannel = 0;
int frequency = 5000;
int resolution = 8;

void setup()
{
	ledcSetup(ledChannel, frequency, resolution);
	ledcAttachPin(ledPin, ledChannel);
	Serial.begin(115200);
	pinMode(button, INPUT_PULLUP);
}

int counter = 0;

void loop()
{
	if(digitalRead(button) == LOW)
	{
		counter++;
		Serial.println("Button Pressed");
		delay(500);
	}
	int dutyCycle;
	if(counter>25)
	{
		Serial.println("Duty Cycle reached to max resetting counter to 0");
		dutyCycle = 255;
		counter = 0;
		Serial.println("Turning OFF Led for 2 Seconds ");
		ledcWrite(ledChannel, 0);
		delay(2000);
	}
	else
	{
		dutyCycle = counter * 10;
	}

	ledcWrite(ledChannel, dutyCycle);

}