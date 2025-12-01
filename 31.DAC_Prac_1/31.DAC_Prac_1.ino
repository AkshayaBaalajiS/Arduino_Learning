int dacPin = 25 ;

void setup()
{
	dacWrite(dacPin, 0);
}

void loop()
{
	for(int i=0;i<255;i++)
	{
		dacWrite(dacPin, i);
	}
}