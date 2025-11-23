
void setup()
{
	Serial.begin(115200);
}

void loop()
{
	Serial.write("This is the data passed from the Serial2 TX2 GPIO through write \n");
	// Serial.println("This is the data passed from the Serial TX2 GPIO through println");
	if(Serial.available())
	{
		String data = Serial.readStringUntil('\n');
		Serial.print("Data received is : " );
		Serial.println(data);
	}
}

/*
It is the working code if not working adjust esp32 proper on board 
*/