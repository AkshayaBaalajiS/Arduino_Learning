hw_timer_t * timer_v = NULL;

volatile bool flag = false;
int ledPin = 2;

void IRAM_ATTR onTimer()
{
	flag=!flag;
}

void setup()
{
	pinMode(ledPin, OUTPUT);

	timer_v = timerBegin(0, 8000, true);
	// 0 is the timer channel 0 
	// 8000 is prescaler
	// true is count up 

	timerAttachInterrupt(timer_v, &onTimer, true);
	// timer_v is the timer var
	// onTImer funct attach to Interrupt 
	// true for the 
	// true is the edge count to true 

	timerAlarmWrite(timer_v, 1000, true);
	// timer_v is ther timer var 
	// 1000 is the tick count 
	// true for the auto trigger 

	timerAlarmEnable(timer_v);

}

void loop()
{
	digitalWrite(ledPin, flag);
}