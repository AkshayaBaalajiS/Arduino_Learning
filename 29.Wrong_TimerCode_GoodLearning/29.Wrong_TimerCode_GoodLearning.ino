hw_timer_t * timer_v = NULL;

volatile int counter = 0 ;

// FOR LED 
int button = 0 ;
int ledPin = 2;

// FOR PWM
int channel = 0;
int resolution  = 8;
int frequency  = 5000;

// we are trying to make a pin to low 
void IRAM_ATTR someFunction()
{
	// digitalWrite(button) = LOW; // wrong syntax 
	digitalWrite(button, LOW);  // button is INPUT_PULLUPwhich cant be written using the digitalWrite 

	Serial.println("Through timer and interrupt we are setting the button to low state through digital write ");
}

void setup()
{
	pinMode(button, INPUT_PULLUP);
	ledcSetup(channel, frequency, resolution);
	ledcAttachPin(ledPin, channel);

	// TIMER 	
	timer_v = timerBegin(0, 8000, true);
	// prescaler =  8000 
	// 80 000 000 / 8000 -> 10 000 | 1 000 000 / 10 000 = 100 micro sec  

	timerAttachInterrupt(timer_v, &someFunction, true);

	timerAlarmWrite(timer_v, 10000, true);

	// here true is for auto reload after interrupt occur

	timerAlarmEnable(timer_v);

	Serial.begin(115200);
}

void loop()
{
	if(digitalRead(button)==LOW)
	{
		Serial.println("Button pressed through interrupt / timer  \n");
		 digitalWrite(button, HIGH); 
		counter++;
		const int constt = 10;
		int dutyCycle = constt * counter;


		if(dutyCycle > 255)
		{
			Serial.println("Duty cycle reached to max \n");
		}
		ledcWrite(channel, dutyCycle);
		delay(1500); // 1.5 sec delay 
	}
	else
	{
		Serial.println("Button state is low ");
		ledcWrite(channel, 0);
	}
}