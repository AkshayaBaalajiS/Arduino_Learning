int ledPin = 4;

int channel = 0;
int frequency = 5000;
int resolution = 8;

void setup()
{
	Serial.begin(115200);
	ledcSetup(channel, frequency, resolution);
	ledcAttachPin(ledPin, channel);
}

void loop()
{
	if(Serial.available())
	{
		String data = Serial.readStringUntil('\n');
		 // data.trim(); // IMPORTANT - Removes \r \n spaces	
		Serial.print("Data received is : " );
		Serial.println(data);
		if(data == "Start")
		{
			for(int dutyCycle=0;dutyCycle<255;dutyCycle++)
			{
				ledcWrite(channel, dutyCycle);
				delay(600);
			}
			Serial.println("Action Completed");
		}
		if(data == "Stop")
		{
			ledcWrite(channel, 0);
		}
	}
}