#include <stdio.h>
#include <pthread.h>
#include <string.h>

char ans[100] = "";
void* conc(void* arg) {
    char* myarg = (char*)arg;
    strcat(ans, myarg);
    strcat(ans," ");
    pthread_exit(NULL);
}

int main() {
    int a;
    pthread_t thread1;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        char line[100];
        scanf(" %s", line);
        pthread_create(&thread1, NULL, conc, (void*)line);
        pthread_join(thread1, NULL);
    }
    printf("Concatenated string: %s\n", ans);
    return 0;
}
