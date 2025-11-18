int ledPin = 2;

volatile bool flag = false;

hw_timer_t * timer_v = NULL;

void IRAM_ATTR onTimer()
{
	flag = !flag;
}

void setup()
{
	pinMode(ledPin, OUTPUT);

	timer_v = timerBegin(0, 8000, true);

	timerAttachInterrupt(timer_v, &onTimer, true);

	timerAlarmWrite(timer_v, 100000, true);

	timerAlarmEnable(timer_v);
}

void loop()
{
	digitalWrite(ledPin, flag);
}