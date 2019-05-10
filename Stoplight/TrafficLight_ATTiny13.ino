/*
The MIT License (MIT)

Copyright (c) 2015 Enrico Gueli

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <avr/interrupt.h>

const byte PIN_R=3;
const byte PIN_Y=2;
const byte PIN_G=4;

const byte PIN_BUTTON=1; // INT0 is at pin 1

typedef enum { RED, YELLOW, GREEN, OFF, MAX_LIGHT } light;
volatile light toShow;

const uint16_t OFF_TIMEOUT = 3945;

ISR(WDT_vect) {
  static uint16_t offTimeoutCount = 0;
  offTimeoutCount++;
  if (offTimeoutCount >= OFF_TIMEOUT) {
    offTimeoutCount = 0;
    toShow = OFF;
    trafficLight(OFF);
  }
}



ISR(INT0_vect) {
  onButtonPressed();
  delay(200);
  while(!digitalRead(PIN_BUTTON));
  onButtonReleased();
}

void setup() {
  setupLeds();
  digitalWrite(PIN_R, HIGH);

  setupButton();

  setupWatchdog();
  setupPowerSaving();

  toShow = RED;
  trafficLight(toShow);
}

void setupLeds() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_Y, OUTPUT);
  pinMode(PIN_G, OUTPUT);
}

void setupButton() {
  pinMode(PIN_BUTTON, INPUT);
  MCUCR &= ~(1 << PUD); // enable input pullups
  digitalWrite(PIN_BUTTON, HIGH); // enable pullup on button
  setupButtonInterrupt();
}

void setupButtonInterrupt() {
  cli();
  GIFR &= ~(1 << INTF0);      // Clear INT0 trigger flag
  GIMSK |= 1 << INT0;         // Enable INT0
  MCUCR &= ~(1 << ISC01);
  MCUCR &= ~(1 << ISC00); // Trigger INT0 on low level
  sei();
}

void loop() {
  goSleep();
}

void onButtonPressed() {
  resetWatchdog();
  toShow = (light) (toShow + 1);
  if (toShow == MAX_LIGHT) {
    toShow = (light)0;
  }
  trafficLight(toShow);
}

void onButtonReleased() {
}

void trafficLight(light l) {
  digitalWrite(PIN_R, l==RED    ? HIGH : LOW);
  digitalWrite(PIN_Y, l==YELLOW ? HIGH : LOW);
  digitalWrite(PIN_G, l==GREEN  ? HIGH : LOW);
}

void toggle() {
  digitalWrite(PIN_R, !digitalRead(PIN_R));
}

