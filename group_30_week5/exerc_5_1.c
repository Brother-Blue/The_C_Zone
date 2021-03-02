/* ====================================
 File name: exerc_5_1.c
 Date: 2021-02-23
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:

 Demonstration code: [3262]
 ====================================== */

#include <avr/io.h>
#include <util/delay.h>

/* --- Maros predefined for the compiler 
DDRB  Data direction register B
PORTB Outport B
PINB  Inport B
DDRD  Data direction register D
PORTD Outport D
PIND  Inport D
*/ 

const byte interruptPin = 2; // The pin that will check for keypress and start the IRS
char key = ' '; // Init a blank key to print

const char rows = 4; // Amount of rows in keypad
const char cols = 4; // Amount of cols in keypad
const char keys[rows][cols] = { // Init the keypad mapping
  {'C','D','E','F'},
  {'8','9','A','B'},
  {'4','5','6','7'},
  {'0','1','2','3'} 
};

void setup() {  
  Serial.begin(9600);      // Start the serial
  DDRB = B00001111;        // bits 4...7
  DDRD = DDRD | B00001011; // bits 0..3
  attachInterrupt(digitalPinToInterrupt(interruptPin), getKey, FALLING); // Attach the IRS
} 

// Iterrate through the keypad to find the key pressed
void getKey() {
  bool btnDown = false; // To avoid spamming the serial
  for (int i = 0; i < rows; i++) {
    // Shift the power to the next row
    PORTB = B1111 & ~(1 << i);
    // Iterate through each button in the row
    for (int j = 0; j < cols; j++) {
      // Check for the pressed button
      if (bitRead(PIND, (7-j)) == 0 && !btnDown) {
        btnDown = true;
        // Set the key and leave the method
        key = (keys[i][j]);
        return;
      }
    }
  }
}

// Main loop
void loop()
{
  // Reset to HIGH
  PORTB = 0x00;
  // Print value if the key was set
  if (key != ' ') {
    Serial.println(key);
    Serial.print("");
  }
  key = ' ';
}