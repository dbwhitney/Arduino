/*
 * Using the watchdog as timer, because Timer0 is already used in
 * Arduino code to count milliseconds.
 */


#include <avr/interrupt.h>
#include <avr/wdt.h>

// avr/sleep.h doesn't know the ATtiny13. So put this before the #include
// because the tiny87 has the same bits at the tiny13.
#define __AVR_ATtiny87__

#include <avr/sleep.h>


void setupWatchdog() {
  cli();
  // set timer to 8 sec
  WDTCR |= (1<<WDP3) | (1<<WDP0);

  // Set watchdog timer in interrupt mode
  WDTCR |= (1 << WDTIE);
  WDTCR |= (0 << WDE);
  sei(); // Enable global interrupts
}

void setupPowerSaving() {
  // disable ADC
  ADCSRA = 0;  

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
}



void goSleep() {
  sleep_mode();   // go to sleep and wait for interrupt...
}

void resetWatchdog() {
  wdt_reset();
}

