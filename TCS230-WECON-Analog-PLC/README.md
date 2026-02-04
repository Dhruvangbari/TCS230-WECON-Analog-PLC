# TCS230 Color Sensor with WECON Analog PLC 🏭🎨  
From frequency signals to industrial control.

This project demonstrates a **complete industrial-style color detection system** using a **TCS230 color sensor**, **Arduino**, and a **WECON PLC with 0–10V analog input**.

The system follows real automation standards:
Sensor → Signal conditioning → Analog voltage → PLC logic → Outputs.

No shortcuts.  
No direct hacks.  
This is **how it’s done in actual factories**.

---

## 🧠 System Overview
The TCS230 outputs color information as a **frequency signal**.  
Arduino measures this frequency, processes the data, and converts it into a **PWM signal**.  
A PWM-to-0–10V converter generates an analog voltage suitable for PLC input.

The WECON PLC reads this voltage and executes **ladder logic** to classify colors and control outputs.

### Block Flow

---

## ⚡ Why This Project Is Industrial-Grade
- Uses **true 0–10V analog signaling**
- Proper **frequency-to-voltage conversion**
- PLC-side scaling and threshold logic
- Mandatory **common grounding**
- Calibration-driven design

This project bridges **Arduino prototyping** and **real PLC automation**.

---

## 🔧 Required Components
- TCS230 Color Sensor Module  
- Arduino Uno / Nano  
- PWM to 0–10V Converter (or DAC + Op-Amp)  
- WECON PLC with Analog Input (0–10V)  
- 5V DC Power Supply (Arduino + Sensor)  
- 24V DC Power Supply (PLC)  
- Shielded signal cables  
- Multimeter (mandatory for calibration)

---

## 🔌 Power Rules (CRITICAL)
- Arduino & TCS230 → **5V DC**
- WECON PLC → **24V DC**
- **Arduino GND and PLC COM (0V) MUST be connected together**

⚠️ Without common ground, analog readings will be unstable or incorrect.

---

## 🔗 Wiring Details

### TCS230 → Arduino
| TCS230 Pin | Arduino Pin |
|-----------|------------|
| VCC | 5V |
| GND | GND |
| OUT | D2 |
| S2  | D4 |
| S3  | D5 |

**Color Filter Selection**
- RED → S2 LOW, S3 LOW  
- GREEN → S2 HIGH, S3 HIGH  
- BLUE → S2 LOW, S3 HIGH  

---

### Arduino → PLC (Analog)
| Arduino | Converter | PLC |
|-------|----------|-----|
| D9 (PWM) | IN | — |
| — | OUT | AI0 |
| GND | GND | COM (0V) |

---

## 💻 Arduino Logic Summary
- Measures pulse frequency using `pulseIn()`
- Reads Red, Green, Blue sequentially
- Determines dominant color
- Maps frequency → PWM (0–255)
- Outputs PWM for analog conversion

The PLC receives **only clean voltage**, never raw frequency.

---

## ⚙️ PLC Analog Configuration
- Input Mode: **0–10V**
- Digital Scaling: **0–4000**

### Color Threshold Logic
| AI0 Value | Detected Color |
|---------|---------------|
| < 1300  | RED |
| 1300 – 2599 | GREEN |
| ≥ 2600 | BLUE |

Outputs:
- RED → Y0  
- GREEN → Y1  
- BLUE → Y2  

---

## 🧪 Calibration Procedure (MANDATORY)
1. Power ON system (wait 30 seconds)
2. Place **white object** → note AI0 value
3. Place **red, green, blue objects**
4. Adjust Arduino mapping if required
5. Lock PLC threshold values

Calibration is the difference between **working** and **reliable**.

---

## ❌ Common Mistakes
- Direct TCS230 → PLC connection ❌
- No common ground ❌
- Skipping PWM-to-voltage conversion ❌
- No multimeter during calibration ❌

---

## 🎯 Applications
- Color-based object sorting
- Conveyor belt classification
- Packaging line inspection
- PLC training & industrial labs

---

## 🧠 Author
**Dhruvang Bari**

