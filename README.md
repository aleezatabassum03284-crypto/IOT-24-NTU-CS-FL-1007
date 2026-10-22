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
  <img width="940" height="529" alt="image" src="https://github.com/user-attachments/assets/bd82d790-dfb8-45da-ac3f-a81573a028c5" />

  <img width="940" height="453" alt="image" src="https://github.com/user-attachments/assets/04700368-b309-42e8-8df3-1ae7dd133795" />

  
<img width="940" height="529" alt="image" src="https://github.com/user-attachments/assets/f901c3cb-ff71-4b53-83e7-f864eefc8d02" />


<img width="940" height="448" alt="image" src="https://github.com/user-attachments/assets/c4cd04f1-e111-494b-8064-cd8434dc626a" />

<img width="940" height="529" alt="image" src="https://github.com/user-attachments/assets/3da70638-87ba-443f-a458-18d3b64b2e4a" />


<img width="940" height="529" alt="image" src="https://github.com/user-attachments/assets/9daefd57-a294-4c90-9662-31e834da8f05" />


<img width="940" height="570" alt="image" src="https://github.com/user-attachments/assets/0be3de6c-4f52-4537-af50-e1a2b166257e" />


<img width="425" height="278" alt="image" src="https://github.com/user-attachments/assets/28ccece7-d40f-4499-bbeb-5a1440100a6c" />


<img width="940" height="533" alt="image" src="https://github.com/user-attachments/assets/1568cd19-e467-4d23-a4be-aeac122b295c" />


<img width="940" height="529" alt="image" src="https://github.com/user-attachments/assets/24105de9-3fae-4fa8-bd87-97333e49b92f" />


<img width="940" height="705" alt="image" src="https://github.com/user-attachments/assets/814c6a7c-585c-4cfa-8a21-6a0d199431d1" />


  <img width="1053" height="914" alt="WhatsApp Image 2026-10-22 at 4 03 29 PM" src="https://github.com/user-attachments/assets/89be83f2-9a57-400f-abc5-27e60ca7a32e" />

