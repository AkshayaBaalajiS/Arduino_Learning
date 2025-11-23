#define TX 17
#define RX 16

void setup()
{
	Serial.begin(115200);
	Serial2.begin(9600, SERIAL_8N1, RX, TX);
}

void loop()
{
	// Serial2.write("This is the data passed from the Serial2 TX2 GPIO through write \n");
	Serial2.println("This is the data passed from the Serial2 TX2 GPIO through println");
	if(Serial2.available())
	{
		String data = Serial2.readStringUntil('\n');
		Serial.print("Data received is : " );
		Serial.println(data);
	}
}

/*
It is the working code if not working adjust esp32 proper on board 
*/