#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

struct Array {
    int arr[100];
    int arr1[50];
    int arr2[50];
    int size;
};

void bubbleSort(int* arrayToSort, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arrayToSort[j] > arrayToSort[j + 1]) {
                temp = arrayToSort[j];
                arrayToSort[j] = arrayToSort[j + 1];
                arrayToSort[j + 1] = temp;
            }
        }
    }
}

void* sortArr1(void* arrays) {
    struct Array* array = (struct Array*)arrays;
    bubbleSort(array->arr1, array->size / 2);
    pthread_exit(NULL);
}

void* sortArr2(void* arrays) {
    struct Array* array = (struct Array*)arrays;
    bubbleSort(array->arr2, array->size / 2);
    pthread_exit(NULL);
}

void* sortMerge(void* arrays){
    struct Array* array = (struct Array*)arrays;
    for(int i=0;i<array->size/2;i++){
        array->arr[i] = array->arr1[i];
    }
    for(int i=array->size/2;i<array->size;i++){
        array->arr[i] = array->arr2[i-(array->size/2)];
    }
    bubbleSort(array->arr, array->size);
    pthread_exit(NULL);
}

int main() {
    int arr[100];
    int a;
    struct Array array;
    array.size = 0;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        scanf("%d", &arr[i]);
    }
    array.size = a;
    for (int i = 0; i < a / 2; i++) {
        array.arr1[i] = arr[i];
    }
    for (int i = a / 2; i < a; i++) {
        array.arr2[i - (a / 2)] = arr[i];
    }

    pthread_t tid1, tid2, tid3;
    pthread_create(&tid1, NULL, sortArr1, &array);
    pthread_create(&tid2, NULL, sortArr2, &array);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_create(&tid3, NULL, sortMerge, &array);
    pthread_join(tid3, NULL);

    for (int i = 0; i < a; i++) {
        printf("%d ", array.arr[i]);
    }
    return 0;
}