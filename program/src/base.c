#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

#define _NUM_THREADS 4

pthread_mutex_t mutex_report_value;

void * report_value() {
    pthread_mutex_lock(&mutex_report_value);
    printf("(OK)\n");
    pthread_mutex_unlock(&mutex_report_value);
}

void * find_md5_sqli(void *vargp) {
    sleep(1);
    printf("Printing from inside Thread \n");
    report_value();
    return NULL;
}

int main() {
    short tk = 0;
    pthread_t threads[_NUM_THREADS];
    printf("Before Thread\n");
    for (tk = 0; tk < _NUM_THREADS; tk++) {
        printf("[DEBUG] Created Thread %d\n", tk);
        pthread_create(&threads[tk], NULL, find_md5_sqli, NULL);
    }

    for (tk = 0; tk < _NUM_THREADS; tk++) {
        pthread_join(threads[tk], NULL);
    }
    printf("After Thread\n");
    exit(0);
}
