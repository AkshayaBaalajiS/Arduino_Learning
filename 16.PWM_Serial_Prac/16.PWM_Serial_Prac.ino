int ledPin = 2;
int button = 0;

int channel = 0;
int resolution = 8;
int frequency = 5000;

void setup()
{
	// pinMode(lecPin, OUTPUT); // ledPin we dont need to set as output 
	pinMode(button, INPUT_PULLUP); 
	ledcSetup(channel, frequency, resolution);
	ledcAttachPin(ledPin, channel);
	Serial.begin(115200);
}

void loop()
{
	if(digitalRead(button)== LOW)
	{
		Serial.println("Button Pressed \n");	
		for(int i=0;i<255;i++)
		{
			ledcWrite(channel, i);	
			delay(250);
		}
		sleep(4);
	}	
	else
	{
		Serial.println("Button Not pressed");
		delay(100);
	
	}	

}