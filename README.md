# ESP32 Music Reactive WS2812 LEDs

An ESP32-based music-reactive LED system that detects sound intensity using a KY-038 sound sensor and visualizes the detected audio amplitude using individually addressable WS2812 RGB LEDs.

---

## Project Overview

This project uses an ESP32, a KY-038 sound sensor, and a WS2812 LED strip to create a real-time music-reactive lighting system.

The KY-038 detects changes in sound intensity. The ESP32 processes the analog signal and converts the detected sound amplitude into a visual LED level. The number of illuminated LEDs changes according to the intensity of the sound or music.

Unlike traditional LEDs, WS2812 LEDs are individually addressable, allowing each LED to be controlled independently and enabling future RGB lighting effects.

### Features

* Real-time sound amplitude detection
* Music-reactive LED visualization
* Individually addressable WS2812 RGB LEDs
* Single-wire LED data control
* Adjustable sound sensitivity through software
* ESP32-based control
* Expandable to multiple lighting effects and patterns

---

## Hardware

| Component        | Specification             |         Qty | Purpose                                    |
| ---------------- | ------------------------- | ----------: | ------------------------------------------ |
| ESP32            | ESP32 Development Board   |           1 | Processes sound data and controls the LEDs |
| Sound Sensor     | KY-038                    |           1 | Detects sound intensity                    |
| Addressable LEDs | WS2812 / WS2812B          |  10 or more | Displays the sound-reactive visual output  |
| Resistor         | 330Ω–470Ω                 |           1 | Protects the WS2812 data line              |
| Capacitor        | 1000µF recommended        |           1 | Helps stabilize the LED power supply       |
| Power Supply     | 5V suitable for LED count |           1 | Powers the WS2812 LEDs                     |
| Jumper Wires     | —                         | As required | Circuit connections                        |

---

## Hardware Connections

### KY-038 Sound Sensor

| KY-038 Pin | ESP32   |
| ---------- | ------- |
| AO         | GPIO 34 |
| GND        | GND     |
| VCC        | 3.3V    |

### WS2812 LED Strip

| WS2812 Pin | Connection      |
| ---------- | --------------- |
| 5V / VCC   | 5V Power Supply |
| GND        | Common GND      |
| DIN        | ESP32 GPIO 5    |

> The GPIO pin used for the WS2812 data signal can be changed in the code.

### Basic Connection

```text
             ┌──────────────────┐
             │      ESP32       │
             │                  │
             │ GPIO 34 ◄────────┤ AO
             │                  │  KY-038
             │ GPIO 5 ──────────┤ DIN
             │                  │  WS2812
             │ GND ─────────────┼──── GND
             └──────────────────┘
                       │
                       │
                  5V Power
                       │
                  WS2812 LEDs
```

> For larger LED strips, power the WS2812 LEDs from a suitable external 5V power supply. Make sure the ESP32 and WS2812 power supply share a common ground.

---

## How It Works

The KY-038 sensor provides an analog signal through its `AO` pin. The ESP32 continuously samples this signal for a short period of time.

During each sampling window:

1. The highest analog value is recorded.
2. The lowest analog value is recorded.
3. The difference between the maximum and minimum values is calculated.

```text
Amplitude = Maximum Signal - Minimum Signal
```

The calculated amplitude is then mapped to the number of WS2812 LEDs that should be illuminated.

```text
Sound Amplitude
      ↓
ESP32 Analog Sampling
      ↓
Maximum - Minimum
      ↓
Amplitude Calculation
      ↓
Map to LED Level
      ↓
Illuminate WS2812 LEDs
```

For example:

```text
Low Sound      → Few LEDs ON
Medium Sound   → More LEDs ON
Loud Sound     → Most LEDs ON
```

---

## LED Visualization

The WS2812 LEDs can be controlled individually, allowing the system to display a sound-level bar.

```text
Low Amplitude:

● ○ ○ ○ ○ ○ ○ ○ ○ ○

Medium Amplitude:

● ● ● ● ● ○ ○ ○ ○ ○

High Amplitude:

● ● ● ● ● ● ● ● ● ●
```

Because WS2812 LEDs are RGB addressable, different colors and lighting effects can also be added in future versions.

---

## Software

### Software Stack

* **Programming Language:** C++
* **Development Environment:** Arduino IDE
* **Microcontroller:** ESP32
* **Sound Input:** KY-038 Analog Output
* **LED Output:** WS2812 / WS2812B Addressable LEDs

### Required Library

The project can be controlled using an addressable LED library such as:

* `Adafruit_NeoPixel`
* `FastLED`

The library allows the ESP32 to individually control each WS2812 LED using a single data pin.

---

## Main Algorithm

The sound sensor is sampled for 50 milliseconds.

```cpp
int amplitude = signalMax - signalMin;
```

The amplitude is then converted into a corresponding LED level:

```cpp
int level = map(amplitude, 0, 600, 0, NUM_LEDS);
```

The WS2812 LEDs are then updated based on the calculated sound level.

```text
Sound Amplitude
      ↓
     250
      ↓
    Level 4
      ↓
LED 1 ─ ON
LED 2 ─ ON
LED 3 ─ ON
LED 4 ─ ON
LED 5 ─ OFF
...
```

---

## Quick Start

### Requirements

* Arduino IDE
* ESP32 board package
* ESP32 development board
* KY-038 sound sensor
* WS2812 or WS2812B LED strip/ring
* 5V power supply
* 330Ω–470Ω resistor
* Optional 1000µF capacitor

### Setup

1. Connect the KY-038 analog output to **GPIO 34**.
2. Connect the WS2812 `DIN` pin to the selected ESP32 GPIO.
3. Connect the WS2812 power supply to **5V and GND**.
4. Connect the ESP32 ground to the WS2812 ground.
5. Install the required WS2812 LED library.
6. Upload the program to the ESP32.
7. Open the Serial Monitor at **115200 baud**.
8. Play music or create sound near the KY-038 sensor.
9. Watch the WS2812 LEDs react to the detected sound amplitude.

---

## Project Structure

```text
Music_Reactive_WS2812/
│
├── Music_Reactive_WS2812.ino    # Main Arduino sketch
│
├── images/                       # Project images
│
├── docs/                         # Documentation
│
└── README.md                     # Project documentation
```

---

## Future Improvements

* Add multiple RGB color modes
* Create smooth transitions between LED levels
* Add beat detection
* Add frequency-based visualization using FFT
* Separate bass, mid, and treble frequencies
* Add gradient lighting effects
* Add different animation modes
* Create a wearable music-reactive LED system
* Add a microphone with better audio sensitivity
* Add Bluetooth or Wi-Fi control for changing LED modes
* Add a mobile application for controlling brightness and colors

---

## License

This project is open-source and can be modified and improved for personal and educational use.

---

## Support

If you found this project interesting, consider ⭐ starring the repository and experimenting with your own WS2812 music-reactive lighting effects.
