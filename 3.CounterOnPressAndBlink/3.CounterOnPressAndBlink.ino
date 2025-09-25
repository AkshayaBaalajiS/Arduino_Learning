int pin =5 ;
int pin1 =21;
int pin2 =2 ;
int inputPin  = 0;

void setup()
{
  pinMode(pin, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);
}


void functionToLight()
{
  digitalWrite(pin, HIGH);
  delay(50);
  digitalWrite(pin, LOW);
  
  digitalWrite(pin1, HIGH);
  delay(50);
  digitalWrite(pin1, LOW);
  
  digitalWrite(pin2, HIGH);
  delay(50);
  digitalWrite(pin2, LOW);  
}

void functionToOffLight()
{
  digitalWrite(pin, LOW);
  // delay(500);
  
  digitalWrite(pin1, LOW);
  // delay(500);
  
  digitalWrite(pin2, LOW);  
  // delay(500);
}


static int counter = 0;

void loop() // loop() executes thousands of times per second.
{
  if(digitalRead(inputPin) == LOW )
  {
    counter++;
    delay(500);
  }
  if(counter>=5 && counter<=10) 
  {
    functionToLight();
  }
  else //if(counter>10 )
  {
    functionToOffLight();
  }
  // if(counter>25)
  // {
  //   functionToLight();
  // }
}