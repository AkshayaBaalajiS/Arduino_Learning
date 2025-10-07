int ledPin = 2;

int ledChannel = 0;
int frequency = 5000;
int resolution = 8; // 2 ^ 8 =  256

int button = 0 ;

void setup()
{
	ledcSetup(ledChannel, frequency, resolution); // this makes the channel to act as / to work as PWM generator 
	ledcAttachPin(ledPin, ledChannel);

	pinMode(button, INPUT_PULLUP);
} 

static int counter ;
static int dutyCycle ;

void loop()
{
	if(digitalRead(button) == LOW )
	{
		counter++;
		delay(800);
	}

	dutyCycle = counter * 10;

	ledcWrite(ledChannel, dutyCycle);

	if(counter>=25)
	{
		// digitalWrite(ledPin, LOW);//we cant use the digitalWite cause the pin attached to the channel controlled by PWM so Pwm takes control over hardware 
		ledcWrite(ledPin, 0);
		counter=0;
		sleep(2);
	}	
}