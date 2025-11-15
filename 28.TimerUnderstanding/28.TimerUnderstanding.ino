hw_timer_t *timer_v = NULL;


int ledPin = 2;
volatile bool flagVar = false;

void IRAM_ATTR someFunctionName()
{
	flagVar = !flagVar;
}

void setup()
{
	pinMode(ledPin, OUTPUT);
	timer_v = timerBegin(0, 800, true); 
	// arguments are  
	/*
	timer as 0 
	800Mhz passed 800/80 = 10Mhz each timer tick is 1 milliseconds 
	true is 
	*/
	timerAttachInterrupt(timer_v, &someFunctionName, true);
	// arguments are 
	/*
	timer_v passed as arg 
	IRAM function passed 
	true - 
	*/

	timerAlarmWrite(timer_v, 2000000, true);
	// arguments are 
	/*
	timer_v passed as arg
	2000 is the milliseconds 
	true - 
	*/	
	timerAlarmEnable(timer_v);
	// timer_v passed as arg to start the timer 
}

void loop()
{
	digitalWrite(ledPin, flagVar );
}