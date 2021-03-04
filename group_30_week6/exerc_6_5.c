 /* ====================================
 File name: exerc_6_5.c
 Date: 2021-03-02
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:
 Demonstration code: [9421]
 ====================================== */

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty    = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full     = PTHREAD_COND_INITIALIZER;

/* Declare global variables */
#define MAX 10

/* Declare variables */
char letter = 'a';  // starting letter
char buffer[MAX];   // circular buffer. Test for MAX 5 and 10.
int inPos;          // index for next character to be put in buffer. (put)
int outPos;         // index for next character to be read (fetch)
int count;          // the number of characters in buffer not fetched.

/* Declare methods */
double get_time_ms();
void snooze(int ms);

/* Declare thread methods */
void *put(void *param);
void *fetch(void *param);

 /* Main */
int main() {
    int i;
    pthread_t t_put, t_fetch;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&t_put, &attr, put, NULL);
    pthread_create(&t_fetch, &attr, fetch, NULL);
    while(1) {
        printf("Main is executing\n");
        snooze(100);
    }
    pthread_join(t_put, NULL);
    pthread_join(t_fetch, NULL);
    return 0;
}

void *put(void *param) {
    char ch = 'a';
    int placed = 0;
    pthread_mutex_lock(&count_mutex);
    while(1) {

        if (count == MAX) {
            pthread_cond_wait(&not_full, &count_mutex);
            printf("Buffer full.\n");
        }
        buffer[inPos] = ch;
        count++;
        inPos++;
        if (inPos == MAX)
        {
            inPos = 0;
        } 
        printf("Buffer storing\n");
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&count_mutex);
       
        ch++;
        if (ch == 'z'+1) {
            ch = 'a';
        }
    }
    pthread_exit(0);
}

void *fetch(void *param) {
    int fetched = 0;
    while(1) {

        pthread_mutex_lock(&count_mutex);
        if(count <= 0) {
            pthread_cond_wait(&not_empty, &count_mutex);
            printf("Buffer empty.\n");
        }
        printf("Buffer output: %c\n", buffer[outPos]);
        buffer[outPos] = NULL;
        count--;
        outPos++;
        if (outPos == MAX) {
            outPos = 0;
        }
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&count_mutex);
        
    }
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