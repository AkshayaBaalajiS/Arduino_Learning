void setup()
{
	Serial.begin(115200);
}

void loop()
{
	Serial.println("Hi this is from the code .ino file");
	Serial.write("Hi This is Akshay", 18);
	int readBytes = Serial.read();
	Serial.print("readBytes =  ");
	Serial.print(readBytes);

	sleep(1);
	if(Serial.available())
	{
		String data = Serial.readString();
		/*
		String 
		is not c char * or cpp std::string 
		this is the arduino provided Class 
			that manages the char buffer with char U and for allocation uses malloc and realloc 
			operator overloading is also done  
		*/
		Serial.print("THe variable Holds : ");
		Serial.println(data);
		delay(2000);
	}
}

// Here we will not get any data cause we are reading the same UART so the Receiver will not have any data 