# ESP32 Music Reactive LEDs

A simple ESP32-based music-reactive LED system that detects sound intensity using a KY-038 sound sensor and visualizes the detected audio amplitude using a 10-level LED bar.

---

## Project Overview

This project uses an ESP32 and a KY-038 sound sensor to create a real-time music-reactive LED display. The sound sensor continuously measures the variation in sound levels, and the ESP32 converts the detected amplitude into a visual LED level.

The louder the sound or music, the more LEDs light up.

### Features

* Real-time sound amplitude detection
* 10-level LED visualizer
* Analog sound sensing using KY-038
* ESP32-based control
* Simple and responsive LED visualization
* Adjustable sound sensitivity through software

---

## Hardware

| Component    | Specification              |         Qty | Purpose                                           |
| ------------ | -------------------------- | ----------: | ------------------------------------------------- |
| ESP32        | ESP32 Development Board    |           1 | Reads sound levels and controls the LEDs          |
| Sound Sensor | KY-038                     |           1 | Detects sound intensity through its analog output |
| LEDs         | Standard LEDs              |          10 | Visualize the detected sound amplitude            |
| Resistors    | Current-limiting resistors |          10 | Protect the LEDs from excessive current           |
| Jumper Wires | —                          | As required | Circuit connections                               |
| Breadboard   | —                          |           1 | Prototyping                                       |

---

## Hardware Connections

### KY-038 Sound Sensor

| KY-038 Pin | ESP32   |
| ---------- | ------- |
| AO         | GPIO 34 |
| GND        | GND     |
| VCC        | 3.3V    |

### LED Connections

| LED    | ESP32 GPIO |
| ------ | ---------- |
| LED 1  | GPIO 12    |
| LED 2  | GPIO 13    |
| LED 3  | GPIO 14    |
| LED 4  | GPIO 27    |
| LED 5  | GPIO 4     |
| LED 6  | GPIO 5     |
| LED 7  | GPIO 25    |
| LED 8  | GPIO 21    |
| LED 9  | GPIO 22    |
| LED 10 | GPIO 23    |

> Each LED should be connected with an appropriate current-limiting resistor.

---

## How It Works

The KY-038 sensor provides an analog signal through its `AO` pin. The ESP32 samples this signal continuously for a short period of time.

During each sampling window:

1. The highest analog value is recorded.
2. The lowest analog value is recorded.
3. The difference between the maximum and minimum values is calculated.

```text
Amplitude = Maximum Signal - Minimum Signal
```

This amplitude represents the approximate intensity of the detected sound.

The amplitude is then mapped to a value between 0 and 10:

```text
Sound Amplitude
      ↓
ESP32 Analog Sampling
      ↓
Maximum - Minimum
      ↓
Amplitude Calculation
      ↓
Map to LED Level (0–10)
      ↓
Light Up LEDs
```

For example:

```text
Low Sound      → 0–2 LEDs
Medium Sound   → 3–6 LEDs
Loud Sound     → 7–10 LEDs
```

---

## Software

### Software Stack

* **Programming Language:** C++
* **Development Environment:** Arduino IDE
* **Microcontroller Framework:** Arduino-ESP32
* **Input:** Analog sound signal
* **Output:** Digital LED control

### Main Algorithm

The program samples the sound sensor for 50 milliseconds and calculates the difference between the highest and lowest detected values.

```cpp
int amplitude = signalMax - signalMin;
```

The amplitude is then converted into a 10-level LED scale:

```cpp
int level = map(amplitude, 0, 600, 0, 10);
```

The LEDs are then controlled based on the calculated level.

---

## Quick Start

### Requirements

* Arduino IDE
* ESP32 board package
* ESP32 development board
* KY-038 sound sensor
* 10 LEDs
* Current-limiting resistors

### Setup

1. Connect the KY-038 analog output to **GPIO 34**.
2. Connect the LEDs to the specified GPIO pins.
3. Connect the circuit grounds together.
4. Open the code in Arduino IDE.
5. Select the correct ESP32 board and COM port.
6. Upload the code.
7. Open the Serial Monitor at **115200 baud** to observe the detected sound amplitude.
8. Play music or create sound near the sensor and observe the LED visualization.

---

## Project Structure

```text
Music_Reactive_LEDs/
│
├── Music_Reactive_LEDs.ino    # Main Arduino sketch
│
├── images/                    # Project images
│
├── docs/                      # Documentation
│
└── README.md                  # Project documentation
```

---

## Future Improvements

* Add WS2812B addressable LEDs for RGB effects
* Create different lighting patterns based on sound intensity
* Add frequency-based visualization using FFT
* Separate bass, mid, and treble responses
* Add smooth LED transitions
* Add adjustable sensitivity control
* Create a circular or wearable LED design
* Add multiple visualization modes
* Synchronize the LEDs with music beats

---

## License

This project is open-source and can be modified and improved for personal and educational use.

---

## Support

If you found this project interesting, consider ⭐ starring the repository and experimenting with your own music-reactive LED patterns.
