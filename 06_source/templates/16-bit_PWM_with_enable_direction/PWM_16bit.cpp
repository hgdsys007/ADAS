/* --------------------------------------------------------------
	Arduino Library to use 16-bit PWM signals on the Arduino Mega
	
	Author: Christoph Jurczyk
 -------------------------------------------------------------- */

#include "Arduino.h"
#include "PWM_16bit.h"

// function to initialize 16-bit PWM
void setupPWM16() {
  TCCR1A = _BV(COM1A1) | _BV(COM1B1)  /* non-inverting PWM */
           | _BV(WGM11);                   /* mode 14: fast PWM, TOP=ICR1 */
  TCCR1B = _BV(WGM13) | _BV(WGM12)
           | _BV(CS10);                    /* no prescaling */
  ICR1 = 0xffff;                      /* TOP counter value */
}


// function to write PWM duty cycle
// value from 0 to 65535
void analogWrite16(uint8_t pin, uint16_t val)
{
  switch (pin) {
    case  11: OCR1A = val; break;
    case  12: OCR1B = val; break;
  }
}
