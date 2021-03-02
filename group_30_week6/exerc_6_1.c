 /* ====================================
 File name: exerc_4_1.c
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

 // 1. One thread is created.
// 2. pthread_t tid; declare a pointer to the thread_id
//    pthread_attr_t attr; declare the attribute of the thread (default if null)
//    pthread_attr_init(&attr); initialise the thread object
//    pthread_create(&tid, &attr, runner, NULL); creates the thread
//    pthread_join(tid, NULL); waits for thread to close
// 3. 1
// 4. In the thread creation we declare what attribute to pass, in this case it's NULL
// 5. The code won't wait for the threading to finish, resulting in the sorting being exucuted before runner has finished populating the values