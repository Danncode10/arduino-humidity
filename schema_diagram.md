# Arduino DHT11 Humidity Sensor — Circuit Diagram
> Using the **DHT11 MODULE** (blue PCB, 3 pins) — 10kΩ resistor is already built in.

---

## Where is D2 on Arduino UNO?

```mermaid
graph TD
    subgraph "Arduino UNO — Digital Pin Row (RIGHT SIDE)"
        direction TB
        D13["D13"]
        D12["D12"]
        D11["D11 ~"]
        D10["D10 ~"]
        D9["D9 ~"]
        D8["D8"]
        D7["D7"]
        D6["D6 ~"]
        D5["D5 ~"]
        D4["D4"]
        D3["D3 ~"]
        D2["⭐ D2  ← CONNECT HERE"]
        D1["D1 TX"]
        D0["D0 RX"]
    end

    D2 -- "🟡 YELLOW wire to DHT11 Signal pin" --> DHT["DHT11 Module · Signal"]
```

> **D2 is the 3rd pin from the bottom** of the digital pin row, just above D1 TX and D0 RX.

---

## Wiring Schematic

```mermaid
graph TD
    UNO["🟦 Arduino UNO"]

    PIN5V["📌 5V"]
    PINGND["📌 GND"]
    PIND2["📌 D2  (Digital Pin 2)"]

    UNO --> PIN5V
    UNO --> PINGND
    UNO --> PIND2

    DHT["🟨 DHT11 MODULE\n(3-pin, resistor built-in)"]
    S["Signal"]
    V["VCC (+)"]
    G["Ground (-)"]

    PIN5V  -- "🔴 RED wire"    --> V
    PINGND -- "⚫ BLACK wire"  --> G
    PIND2  -- "🟡 YELLOW wire" --> S

    V --> DHT
    S --> DHT
    G --> DHT
```

---

## Pin Reference Table

```mermaid
graph LR
    subgraph "Arduino UNO"
        A1["5V"]
        A2["GND"]
        A3["D2"]
    end

    subgraph "DHT11 MODULE (3-pin)"
        D1["Signal"]
        D2["VCC (+)"]
        D3["Ground (-)"]
    end

    A1 -- "🔴 RED"    --> D2
    A2 -- "⚫ BLACK"  --> D3
    A3 -- "🟡 YELLOW" --> D1
```

---

## Power Flow

```mermaid
flowchart LR
    USB["💻 USB / Power\n5V"] --> UNO["Arduino UNO"]
    UNO -- "5V → VCC+" --> DHT11["DHT11 Module"]
    UNO -- "GND" --> DHT11
    DHT11 -- "Signal → D2" --> UNO
    UNO -- "Serial 9600 baud" --> PC["📟 Serial Monitor\nHumidity % · Temp °C"]
```

---

## Component Checklist

```mermaid
graph TD
    A["✅ Arduino UNO R3"]
    B["✅ DHT11 MODULE — 3-pin blue PCB\n(resistor already on board — no extras needed)"]
    C["✅ Breadboard (optional, or wire directly)"]
    D["✅ Jumper Wires: 🔴 RED · ⚫ BLACK · 🟡 YELLOW"]
    E["✅ USB Cable (Type-B)"]

    A --- B --- C --- D --- E
```

---

## Serial Monitor Output (expected)

```mermaid
sequenceDiagram
    participant Arduino
    participant DHT11 as DHT11 Module
    participant Monitor as Serial Monitor

    loop Every 2 seconds
        Arduino->>DHT11: Request reading
        DHT11-->>Arduino: Humidity + Temperature
        Arduino-->>Monitor: Humidity:    55.00 %
        Arduino-->>Monitor: Temperature: 27.00 °C
        Arduino-->>Monitor: ----------------------------
    end
```
