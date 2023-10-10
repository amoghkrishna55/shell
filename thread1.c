#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STRINGS 10
#define MAX_STRING_LENGTH 100

void *concatenate_strings(void *arg) {
    char *strings[MAX_STRINGS];
    int num_strings = *(int *)arg;
    int total_length = 0;
    for (int i = 0; i < num_strings; i++) {
        strings[i] = ((char **)arg)[i + 1];
        total_length += strlen(strings[i]);
    }
    char *concatenated_string = (char *)malloc(total_length + 1);
    int index = 0;
    for (int i = 0; i < num_strings; i++) {
        strcpy(&concatenated_string[index], strings[i]);
        index += strlen(strings[i]);
    }
    pthread_exit(concatenated_string);
}

int main() {
    char *strings[] = {"Hello, ", "World! ", "This ", "is ", "a ", "multi-threaded ", "concatenation ", "example."};
    int num_strings = sizeof(strings) / sizeof(strings[0]);
    pthread_t thread;
    if (pthread_create(&thread, NULL, concatenate_strings, (void *)&num_strings) != 0) {
        perror("Thread creation error");
        return 1;
    }
    char *concatenated_string;
    if (pthread_join(thread, (void **)&concatenated_string) != 0) {
        perror("Thread join error");
        return 1;
    }
    printf("%s\n", concatenated_string);
}