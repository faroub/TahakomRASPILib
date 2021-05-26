/**
 * @file main.cpp
 *
 * Demo example: Blink a Led
 *
 * Usage demonstration of the TahakomAVRLib in a simple blink a Led example.
 * This example demonstrates the use of the component::Led() and io::Pin() abstraction objects.
 *
 * - Compiler: avr-gcc (GCC) 5.4.0
 * - Supported devices:  The example compiles on the ATmega48P/88P/168P/328P AVR family
 *
 *
 * @author Farid Oubbati (farid.oubbati@outlook.com)
 * @date March 2018
*/

#include <wiringPi.h>

int main (void)
{
  wiringPiSetup () ;
  pinMode (0, OUTPUT) ;
  for (;;)
  {
    digitalWrite (0, HIGH) ; delay (100) ;
    digitalWrite (0,  LOW) ; delay (100) ;
  }
  return 0 ;
}
