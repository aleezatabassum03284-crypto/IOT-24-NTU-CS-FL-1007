/*
  Homework-01 - Stage 2: Button input and counter (no debounce yet)
  Button on GPIO 18 to GND, INPUT_PULLUP (pressed = LOW).
  The count goes up when the button is pressed.
  NOTE: there is no debounce here, so one press may count more than once.
*/

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int BUTTON_PIN = 18;
const int SDA_PIN = 21;
const int SCL_PIN = 22;
const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const uint8_t OLED_ADDRESS = 0x3C;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int lastState = HIGH;               // previous button reading
unsigned int pressCount = 0;

void drawScreen(int state) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ESP32 Button Counter");

  display.setCursor(0, 20);
  display.print("Button: ");
  display.println(state == LOW ? "PRESSED" : "RELEASED");

  display.setTextSize(2);
  display.setCursor(0, 40);
  display.print("Count: ");
  display.println(pressCount);

  display.display();
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Wire.begin(SDA_PIN, SCL_PIN);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("OLED not found. Check wiring and address.");
    while (true) { delay(1000); }
  }

  drawScreen(HIGH);
  Serial.println("System ready. Count = 0");
}

void loop() {
  int state = digitalRead(BUTTON_PIN);

  if (state != lastState) {         // the button changed
    if (state == LOW) {             // it was pressed
      pressCount++;
      Serial.print("Press. Count = ");
      Serial.println(pressCount);
    }
    drawScreen(state);
    lastState = state;
  }
}
