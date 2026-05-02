# 🤖 Line Follower Robot with Obstacle Detection 🚗

This project implements a **PID-based Line Follower Robot** with an additional **Ultrasonic Sensor for obstacle detection**. The robot follows a path using IR sensors and adjusts its movement using PID control.

---

## 📑 Table of Contents
- [✨ Introduction](#-introduction)
- [🚀 Features](#-features)
- [🧰 Components Required](#-components-required)
- [🔌 Circuit Connections](#-circuit-connections)
- [⚙️ Installation](#-installation)
- [📊 Working Principle](#-working-principle)
- [🧠 Code Logic](#-code-logic)
- [🎥 Demo](#-demo)
- [📄 License](#-license)

---

## ✨ Introduction
A **Line Follower Robot** is an autonomous robot that follows a path (usually a black line on a white surface). This project uses **PID control** for smooth and accurate movement and includes **obstacle detection** using an ultrasonic sensor.

---

## 🚀 Features
- 📍 Line tracking using 5 IR sensors  
- 🎯 PID control (Kp, Ki, Kd tuning)  
- 🚧 Obstacle detection using ultrasonic sensor  
- ⚡ Real-time correction for smooth motion  
- 🔄 Automatic turning (left/right)  

---

## 🧰 Components Required
- Arduino UNO / ESP32  
- 5 IR Line Sensors  
- L298N Motor Driver  
- 2 DC Motors  
- Ultrasonic Sensor (HC-SR04)  
- Battery / Power Supply  
- Jumper Wires  

---

## 🔌 Circuit Connections

### IR Sensors
- Connected to pins: `6, 7, 8, 11, 12`

### Motor Driver (L298N)
- Motor Pins:
  - IN1 → Pin 2  
  - IN2 → Pin 3  
  - IN3 → Pin 4  
  - IN4 → Pin 5  
- Enable Pins:
  - ENA → Pin 9  
  - ENB → Pin 10

## 🔌 Circuit Diagram

[![Watch Demo](https://img.youtube.com/vi/VIDEO_ID/0.jpg)](https://youtube.com/watch?v=VIDEO_ID)

### Ultrasonic Sensor
- Trig → A1  
- Echo → A2  

---

## ⚙️ Installation
```bash
git clone https://github.com/danielabishek585/Final-Year-Project.git
