# LED Sequence Activity - Complete Guide

## Project Overview

This activity demonstrates:
- **6 LEDs** wired in parallel with individual 220Ω current-limiting resistors
- **Arduino digital pins** (3-8) controlling each LED independently
- **For Loop** implementation for sequential LED control
- **Serial communication** for debugging and monitoring

## Hardware Assembly Instructions

### Components Needed
- 1× Arduino Uno (or compatible board)
- 6× LED (any color: Red, Yellow, Green, Blue)
- 6× 220Ω resistors (1/4W, carbon film or metal film)
- 1× Breadboard (optional but highly recommended)
- 1× USB cable (for programming and power)
- Jumper wires (22 AWG recommended)

### Step-by-Step Assembly

#### Step 1: Prepare the Breadboard
```
  Arduino Uno
  │
  └─[Power Rails]
     ├─ +5V (Red)
     └─ GND (Black)
```

#### Step 2: Connect Power to Breadboard
- Connect Arduino 5V pin → Breadboard positive rail (Red)
- Connect Arduino GND pin → Breadboard negative rail (Black)

#### Step 3: Install Each LED (Repeat 6 times)

For **LED 1** (Pin 3):
1. Insert 220Ω resistor anode leg into breadboard column connected to Arduino Pin 3
2. Insert LED anode (longer leg) into breadboard column with resistor
3. Insert LED cathode (shorter leg) into negative rail (GND)
4. **Verify polarity**: LED longer leg (+) toward resistor, shorter leg (-) toward GND

Repeat for LEDs 2-6:
- LED 2: Resistor from Pin 4
- LED 3: Resistor from Pin 5
- LED 4: Resistor from Pin 6
- LED 5: Resistor from Pin 7
- LED 6: Resistor from Pin 8

#### Step 4: Connect Arduino Digital Pins
```
Arduino Pin 3 ──[220Ω]──→ LED 1 Anode
Arduino Pin 4 ──[220Ω]──→ LED 2 Anode
Arduino Pin 5 ──[220Ω]──→ LED 3 Anode
Arduino Pin 6 ──[220Ω]──→ LED 4 Anode
Arduino Pin 7 ──[220Ω]──→ LED 5 Anode
Arduino Pin 8 ──[220Ω]──→ LED 6 Anode

All LED Cathodes → Arduino GND
```

#### Step 5: Upload Code
1. Connect Arduino to computer via USB cable
2. Open Arduino IDE
3. Select Tools → Board: Arduino Uno
4. Select Tools → Port: COM[X] (or /dev/ttyUSB[X] on Linux/Mac)
5. Open `led_sequence.ino`
6. Click Upload (→ button)
7. Wait for "Upload complete" message

### Breadboard Layout (Top View)

```
┌─────────────────────────────────────────────┐
│  +5V  GND   │  │  │  │  │  │  │  │  │  │   │
│   │    │    │  │  │  │  │  │  │  │  │  │   │
│   ├────┴────┤  │  │  │  │  │  │  │  │  │   │
│   │ Power   │  │  │  │  │  │  │  │  │  │   │
│   │ Rails   │  │  │  │  │  │  │  │  │  │   │
│   │────────│  │  │  │  │  │  │  │  │  │   │
│   │        │  │  │  │  │  │  │  │  │  │   │
│  R1  LED1  │  │  │  │  │  │  │  │  │  │   │
│  R2  LED2  │  │  │  │  │  │  │  │  │  │   │
│  R3  LED3  │  │  │  │  │  │  │  │  │  │   │
│  R4  LED4  │  │  │  │  │  │  │  │  │  │   │
│  R5  LED5  │  │  │  │  │  │  │  │  │  │   │
│  R6  LED6  │  │  │  │  │  │  │  │  │  │   │
└─────────────────────────────────────────────┘
```

## Testing & Verification

### Step 1: Check Connections
- Verify each resistor is connected to correct pin (3-8)
- Verify all LED cathodes connect to GND
- Verify Arduino is properly powered

### Step 2: Monitor Serial Output
1. Open Arduino IDE → Tools → Serial Monitor
2. Set baud rate to 9600
3. Verify output shows:
   ```
   LED Sequence Circuit Started!
   LED 1 ON
   LED 1 OFF
   LED 2 ON
   ...
   ```

### Step 3: Visual Verification
- Watch LEDs light up in sequence (1→2→3→4→5→6)
- Watch LEDs turn off in sequence (1→2→3→4→5→6)
- Cycle should repeat continuously

## Video Recording Instructions

To capture the working circuit:

### Using Smartphone
1. Set phone on tripod or stable surface
2. Position camera to clearly show all 6 LEDs
3. Ensure good lighting (not backlit)
4. Start recording
5. Let circuit run for 20-30 seconds (2-3 complete cycles)
6. Stop recording
7. Save video as `LED_SEQUENCE_DEMO.mp4`

### Using Computer Webcam (Optional)
- Use OBS Studio or similar to record screen + webcam
- Capture Arduino IDE serial monitor + LED action

### Video Checklist
- ✓ All 6 LEDs visible
- ✓ LEDs lighting sequentially and clearly
- ✓ LEDs turning off sequentially and clearly
- ✓ At least 2 complete cycles shown
- ✓ Good lighting and clear visibility

## Expected Behavior

### LED Sequence Timeline
```
0.0s  │ ● ○ ○ ○ ○ ○  (LED 1 ON)
0.5s  │ ○ ● ○ ○ ○ ○  (LED 2 ON)
1.0s  │ ○ ○ ● ○ ○ ○  (LED 3 ON)
1.5s  │ ○ ○ ○ ● ○ ○  (LED 4 ON)
2.0s  │ ○ ○ ○ ○ ● ○  (LED 5 ON)
2.5s  │ ○ ○ ○ ○ ○ ●  (LED 6 ON)
3.0s  │ ○ ○ ○ ○ ○ ○  (All OFF)
3.5s  │ ● ○ ○ ○ ○ ○  (LED 1 OFF phase)
4.0s  │ ○ ● ○ ○ ○ ○  (LED 2 OFF)
...
7.5s  │ ○ ○ ○ ○ ○ ○  (All OFF, pause)
8.0s  │ ● ○ ○ ○ ○ ○  (Cycle repeats)

Legend: ● = LED ON, ○ = LED OFF
```

## Troubleshooting

### LEDs Don't Light Up
1. Check LED polarity: longer leg (+) should be toward resistor
2. Verify pin connections (should be pins 3-8)
3. Upload code again
4. Check Arduino is powered (check USB connection)

### Some LEDs Don't Light
1. Test LED in known working circuit
2. Check resistor connection
3. Verify breadboard contact (push wires firmly)
4. Check Arduino pin status in serial monitor

### Intermittent Behavior
1. Check all jumper wire connections are secure
2. Verify breadboard contacts are clean
3. Try different resistors
4. Check USB cable quality

### Code Won't Upload
1. Select correct board: Tools → Board → Arduino Uno
2. Select correct COM port: Tools → Port
3. Install CH340 drivers if needed (common clone issue)
4. Try different USB port/cable

## For Loop Learning Points

### What the For Loop Does
```cpp
for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(DELAY_TIME);
}
```

This loop executes 6 times:
- **i = 0**: Turn on LED at pin 3
- **i = 1**: Turn on LED at pin 4
- **i = 2**: Turn on LED at pin 5
- **i = 3**: Turn on LED at pin 6
- **i = 4**: Turn on LED at pin 7
- **i = 5**: Turn on LED at pin 8

### Why Use Arrays with Loops?
**Without loop** (Bad):
```cpp
digitalWrite(LED_PINS[0], HIGH);
delay(500);
digitalWrite(LED_PINS[1], HIGH);
delay(500);
// ... repeat 6 times = 12 lines of code
```

**With loop** (Good):
```cpp
for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(500);
}
// = 3 lines of code, easily scalable
```

## Deliverables Checklist

- ✓ Circuit diagram (Mermaid format)
- ✓ Arduino code with For loop implementation
- ✓ Code documentation and explanation
- ✓ Assembly instructions
- ✓ Video of working circuit
- ✓ Serial monitor output screenshot

## Files Included

```
├── led_sequence.ino                 (Arduino code)
├── LED_CIRCUIT_DIAGRAM.md           (Mermaid diagram + pin config)
├── LED_SEQUENCE_CODE.md             (Full code explanation)
├── LED_SEQUENCE_README.md           (This file)
└── [VIDEO FILE]                     (Recorded demo)
```

## Future Enhancements

1. **Reverse direction** - Count from 6 down to 1
2. **Different patterns** - Alternating on/off, bounce effect
3. **Speed control** - Adjust DELAY_TIME variable
4. **More LEDs** - Extend to 8 or 10 LEDs
5. **Brightness control** - Use PWM (analogWrite) instead of digitalWrite
6. **User input** - Control speed with button or potentiometer

---
**Activity Completed By**: Dann
**Date**: 2026-04-23
**Course**: Robotics 1
