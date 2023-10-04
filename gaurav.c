#include <stdio.h>
#include <unistd.h>

int main() {
    // P1
    printf("P1 (PID: %d, PPID: %d)\n", getpid(), getppid());

    pid_t pid = fork();

    if (pid == 0) {
        // P2
        printf("P2 (PID: %d, PPID: %d)\n", getpid(), getppid());

        pid = fork();

        if (pid == 0) {
            // P3
            printf("P3 (PID: %d, PPID: %d)\n", getpid(), getppid());
        }
    }

    sleep(1); // Wait for child processes to complete

    return 0;
}
