int led1  = 2;
int led2  = 4;
int led3  = 5;

int buttonClick = 0 ;

void setup()
{
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	pinMode(buttonClick, INPUT_PULLUP);
}

static int counter =0 ;

void loop()
{
	if(digitalRead(buttonClick) == LOW)
	{
	 	counter++;
	 	delay(50);
	}

	if(counter >= 5 && counter <= 10)
	{
		digitalWrite(led1,HIGH);
		delay(20);
		digitalWrite(led1,LOW);
		// delay(20);
		
		digitalWrite(led2,HIGH);
		delay(20);
		digitalWrite(led2,LOW);
		// delay(20);

		digitalWrite(led3,HIGH);
		delay(20);
		digitalWrite(led3,LOW);
		// delay(20);

	}
	if(counter>10)
	{
		digitalWrite(led1,LOW);
		digitalWrite(led2,LOW);
		digitalWrite(led3,LOW);
	}
}
// void setup() {
//   // put your setup code here, to run once:

// }

// void loop() {
//   // put your main code here, to run repeatedly:

// }
