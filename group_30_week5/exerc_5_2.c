/* ====================================
 File name: exerc_5_2.c
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
const byte tempSensor = A0;  // Analog pin to measure the temperature sensor

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
  DDRD = DDRD | B00001011; // bits 0...3
  attachInterrupt(digitalPinToInterrupt(interruptPin), getKey, FALLING); // Attach the IRS
  // Print temperature once in the beginning 
  printTemp();
} 

// Iterate through the keypad to find the key pressed
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

void printTemp() {
  int reading = analogRead(tempSensor); // Get the analog value from the temp sensor
  float voltage = reading * 5.0; // Convert the reading to volgate
  voltage /= 1024.0; 
  float temp = (voltage - 0.5) * 100; // Convert the voltage to temperature in Celsius
  Serial.print(temp); Serial.println(" C");
}

void loop()
{
  // Reset to HIGH
  PORTB = 0x00;
  // Print value and temp if the key was set
  if (key != ' ') {
    Serial.print(key);
    Serial.print(" ");
    printTemp();
  }
  key = ' ';
  delay(500);
}