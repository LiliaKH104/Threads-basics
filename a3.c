#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_numbers(void *arg) {

    int thread_num = *(int *)arg;

    for (int i = 1; i <= 5; i++) {
        printf("Thread %d: %d\n", thread_num, i);
    }

    return NULL;
}

int main() {

    pthread_t t[3];
    int numbers[3];

    for (int i = 0; i < 3; i++) {

        numbers[i] = i + 1;

        if (pthread_create(&t[i], NULL, print_numbers, &numbers[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(t[i], NULL);
    }

    printf("All threads finished.\n");

    return 0;
}
