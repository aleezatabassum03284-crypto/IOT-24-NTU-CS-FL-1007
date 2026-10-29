#include <Arduino.h>

// Define LED pins
const int ledPin1 = 18;
const int ledPin2 = 19;

// PWM properties
const int freq1 = 1000;   // 1 kHz for LED 1
const int freq2 = 5000;   // 5 kHz for LED 2
const int ledChannel1 = 0;
const int ledChannel2 = 1;
const int resolution = 8; // 8-bit resolution (0-255)

void setup() {
  // Configure LED PWM functionalities
  ledcSetup(ledChannel1, freq1, resolution);
  ledcSetup(ledChannel2, freq2, resolution);

  // Attach the channels to the pins
  ledcAttachPin(ledPin1, ledChannel1);
  ledcAttachPin(ledPin2, ledChannel2);
}

void loop() {
  // Fade LED 1 and LED 2 smoothly
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(ledChannel1, dutyCycle);
    ledcWrite(ledChannel2, 255 - dutyCycle);
    delay(15);
  }

  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(ledChannel1, dutyCycle);
    ledcWrite(ledChannel2, 255 - dutyCycle);
    delay(15);
  }
}
