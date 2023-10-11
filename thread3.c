#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct ThreadArgs {
    int* arr;
    int size;
    int maxResult;
    int minResult;
    float avgResult;
};

void* avg(void* arg) {
    struct ThreadArgs* args = (struct ThreadArgs*)arg;
    int* arr = args->arr;
    int size = args->size;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    float avg = (float)sum / size;
    (args->avgResult) = avg;
    pthread_exit(NULL);
}

void* max(void* arg) {
    struct ThreadArgs* args = (struct ThreadArgs*)arg;
    int* arr = args->arr;
    int size = args->size;

    int max_value = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    (args->maxResult) = max_value;
    pthread_exit(NULL);
}

void* min(void* arg) {
    struct ThreadArgs* args = (struct ThreadArgs*)arg;
    int* arr = args->arr;
    int size = args->size;

    int min_value = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }

    (args->minResult) = min_value;
    pthread_exit(NULL);
}

int main() {
    int maxResult;
    int minResult;
    float avgResult;
    int array[100];
    int arraySize;
    scanf("%d", &arraySize);
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &array[i]);
    }
    pthread_t max_tid, min_tid, avg_tid;
    struct ThreadArgs args;
    args.arr = array;
    args.size = arraySize;

    pthread_create(&max_tid, NULL, max, &args);
    pthread_create(&min_tid, NULL, min, &args);
    pthread_create(&avg_tid, NULL, avg, &args);

    pthread_join(max_tid, NULL);
    pthread_join(min_tid, NULL);
    pthread_join(avg_tid, NULL);

    minResult = args.minResult;
    avgResult = args.avgResult;
    maxResult = args.maxResult;

    printf("Maximum: %d\n", maxResult);
    printf("Minimum: %d\n", minResult);
    printf("Average: %.2f\n", avgResult);
    return 0;
}
