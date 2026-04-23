# LED Sequence Code - Full Implementation

## Arduino Sketch: led_sequence.ino

```cpp
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
```

## Code Explanation

### Constants (Lines 4-6)
```
NUM_LEDS = 6          → Total number of LEDs
LED_PINS[6]           → Array storing pin numbers (3,4,5,6,7,8)
DELAY_TIME = 500      → Delay between each LED (milliseconds)
```

### Setup Function (Lines 8-17)
- Initializes serial communication at 9600 baud
- **For Loop**: Configures all 6 pins as OUTPUT
- Sets all pins to LOW (0V) initially, turning all LEDs OFF
- Prints startup message to serial monitor

### Loop Function (Lines 19-40)

#### Part 1: Turn ON Sequence (Lines 21-28)
```cpp
for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);  // Set pin to 5V
    // Serial output for debugging
    delay(DELAY_TIME);  // Wait 500ms
}
```
- Uses **FOR LOOP** to iterate through each LED (i = 0 to 5)
- Sets each pin to HIGH (5V), turning on the LED
- Waits 500ms before moving to next LED
- Creates a "chasing" effect: LED1 → LED2 → LED3 → LED4 → LED5 → LED6

#### Part 2: Turn OFF Sequence (Lines 30-37)
```cpp
for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);   // Set pin to 0V
    // Serial output for debugging
    delay(DELAY_TIME);  // Wait 500ms
}
```
- Uses **FOR LOOP** again to iterate through each LED
- Sets each pin to LOW (0V), turning off the LED
- Waits 500ms before moving to next LED
- Creates reverse effect: LED1 → LED2 → LED3 → LED4 → LED5 → LED6 (turning OFF)

#### Part 3: Pause (Line 39)
```cpp
delay(1000);  // Rest for 1 second before repeating
```

## Execution Timeline

```
Time (s)  │ Event
──────────┼─────────────────────────────
0.0       │ LED 1 ON
0.5       │ LED 1 OFF, LED 2 ON
1.0       │ LED 2 OFF, LED 3 ON
1.5       │ LED 3 OFF, LED 4 ON
2.0       │ LED 4 OFF, LED 5 ON
2.5       │ LED 5 OFF, LED 6 ON
3.0       │ LED 6 OFF
3.5       │ [Turn OFF Sequence starts]
...       │
7.0       │ [Pause 1 second]
8.0       │ [Cycle repeats]
```

## Serial Monitor Output

```
LED Sequence Circuit Started!
LED 1 ON
LED 1 OFF
LED 2 ON
LED 2 OFF
LED 3 ON
...
```

## How the For Loop Works

### Syntax
```cpp
for (initialization; condition; increment) {
    // code to execute
}
```

### Our Implementation
```cpp
for (int i = 0; i < NUM_LEDS; i++)
```
- **Initialization**: `int i = 0` → Start at first LED (index 0)
- **Condition**: `i < NUM_LEDS` → Continue while i is less than 6
- **Increment**: `i++` → Move to next LED after each iteration
- **Body**: Turn ON/OFF the LED at position `i`

## Customization Options

### Change LED Speed
```cpp
const int DELAY_TIME = 250;  // Faster (250ms)
const int DELAY_TIME = 1000; // Slower (1000ms = 1 second)
```

### Change Pause Between Cycles
```cpp
delay(500);  // 0.5 second pause
delay(2000); // 2 second pause
```

### Add More LEDs
```cpp
const int NUM_LEDS = 8;  // 8 LEDs instead of 6
const int LED_PINS[NUM_LEDS] = {3, 4, 5, 6, 7, 8, 9, 10};
```

### Reverse the Direction
```cpp
for (int i = NUM_LEDS - 1; i >= 0; i--) {  // Count backwards
    digitalWrite(LED_PINS[i], HIGH);
    delay(DELAY_TIME);
}
```
