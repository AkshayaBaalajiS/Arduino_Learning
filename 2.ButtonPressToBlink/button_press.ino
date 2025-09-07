int pin = 2;       // onboard LED (usually GPIO2)
int button = 0;    // BOOT button (GPIO0)

void setup() {
  pinMode(pin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button) == LOW) {  // button pressed
    digitalWrite(pin, HIGH);         // LED on
  } else {
    digitalWrite(pin, LOW);          // LED off
  }
}
