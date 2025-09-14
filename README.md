# Small Clinic Management System

## Overview
This project implements a **Small Clinic Management System** in C++ using **OOP** principles. It manages **patients** (normal & chronic), **doctors**, and **appointments**, demonstrating **classes, inheritance, polymorphism, and encapsulation**.

---

## Features
- Register patients and doctors
- Schedule, complete, or cancel appointments
- Track patient medical history
- Specialized handling for chronic patients (frequent checkups)
- Display detailed info for patients and doctors

---

## Classes & Inheritance
- **Person** – base class: `name`, `id`, `age`, `gender`  
- **Patient** – inherits `Person`: address, insurance, next appointment, appointments  
- **ChronicPatient** – inherits `Patient`: condition type, last checkup, overrides `scheduleAppointment()`  
- **Doctor** – inherits `Person`: specialty, assigned appointments  
- **Appointment** – contains doctor/patient names, date, time, reason, status  

---

## How to Run
```bash
g++ -std=c++17 -o Hospital3 Hospital3.cpp
./Hospital3
Input from input.txt

Output to output.txt

Sample Input/Output
Input: 5 patients, 5 doctors, appointment histories
Output: patient info + appointment history, doctor info + assigned appointments

---

## LLM Usage
Used ChatGPT to brainstorm class structure, methods, and inheritance.
Prompts included:
"Suggest classes and methods for a small clinic management system in C++"
"How to model chronic patients using inheritance in C++"
