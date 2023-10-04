#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int pid;
	pid=getpid();
	printf("Process ID: %d\n",pid);
	pid=fork();
	printf("Process ID: %d\n",pid);
	return 0;
}
