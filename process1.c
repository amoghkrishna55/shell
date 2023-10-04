#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

int main(){
	int a,pid;
	int ans=0;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		 pid=fork();
		 if(pid==0){
			 printf("Current PID: %d\n",getpid());
			 printf("Parent PID: %d\n",getppid());
			 printf("\n");
		 }
	}
}
