// LED Sequence Circuit - 6 LEDs controlled by For Loop
// Pins: 3, 4, 5, 6, 7, 8 connected to LEDs with 220Ω resistors

const int NUM_LEDS = 6;
const int LED_PINS[NUM_LEDS] = {3, 4, 5, 6, 7, 8};
const int DELAY_TIME = 500;  // 500ms between LED changes

void setup() {
  Serial.begin(9600);

  // Initialize all LED pins as outputs
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);  // Start all LEDs off
  }

  Serial.println("LED Sequence Circuit Started!");
}

void loop() {
  // Forward sequence: turn on LEDs one by one
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);  // Turn on LED
    Serial.print("LED ");
    Serial.print(i + 1);
    Serial.println(" ON");
    delay(DELAY_TIME);
  }

  // Turn off LEDs one by one
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);   // Turn off LED
    Serial.print("LED ");
    Serial.print(i + 1);
    Serial.println(" OFF");
    delay(DELAY_TIME);
  }

  delay(1000);  // 1 second pause before repeating
}
