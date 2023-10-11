#include<stdio.h>
#include<pthread.h>
#include<string.h>

char ans[100] = "";
void* conc(void* arg) {
    char* myarg = (char*)arg;
    strcat(ans, myarg);
    strcat(ans," ");
    pthread_exit(NULL);
}

void* prime(){
    for(int n=2;n<=20;n++){
        int isPrime = 1;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d is prime\n", n);
        }
    }
    printf("\n");
    pthread_exit(NULL);
}

void* pattern() {
    int rows = 4;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        for (int k = 0; k < rows - i; k++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    pthread_exit(NULL);
}

int main(){
    pthread_t thread1, thread2, thread3;
    char line1[100] = "i will become";
    char line2[100] = "an engineer";
    pthread_create(&thread1, NULL, conc, (void*)line1);
    pthread_join(thread1, NULL);
    pthread_create(&thread1, NULL, conc, (void*)line2);
    pthread_join(thread1, NULL);
    printf("Concatenated string: %s\n\n", ans);
    pthread_create(&thread2, NULL, prime, NULL);
    pthread_join(thread2, NULL);
    pthread_create(&thread3, NULL, pattern, NULL);
    pthread_join(thread3, NULL);
    return 0;
}