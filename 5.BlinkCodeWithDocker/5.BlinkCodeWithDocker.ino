int blinkLed = 5;

void setup()
{
	pinMode(blinkLed, OUTPUT);
}

void loop()
{
	digitalWrite(blinkLed, HIGH);
	delay(500);

	digitalWrite(blinkLed, LOW);
	delay(500);
}