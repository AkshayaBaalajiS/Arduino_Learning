int dacPin = 25;

void setup()
{
	pinMode(dacPin, OUTPUT);
	Serial.begin(115200);
}

void loop()
{
	if(Serial.available())
	{
		String data  = Serial.readStringUntil('\n');
		Serial.print("Data received is :" );
		Serial.println(data);

		if(data == "Start")
		{
			for(int i=0;i<255;i++)
			{
				dacWrite(dacPin, i);
				delay(100);
			}
		}
		else if(data == "Stop")
		{
			dacWrite(dacPin, 0);
			// digitalWrite(dacPin, 0);
		}
		else if(data == "Exit")
		{
			exit(0);
		}
	}
}