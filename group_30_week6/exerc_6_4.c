 /* ====================================
 File name: exerc_6_4.c
 Date: 2021-03-02
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:
 Demonstration code: [XXXX]
 ====================================== */

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

/* Declare thread methods */
void *time_count(void *param);
void *read_inport(void *param);

/* Declare methods */
double get_time_ms();
void snooze(int ms);

int program_time; // The global time, start value 0

// ------MAIN------
int main() {

    pthread_t t_time_count, t_read_inport; // Init thread variables
    pthread_attr_t attr; // Init thread attr
    
    // Assign the thread attr
    pthread_attr_init(&attr);
    
    // Create the threads
    pthread_create(&t_read_inport, &attr, read_inport, NULL);
    pthread_create(&t_time_count, &attr, time_count, NULL);     

    // Join the threads
    pthread_join(t_time_count, NULL);
    pthread_join(t_read_inport, NULL);
}
// --- End of main thread ----

// ---- Thread functions -----
// Program timer
void *time_count(void *param) {
    while (program_time < 50) {
        // Print the current program time, increment it, then sleep for 1 second
        printf("Program time: %d\n", program_time);
        program_time++;
        snooze(1000);
    }
    // exit thread
    pthread_exit(0);
} // End----------------------

// Reads the inport
void *read_inport(void *param) {
    // Keep reading until program_time ends
    while ( program_time < 50) {
        // Read every 5 seconds and print a message
        snooze(5000);
        printf("Reading Inport now...\n");
    }
    printf("\n done");
    pthread_exit(0);
}

// Sleep for x milliseconds
void snooze(int ms) {
    double prevTime = get_time_ms(); // Get the current system time
    double curTime = prevTime; // Get the current system time
    // Check the current time until desired sleep time passed
    while ((curTime - prevTime) <= ms) {
        curTime = get_time_ms();
    }
}

double get_time_ms(){        
    struct timeval t;        
    gettimeofday(&t, NULL);         
    return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}
