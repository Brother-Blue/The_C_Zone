 /* ====================================
 File name: exerc_6_5.c
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

/* Declare thread methods */
void *put(void *param);
void *fetch(void *param);

 /* Main */
int main() {
    int i;
    pthread_t t_put, t_fetch;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

     (&t_put, &attr, put, NULL);
    pthread_create(&t_fetch, &attr, fetch, NULL);
    while(1) {
        
    }
    pthread_join(t_time_count, NULL);
    pthread_join(t_read_inport, NULL);
    return 0;
}

void *put(void *param) {
    char ch = 'a';
    int placed = 0;
    pthread_mutex_lock(&count_mutex);
    while(1) {
        pthread_cond_wait(&not_full, &count_mutex);
        for (int i = 0; i < MAX; i++) {
            if (sizeof(buffer[i]) != sizeof(char)) {
                buffer[i] = ch;
                placed = 1;
                break;
            }
        }
        pthread_mutex_unlock(&count_mutex);
        if (placed) {
            pthread_cond_signal(&not_empty);
        }
        placed = 0;
        ch = ch == 'z' ? 'a' : ch++;
    }
    pthread_exit(0);
}

void *fetch(void *param) {
    int fetched = 0;
    pthread_mutex_lock(&count_mutex);
    while(1) {
        pthread_cond_wait(&not_empty, &count_mutex);
        for (int i = 0; i < MAX; i++) {
            if (sizeof(buffer[i]) == sizeof(char)) {
                printf("Character found: %c\n", buffer[i]);
                buffer[i] = '\0';
                fetched = 1;
                break;
            }
        }
        pthread_mutex_unlock(&count_mutex);
        if (fetched) {
            pthread_cond_signal(&not_full);
        }
        fetched = 0;
    }
    pthread_exit(0);
}

