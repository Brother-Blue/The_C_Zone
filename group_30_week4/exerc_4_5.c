/* ====================================
 File name: exerc_4_5.c
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

const char rows = 4; // Define row count
const char cols = 4; // Define column count
const char keys[rows][cols] = { // Define keypad mapping
  {'C','D','E','F'},
  {'8','9','A','B'},
  {'4','5','6','7'},
  {'0','1','2','3'} 
};

bool btnClicked = false; // Used to avoid spam clicks

void setup() {  
  Serial.begin(9600);   
  DDRB = B00001111;        // bits 5...8
  DDRD = DDRD | B00001111; // bits 0...4
} 

char getKeys() {
  PORTB = B1;
  if (!btnClicked) {
    btnClicked = !btnClicked;
    // Iterate through the rows
    for (int i = 0; i < rows; i++) {
      // Shift the power up a row
      PORTB = B1111 & ~(1 << i);
      // Check for each button on the row
      for (int j = 0; j < cols; j++) {
        // If the button reads a LOW power return the mapping of that row and col
        if (bitRead(PIND, (7-j)) == 0) {
          return(keys[i][j]);
        }
      }
    }
  }
  // Otherwise return empty
  return ' ';
}

void loop()
{
  char c = getKeys(); // Store the pressed key
  // If the key is not pressed print it
  if (c != ' ') {
    Serial.println(c);
  }
  // Wait a second and reset the btnClicked
  delay(1000);
  btnClicked = !btnClicked;
}