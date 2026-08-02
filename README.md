# Stadxn (ស្តាដ-អ៊ិច-អ៊ិន) ⚡
> **An Offline-First Embedded NFC Attendance System Built on Hard Mode.**

![License](https://img.shields.io/badge/License-MIT-blue.svg)
![Platform](https://img.shields.io/badge/Platform-ESP32-green.svg)
![Status](https://img.shields.io/badge/Build-In--Progress-orange.svg)

---

## 🌌 About The Project

**Stadxn** is a professional, offline-first attendance management hardware solution designed to replace traditional paper-based signatures. Built completely from scratch on the ESP32 microcontroller, **Stadxn** eliminates reliance on continuous internet connectivity while ensuring high-precision, real-time logging via NFC and RTC.

### 🧬 Brand Identity & Philosophy
The name **Stadxn** encapsulates the soul and architecture of the project:
* **St** (Staff / Student): Target ecosystem users.
* **a** (Attendance): The core functional objective.
* **d** (Sad / Struggle): The fuel—transmuting past challenges and sacrifices into creation.
* **xn** ($x^n$ / Exponential): Unlimited potential, scaling capacity, and unstoppable growth.

---

## 🛠️ Hardware Architecture (BOM)

| Component | Interface | Description |
| :--- | :--- | :--- |
| **ESP32 DevKit V1 (30-Pin)** | MCU | Core Controller |
| **PN532 NFC Module** | I2C (GPIO 21/22) | Card Reader (UID Logging) |
| **DS3231 RTC Module** | I2C (GPIO 21/22) | Real-Time Timestamping |
| **OLED Display (SSD1306)** | I2C (GPIO 21/22) | Visual User Feedback |
| **MicroSD Card Module** | SPI (GPIO 5/18/19/23) | Offline Log Storage |
| **Active Buzzer** | GPIO 13 | Audio Feedback |

---

## 🚀 Features

- [x] **Offline-First:** Full functionality without Wi-Fi/Internet dependencies.
- [x] **Multi-Bus I2C Sharing:** Efficient bus multiplexing for NFC, RTC, and Display.
- [ ] **Data Security:** UID verification to prevent proxy loggings. *(In Progress)*
- [ ] **Power Efficiency:** Optimized deep-sleep and power handling. *(Planned)*

---

## 💻 Firmware Setup & Installation

1. **Clone the Repository:**
   ```bash
   git clone [https://github.com/YourUsername/Stadxn.git](https://github.com/YourUsername/Stadxn.git)
