// DAC on GPIO25
int dacPin = 25;

void setup() {
  dacWrite(dacPin, 0);   // Initialize to 0V
}

void loop() {
  dacWrite(dacPin, 85);   // ~1.1V
  delay(1000);

  dacWrite(dacPin, 170);  // ~2.2V
  delay(1000);

  dacWrite(dacPin, 255);  // ~3.3V
  delay(1000);

  dacWrite(dacPin, 0);    // 0V
  delay(1000);
}
