int buttonPin =0;
int ledPin1 = 2;
int ledPin2 = 4;
int ledPin3 = 18;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

static int counter=0;
void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPin) == LOW)
  {
    counter++;
    delay(500);
  }
  if(counter>=5 && counter<=10)
  {
    digitalWrite(ledPin1, HIGH);
    delay(50);
    digitalWrite(ledPin1, LOW);

    digitalWrite(ledPin2, HIGH);
    delay(50);
    digitalWrite(ledPin2, LOW);
    
    digitalWrite(ledPin3, HIGH);
    delay(50);
    digitalWrite(ledPin3, LOW);
  }

  if(counter >=10)
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }

}
