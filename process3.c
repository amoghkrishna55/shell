#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid2, pid3, pid4, pid5;

    // P1
    printf("P1 (PID: %d, PPID: %d)\n", getpid(), getppid());

    // Fork P2 and P4
    pid2 = fork();

    if (pid2 == 0) {
        // P2
        printf("P2 (PID: %d, PPID: %d)\n", getpid(), getppid());

        // Fork P3
        pid3 = fork();

        if (pid3 == 0) {
            // P3
            printf("P3 (PID: %d, PPID: %d)\n", getpid(), getppid());
        }

        // Wait for P3 to finish (P2 should not become a zombie)
        wait(NULL);
    }
    else {
        pid4 = fork();

        if (pid4 == 0) {
            // P4
            printf("P4 (PID: %d, PPID: %d)\n", getpid(), getppid());

            pid5 = fork();

            if (pid5 == 0) {
                // P5
                printf("P5 (PID: %d, PPID: %d)\n", getpid(), getppid());
            }
        }
        else {
            // Simulating P4 as an orphan (P1 exits before P4)
            sleep(1);
            printf("P1 exiting\n");
        }
    }

    // Simulating P5 as a zombie (P5 exits before P4 retrieves its exit status)
    if (getpid() == pid4) {
        sleep(2);
        printf("P4 exiting\n");
    }

    return 0;
}
