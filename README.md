#  Smart Pill Dispenser

An Arduino-based Smart Pill Dispenser designed to automate medication reminders and pill dispensing for elderly patients and individuals who require timely medication. The project demonstrates the use of embedded systems to improve medication adherence through real-time scheduling and automated dispensing.

---

##  Overview

Missing medication doses can lead to serious health complications. This project provides a simple and affordable automation solution using Arduino and peripheral modules to remind users and dispense pills at scheduled times.

The system uses a Real-Time Clock (RTC) module to keep accurate time, an LCD to display reminders, a buzzer for alerts, and a servo motor to dispense medication automatically.

---

##  Features

* Automated pill dispensing
* Real-time medication scheduling using RTC
* LCD-based reminder display
* Audio alerts using a buzzer
* Servo motor-controlled dispensing mechanism
* User-friendly embedded system prototype
* Low-cost healthcare automation solution

---

##  Hardware Components

| Component         | Purpose                     |
| ----------------- | --------------------------- |
| Arduino Uno       | Main microcontroller        |
| DS3231 RTC Module | Real-time scheduling        |
| SG90 Servo Motor  | Dispenses pills             |
| 16×2 LCD Display  | Displays reminders and time |
| I2C Module        | LCD communication           |
| Buzzer            | Audio notification          |
| Breadboard        | Circuit prototyping         |
| Jumper Wires      | Hardware connections        |
| Power Supply      | System power                |

---

##  Working Principle

1. The RTC module continuously tracks the current time.
2. When a scheduled medication time is reached:

   * The LCD displays a reminder message.
   * The buzzer alerts the user.
   * The servo motor rotates to dispense a pill.
3. After dispensing, the servo returns to its initial position, preparing the system for the next scheduled dose.

---

## Project Structure

```text
Smart-Pill-Dispenser/
│── pilldispenser.ino
│── README.md
│── Project_Report.docx
│── demo.mp4
│── circuit_diagram.png
```

---

##  How to Run

1. Open `pilldispenser.ino` using the Arduino IDE.
2. Install the required Arduino libraries (if applicable).
3. Connect the hardware components according to the circuit diagram.
4. Upload the sketch to the Arduino Uno.
5. Set the RTC module with the correct date and time.
6. Power the system and observe automatic reminders and pill dispensing.

---

##  Demonstration

* Demo video: `demo.mp4`
* Circuit diagram: `circuit_diagram.png`

---

## Learning Outcomes

This project helped me gain practical experience in:

* Arduino programming
* Embedded systems development
* RTC module interfacing
* Servo motor control
* Hardware prototyping
* Circuit integration and debugging
* Embedded automation logic

---

##  Applications

* Elderly patient care
* Medication reminder systems
* Home healthcare automation
* Smart healthcare prototypes

---

##  Future Improvements

* Mobile application integration
* Wi-Fi/Bluetooth connectivity
* SMS or notification alerts
* Multiple medication compartments
* Battery backup
* Cloud-based medication logging

---

## 📄 License

This project is intended for educational and learning purposes.
