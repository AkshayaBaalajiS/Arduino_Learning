void setup()
{
	Serial.begin(115200);
}

void loop()
{
	Serial.write("This is the data passed through ESP32  Serial write ");

	if(Serial.available())
	{
		String data = Serial.readStringUntil('\n');
		Serial.print("Data received is : ");
		Serial.println(data);
	}
	delay(2000);
}
/*
Wrie can be done but the wire should not be connected to Rx0 or TX 0 
Don’t use UART0 pins (GPIO 1 / GPIO 3)

Those two pins are reserved for USB communication, boot, and programming.

USB chip convert the USB data to the UART data and these data pass to GPIO3 and GPIO 1 
*/