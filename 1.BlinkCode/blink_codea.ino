void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5, HIGH);
  delay(500); // in milli seconds 
  // sleep(5); // in seconds 
  digitalWrite(5, LOW); 
  // sleep(5);
  delay(500);
}
