#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *thread_sum(void *arg) {

    int *arr = (int *)arg;
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }

    printf("Sum: %d\n", sum);

    return NULL;
}

int main() {

    int arr[10];
    pthread_t t1, t2;

    int half = 10 / 2;
    int arr1[half];
    int arr2[half];

    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;

        if (i < half) {
            arr1[i] = arr[i];
        }
        else {
            arr2[i - half] = arr[i];
        }
    }

    if (pthread_create(&t1, NULL, thread_sum, arr1) != 0 ||
        pthread_create(&t2, NULL, thread_sum, arr2) != 0) {

        perror("Failed");
        return 1;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
