#include <stdio.h>
#include <pthread.h>
#include <string.h>

void* conc(void* arg) {
    int count;
    char* myarg = (char*)arg;
    for(count=0;myarg[count]!='\0';count++);
    pthread_exit((void*)(intptr_t)count);
}

int main() {
    void* a;
    pthread_t thread1;
    char line[100];
    scanf(" %s", line);
    pthread_create(&thread1, NULL, conc, (void*)line);
    pthread_join(thread1, &a);
    printf("Length of string: %d\n", (int)(intptr_t)a);
    return 0;
}
