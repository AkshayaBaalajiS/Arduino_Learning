#define TX 17
#define RX 16

void setup()
{
	Serial.begin(115200);
	Serial2.begin(9600, SERIAL_8N1, RX, TX);
}

void loop()
{
	Serial2.println("Data printed with Serial 2 ");
	Serial2.println("This is the data passed from the Serial2 TX2 GPIo 17 ");
	if(Serial2.available())
	{
		String data = Serial2.readStringUntil('\n');
		Serial.print("Data received is : " );
		Serial.println(data);
	}
}