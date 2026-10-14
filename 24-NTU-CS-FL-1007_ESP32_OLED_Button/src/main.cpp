/*
  Homework-01: ESP32 OLED status display with a debounced push button
  - OLED: SSD1306 128x64 over I2C (SDA = GPIO 21, SCL = GPIO 22, address 0x3C)
  - Button: GPIO 18 to GND, INPUT_PULLUP (pressed = LOW)
  - Debounce: non-blocking, uses millis() (no long delay)
*/

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------- Pin and display settings ----------
const int BUTTON_PIN = 18;
const int SDA_PIN = 21;
const int SCL_PIN = 22;

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const uint8_t OLED_ADDRESS = 0x3C;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ---------- Debounce variables ----------
const unsigned long DEBOUNCE_MS = 50;   // signal must stay the same for 50 ms

int lastReading = HIGH;                 // reading from the previous loop
int stableState = HIGH;                 // confirmed (debounced) button state
unsigned long lastChangeTime = 0;       // time when the reading last changed

unsigned int pressCount = 0;            // number of valid presses

// ---------- Draw the status screen ----------
void drawScreen() {
  display.clearDisplay();               // clear the old content in the buffer
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ESP32 Button Counter");

  display.setCursor(0, 20);
  display.print("Button: ");
  display.println(stableState == LOW ? "PRESSED" : "RELEASED");

  display.setTextSize(2);
  display.setCursor(0, 40);
  display.print("Count: ");
  display.println(pressCount);

  display.display();                    // send the buffer to the OLED
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Wire.begin(SDA_PIN, SCL_PIN);
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("OLED not found. Check wiring and address.");
    while (true) { delay(1000); }       // stop here if the OLED is missing
  }

  drawScreen();                         // startup screen: count = 0
  Serial.println("System ready. Count = 0");
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  // Step 1: if the reading changed (maybe bounce), restart the timer
  if (reading != lastReading) {
    lastChangeTime = millis();
    lastReading = reading;
  }

  // Step 2: has the reading stayed the same for DEBOUNCE_MS?
  if ((millis() - lastChangeTime) >= DEBOUNCE_MS) {

    // Step 3: is it different from the confirmed state? Then it is a real change
    if (reading != stableState) {
      stableState = reading;

      // Step 4: count only when the button becomes PRESSED (LOW)
      if (stableState == LOW) {
        pressCount++;
        Serial.print("Accepted press. Count = ");
        Serial.println(pressCount);
      } else {
        Serial.println("Button released");
      }

      drawScreen();                     // update the OLED only when something changed
    }
  }
}
