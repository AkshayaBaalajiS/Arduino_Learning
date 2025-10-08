// Serial Communication : 

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	Serial.print("This is from Serial.print\n");
	delay(1500);
	int numOfCharToRead = Serial.available();
	delay(1500);
	char c = Serial.read();
	delay(1500);
	Serial.print("Print of the variable c");
	Serial.print(c);
	delay(1500);
	Serial.println("This is from the serial.println");
}