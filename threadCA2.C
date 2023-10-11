#include <stdio.h>
#include <pthread.h>

void* even(void* arg) {
    printf("Even numbers: ");
    for (int i = 2; i <= 100; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    return NULL;
}

void* odd(void* arg) {
    printf("Odd numbers: ");
    for (int i = 1; i <= 99; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    pthread_create(&thread1, NULL, even, NULL);
    pthread_create(&thread2, NULL, odd, NULL);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
