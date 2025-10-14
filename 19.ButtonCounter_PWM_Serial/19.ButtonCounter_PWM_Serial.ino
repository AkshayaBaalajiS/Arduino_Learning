int ledPin  = 2;

int  ledChannel = 0 ;
int frequency = 5000 ;
int resolution = 8 ;

int button = 0 ;
int dutyCycle = 0;

static int counter = 0 ;


void setup()
{
	pinMode(button, INPUT_PULLUP);
	ledcSetup(ledChannel, frequency, resolution);
	ledcAttachPin(ledPin, ledChannel);
	Serial.begin(115200);
}

void loop()
{
	if(digitalRead(button) ==  LOW)
	{
		Serial.println("Button Pressed");
		dutyCycle = dutyCycle + 10;
		ledcWrite(ledChannel, dutyCycle);
		delay(100);
		++counter;
		Serial.print("Counter  : ");
		Serial.print(counter);
		Serial.println("");
	}
	if(counter > 25)
	{
		Serial.println("Counter Reached 25 LED turned OFF ");
		ledcWrite(ledPin, 0);
	}
}