/*
  Homework-01 - Stage 1: OLED startup screen
  Shows a title, button status and a counter (0) on the SSD1306 OLED.
  OLED: I2C, SDA = GPIO 21, SCL = GPIO 22, address 0x3C
*/

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int SDA_PIN = 21;
const int SCL_PIN = 22;
const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const uint8_t OLED_ADDRESS = 0x3C;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

unsigned int pressCount = 0;

void drawScreen() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ESP32 Button Counter");

  display.setCursor(0, 20);
  display.println("Button: RELEASED");

  display.setTextSize(2);
  display.setCursor(0, 40);
  display.print("Count: ");
  display.println(pressCount);

  display.display();
}

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("OLED not found. Check wiring and address.");
    while (true) { delay(1000); }
  }

  drawScreen();
  Serial.println("System ready. Count = 0");
}

void loop() {
  // nothing yet
}
