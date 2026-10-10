
# 🤖 ROBY - Simple Version

**ROBY** is a simple, expressive desktop robot companion built with an **ESP32** and an **OLED display** over I2C. Designed as a hands-on project to learn microcontrollers, display protocols, sound synthesis, and state handling, ROBY responds to physical button interactions with facial expressions and audio cues—and even features a built-in **25-minute Pomodoro timer**!

---

## ✨ Features

- **Expressive OLED Eyes**: Animated emotions (Happy, Angry, Tired, Normal) using the `FluxGarage_RoboEyes` library.
- **Interactive Button Control**:
  - **Single Click**: Trigger "Angry" reaction with sound feedback.
  - **Double Click**: Trigger "Happy" reaction with a cheerful tone sequence.
- **Pomodoro Timer**: Dedicated button to launch a 25-minute productivity countdown.
- **Sound Effects**: Piezo buzzer tones calibrated for different expressions and state changes.

---

## 🛠️ Hardware Components

| Component | Description |
| :--- | :--- |
| **ESP32 NodeMCU 32S** | Main Microcontroller |
| **0.96" OLED Display** | I2C SSD1306 (128x64 resolution) |
| **Piezo Buzzer** | Audio feedback / tone generator |
| **Push Button (x2)** | 1x Interaction / 1x Pomodoro trigger |
| **Jumper Wires & Breadboard** | Interconnections |

---

## 🔌 Wiring & Pinout

| Component | ESP32 Pin | Note |
| :--- | :--- | :--- |
| **OLED VCC** | 3.3V | Power |
| **OLED GND** | GND | Ground |
| **OLED SDA** | GPIO 21 | I2C Data |
| **OLED SCL** | GPIO 22 | I2C Clock |
| **Buzzer (+)** | GPIO 33 | PWM Signal |
| **Buzzer (-)** | GND | Ground |
| **Push Button 1 (1st pin)** | GPIO 14 | Internal Pull-up |
| **Push Button 1 (2nd pin)** | GND | Ground |
| **Push Button 2 (1st pin)** | GPIO 17 | Internal Pull-up |
| **Push Button 2 (2nd pin)** | GND | Ground |

---

## 📚 Required Libraries

Make sure you have installed the following libraries in Arduino IDE before uploading:

1. **Adafruit_SSD1306**
2. **Adafruit_GFX**
3. **FluxGarage_RoboEyes**

---

## 🚀 Getting Started

1. Connect the components according to the pinout table above.
2. Open the `.ino` sketch file in the Arduino IDE.
3. Select **ESP32 Dev Module** under `Tools -> Board`.
4. Ensure all required libraries are installed.
5. Compile and flash the code to your ESP32.

---

## 💡 Future Roadmap

- [ ] Transition timer from `delay()` to non-blocking `millis()` for smoother animations.
- [ ] Add servo motors for physical head movement.
- [ ] Add battery charging module (TP4056) for portability.

---

*Created for learning and experimenting with ESP32 & I2C OLED displays.*
