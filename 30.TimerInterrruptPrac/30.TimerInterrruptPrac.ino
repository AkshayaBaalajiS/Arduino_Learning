int ledPin = 2;
volatile bool ledSwitch = false;

hw_timer_t * timerVar = NULL;


void IRAM_ATTR timerFunc ()
{
	ledSwitch = !ledSwitch;
}

void setup()
{
	timerVar  = timerBegin(0, 800, true);
	// timer 0
	// 800 prescalar 
	// true count up 
	timerAttachInterrupt(timerVar, timerFunc, true );
	// timerVar passed 
	//  IRAM_ATTR function passed 
	// true edge trigger 

	timerAlarmWrite(timerVar, 100000, true);
	// timerVar for timer variable 
	// 100000 prescaler 
	// true auto reload after interrupt  

	timerAlarmEnable(timerVar);

	pinMode(ledPin, OUTPUT);


}

void loop()
{
	digitalWrite(ledPin, ledSwitch);
}