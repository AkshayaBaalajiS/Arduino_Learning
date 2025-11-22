void setup()
{
	Serial.begin(115200);
}

void loop()
{
	// this throws the one byte 
	//Serial.read();
	if(Serial.available())
	{
		String data = Serial.readStringUntil('\n');  // read until ENTER key
		Serial.print("Data read is : ");
		Serial.println(data);
	}
	delay(1500);
}
/*
throws away one byte always

Serial.read() reads 1 byte from the UART buffer and returns it.

You did NOT check if data exists.

So:

If no data → it returns -1 (nothing)

If data exists → you REMOVE one valid byte from the buffer

That means the first character the user sends is LOST.

🔍 Example to understand

Suppose you type "HELLO" in the terminal.

Incoming buffer in ESP32:

H  E  L  L  O
↑
first character

Code executes:

1️⃣ Serial.read() → takes the H and throws it away
Buffer becomes:

E  L  L  O
*/