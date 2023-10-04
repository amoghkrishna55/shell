#include<stdio.h>
#include<pthread.h>

void *func(){
	printf("In the thread function \n");
	pthread_exit("Exit thread function \n");
}
int main() {
    char *strings[] = {"Hello, ", "World! ", "This ", "is ", "a ", "single-threaded ", "concatenation ", "example."};
    int num_strings = sizeof(strings) / sizeof(strings[0]);

    // Calculate the total length of the concatenated string
    int total_length = 0;
    for (int i = 0; i < num_strings; i++) {
        total_length += strlen(strings[i]);
    }

    // Allocate memory for the concatenated string
    char *concatenated_string = (char *)malloc(total_length + 1);
    if (concatenated_string == NULL) {
        perror("Memory allocation error");
        return 1;
    }
