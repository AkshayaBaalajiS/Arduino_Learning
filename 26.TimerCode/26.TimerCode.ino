hw_timer_t * timer = NULL;   // timer object
volatile bool ledState = false;   // shared variable for ISR

void IRAM_ATTR onTimer() {
    ledState = !ledState;    // toggle LED state
}

void setup() {
    pinMode(2, OUTPUT);

    // Step 1: Create timer
    timer = timerBegin(
        0,      // timer number (0–3)
        80,     // prescaler → 80MHz / 80 = 1MHz → 1 tick = 1 microsecond
        true    // count up
    );

    // Step 2: Attach interrupt function
    timerAttachInterrupt(
        timer,
        &onTimer,
        true      // edge triggered
    );

    // Step 3: Set alarm (period)
    timerAlarmWrite(
        timer,
        5000000,  // 1,000,000 microseconds = 1 second
        true      // autoreload after interrupt
    );

    // Step 4: Start timer
    timerAlarmEnable(timer);
}

void loop() {
    digitalWrite(2, ledState); // update LED based on ISR
}
