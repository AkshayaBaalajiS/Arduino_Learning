#define TX2 17
#define RX2 16

void setup()
{
	Serial.begin(115200);
	Serial2.begin(9600,SERIAL_8N1, RX2, TX2 );
}

void loop()
{
	Serial2.println("THis is the data sent from the Serial2 RX2 and TX2 pin");
	if(Serial2.available())
	{
		String data = Serial2.readStringUntil('\n');
		Serial.print("Data Received is : ");
		Serial.println(data);
		// delay(1500);
	}
	delay(1500);
}