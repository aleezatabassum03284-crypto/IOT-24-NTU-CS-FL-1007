// Week3-Lecture2
// Timer Interrupt (Internal)
// Embedded IoT System Fall-2026

// Name: Aleeza Tabassum Saleem                 Reg#: 24-NTU-CS-FL-1007

#include<Arduino.h>

#define LED 2

hw_timer_t *My_timer = NULL;

void IRAM_ATTR onTimer() {
  digitalWrite(LED, !digitalRead(LED));
}

void setup() {
  pinMode(LED, OUTPUT);

  My_timer = timerBegin(0, 80, true);

  timerAttachInterrupt(My_timer, &onTimer, true);

  timerAlarmWrite(My_timer, 1000000, true);

  timerAlarmEnable(My_timer);
}

void loop() {
}