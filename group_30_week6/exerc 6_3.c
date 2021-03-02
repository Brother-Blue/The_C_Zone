 /* ====================================
 File name: exerc_6_3.c
 Date: 2021-03-02
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:
 Demonstration code: [XXXX]
 ====================================== */

#include <pthread.h>
#define ML13_Status 0x0B10 // Status register (read)
#define ML13_Control 0x0B00 // Control register (write)

/* Declare thread methods */
void *checkSensor(void *param);
void *isOpenSensor(void *param);
void *isClosedSensor(void *param);

/* Declare methods */
void openDoor();
void closeDoor();
int isOpening();
int isClosing();
int delay();
int checkBit(char bit, char byte);

 /* Main */
int main() {
	pthread_t isOpen, isClosed, sensorCheck; // declare thread id
	pthread_attr_t attr; // declare thread attribute
    
    // initialise the thread with default values
    pthread_attr_init(&attr);
    
    // Creates threads for all sensors
    pthread_create(&sensorCheck, &attr, checkSensor, NULL);
    pthread_create(&isOpen, &attr, isOpenSensor, NULL);
    pthread_create(&isClosed, &attr, isClosedSensor, NULL);

    // Join the threads when finished
    pthread_join(sensorCheck, NULL);
    pthread_join(isOpen, NULL);
    pthread_join(isClosed, NULL);
    
    return 0;
}

// Set a delay
int delay() {
    // Iterate through some arbitrary value for a delay
    for (int n = 0; n < 200000; n++) {
        ;
    }
    return 1;
}

// -------CHECKING------------
// Check the sensor
void *checkSensor(void *param) {
    // Bit 3,     Sensor ;       1 = Sensor is activated, someone close to the door
    if (checkBit(3, ML13_Status)) {
        if (!isOpening())
        openDoor(); // Open door
        checkSensor();
    } else {
        checkSensor();
    }
    pthread_exit(0);
}

// -------CLOSING------------
// Close the door if it is open
void closeDoor() {
    // Set bit 7
}

// Check if the door is in the closing state
int isClosing() {
    // Door is closing slowly? 
    return checkBit(7, ML13_Status);
}

// Check if the door is closed
void *isClosedSensor(void *param) {
    // If bit 5 is set
    if (checkBit(5, ML13_Status)) {
        // Door is closed
        isClosedSensor();
    } else {
        isClosedSensor();
    }
    pthread_exit(0);
}

// -------OPENING------------
// Open door if it is closed
void openDoor() {
    // Set bit 6
}

// Check if the door is in the opening state
int isOpening() {
    // Door is opening slowly?
    return checkBit(6, ML13_Status);
}

// Check if the door is opened
void *isOpenSensor(void *param) {
    // If bit 4 is set, delay then close
    if (checkBit(4, ML13_Status)) {
        delay();
        closeDoor(); // Close door
        isOpenSensor();
    } else {
        isOpenSensor();
    }
    pthread_exit(0);
}

// checks the bit of a byte.
// bit = the bit to select, byte = the byte to select from
int checkBit(char bit, char byte)
{
    // Shift 00000001 by bit, then compares with ML13_Status
    bit = 1 << bit; 
    return(bit & byte);
}