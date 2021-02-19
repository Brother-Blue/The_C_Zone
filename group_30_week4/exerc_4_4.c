/* ====================================
 File name: exerc_4_4.c
 Date: 2021-02-16
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:
 Hugo Hempel
 Demonstration code: [4580]
 ====================================== */

// ---- Program template for Arduino in Tinkercad VT 2021
#include <avr/io.h>
#include <util/delay.h>
/* --- Macros predefined for the compiler 
DDRB  Data direction register B
PORTB Outport B
PINB  Inport B
DDRD  Data direction register D
PORTD Outport D
PIND  Inport D
*/ 

void setup() {  
  // Serial.begin(9600); // If using the Serial monitor and in that case needed Port D bit 1,0 to be set as out/in   
  DDRD = DDRD | B11111111; // To set all Port D bits as outbits.  
  DDRB = 0x00; // (Set all to inbits)
  PORTD = B00000011; // Init with binary 3
} 

void loop() {
  // Check if switch is toggled
  if(PINB == B1)
  {
    // Shift the binary left, if PB7 is set, set PB0 (shift right by 7 bits)
    PORTD = (PORTD << 1) | (PORTD >> 7);
  }                                  
  delay(500); // Wait for 500 millisecond(s)
} 