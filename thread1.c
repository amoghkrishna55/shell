#include <stdio.h>
#include <pthread.h>
#include <string.h> 

void* conc(void* arr, void* ans) {
    char* myarr = (char*)arr;
    char* myans = (char*)ans; 
    strcpy(myans, myarr);
    return NULL;
}

int main() {
    char line[100];
    char ans[100] = "";
    int a;
    pthread_t thread1;
    scanf("%d", &a);
    while (a--) {
        scanf("%s", line);
        pthread_create(&thread1, NULL, conc, (void*)line);
        pthread_join(thread1, NULL);
    }
    printf("%s\n", ans);
    return 0;
}
