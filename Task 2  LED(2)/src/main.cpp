#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int ledPin1 = 18;
const int ledPin2 = 19;

const int freq1 = 1000;
const int freq2 = 5000;
const int ledChannel1 = 0;
const int ledChannel2 = 1;
const int resolution = 8;

int dutyCycle1 = 0;
int dutyCycle2 = 0;
bool increasing1 = true;
bool increasing2 = true;

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  ledcSetup(ledChannel1, freq1, resolution);
  ledcSetup(ledChannel2, freq2, resolution);

  ledcAttachPin(ledPin1, ledChannel1);
  ledcAttachPin(ledPin2, ledChannel2);
}

void loop() {
  if (increasing1) {
    dutyCycle1 += 5;
    if (dutyCycle1 >= 255) increasing1 = false;
  } else {
    dutyCycle1 -= 5;
    if (dutyCycle1 <= 0) increasing1 = true;
  }

  if (increasing2) {
    dutyCycle2 += 10;
    if (dutyCycle2 >= 255) increasing2 = false;
  } else {
    dutyCycle2 -= 10;
    if (dutyCycle2 <= 0) increasing2 = true;
  }

  ledcWrite(ledChannel1, dutyCycle1);
  ledcWrite(ledChannel2, dutyCycle2);

  int percent1 = (dutyCycle1 * 100) / 255;
  int percent2 = (dutyCycle2 * 100) / 255;

  display.clearDisplay();
  
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("PWM MONITOR"));

  display.setCursor(0, 18);
  display.print(F("LED1: "));
  display.print(percent1);
  display.println(F("%"));

  display.setCursor(0, 28);
  display.print(F("F:"));
  display.print(freq1);
  display.println(F("Hz"));

  display.setCursor(0, 45);
  display.print(F("LED2: "));
  display.print(percent2);
  display.println(F("%"));

  display.setCursor(0, 55);
  display.print(F("F:"));
  display.print(freq2);
  display.println(F("Hz"));

  display.display();

  Serial.printf("LED1 Duty: %d%% | LED2 Duty: %d%%\n", percent1, percent2);

  delay(30);
}