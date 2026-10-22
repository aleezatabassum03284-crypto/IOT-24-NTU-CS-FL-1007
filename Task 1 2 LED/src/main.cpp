#include <Arduino.h>

// LED pins define karein
const int ledPin1 = 18; // LED 1 GPIO pin
const int ledPin2 = 19; // LED 2 GPIO pin

// PWM properties
const int freq1 = 1000;  // LED 1 frequency (1 kHz)
const int freq2 = 5000;  // LED 2 frequency (5 kHz)
const int ledChannel1 = 0;
const int ledChannel2 = 1;
const int resolution = 8; // 8-bit resolution (0 - 255)

// Global variables duty cycle track karne ke liye (Task 2 mein OLED par dikhane ke liye kaam aayenge)
int dutyCycle1 = 0;
int dutyCycle2 = 0;
bool increasing1 = true;
bool increasing2 = true;

void setup() {
  Serial.begin(115200);

  // LED channels configure karein
  ledcSetup(ledChannel1, freq1, resolution);
  ledcSetup(ledChannel2, freq2, resolution);

  // Pins ko LED channels ke sath attach karein
  ledcAttachPin(ledPin1, ledChannel1);
  ledcAttachPin(ledPin2, ledChannel2);
}

void loop() {
  // LED 1 fading logic
  if (increasing1) {
    dutyCycle1 += 5;
    if (dutyCycle1 >= 255) increasing1 = false;
  } else {
    dutyCycle1 -= 5;
    if (dutyCycle1 <= 0) increasing1 = true;
  }

  // LED 2 fading logic (alag speed ya pattern bhi rakh sakte hain)
  if (increasing2) {
    dutyCycle2 += 10;
    if (dutyCycle2 >= 255) increasing2 = false;
  } else {
    dutyCycle2 -= 10;
    if (dutyCycle2 <= 0) increasing2 = true;
  }

  // PWM values LEDs par apply karein
  ledcWrite(ledChannel1, dutyCycle1);
  ledcWrite(ledChannel2, dutyCycle2);

  // Serial Monitor par values print karke check karein
  Serial.printf("LED1 Duty: %d%% | LED2 Duty: %d%%\n", (dutyCycle1 * 100) / 255, (dutyCycle2 * 100) / 255);

  delay(30); // Fading speed control karne ke liye delay
}