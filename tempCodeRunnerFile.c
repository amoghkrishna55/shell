#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int fd[2], nb;
    pid_t pid;
    int n;
    pipe(fd);
    int a = rand();
    pid = fork();
    if(pid==0){
        close(fd[0]);
        write(fd[1], &a, sizeof(int));
        printf("Child: %d\n", a);
        close(fd[1]);
        exit(0);
    }
    else{
        read(fd[0], &n, sizeof(int));
        printf("Parent: %d\n", n);
        if(n%2==0)
            printf("Even\n");
        else
            printf("Odd\n");
    }
    return 0;
}