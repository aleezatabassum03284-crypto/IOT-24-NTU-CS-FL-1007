ESP32 Dual-LED PWM Control with Live OLED Monitoring
This project demonstrates dual-LED PWM fading control using an ESP32 microcontroller, along with real-time parameter monitoring on an SSD1306 OLED display.
Project Overview
  Microcontroller: ESP32 DevKit v1
  Task 1: Dual-LED independent PWM control (LED 1 at 1000 Hz, LED 2 at 5000 Hz) with 8-bit resolution.
  Task 2: Real-time live monitoring of duty-cycle percentages and frequencies on an SSD1306 I2C OLED display.
Hardware Wiring Description
   LED 1: Connected to ESP32 pin GPIO 18 through a 220-ohm current-limiting resistor.
   LED 2: Connected to ESP32 pin GPIO 19 through a 220-ohm current-limiting resistor.
   SSD1306 I2C OLED Display:
      VCC connected to ESP32 3V3   
      GND connected to ESP32 GND
      SDA connected to ESP32 GPIO 21
      SCL connected to ESP32 GPIO 22
PWM Frequencies & Duty-Cycle Control      
  LED 1 Frequency: Set to 1000 Hz (1 kHz) with dynamic fading logic.   
  LED 2 Frequency: Set to 5000 Hz (5 kHz) with independent fading speeds.
  Resolution: Configured at 8-bit (duty cycle ranging from 0 to 255).
OLED Output Features  
  Displays real-time brightness/duty-cycle percentages for both LEDs dynamically.
  Shows configured frequencies (1000Hz and 5000Hz) simultaneously on screen
  Refreshes data smoothly without lag during the fading loop.
  <img width="1053" height="914" alt="WhatsApp Image 2026-10-22 at 4 03 29 PM" src="https://github.com/user-attachments/assets/89be83f2-9a57-400f-abc5-27e60ca7a32e" />

