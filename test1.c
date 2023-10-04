#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

int main(){
        int a,pid;
        scanf("%d",&a);
        for(int i=0;i<a;i++){
                 pid=fork();
                 if(pid==0){
                         printf("I AM CHILD PROCESS NUMBER %d\n",getpid());
                 }
		/* else{
			 printf("I AM PARENT PROCESS NUMBER %d\n",getppid());
		 }*/
        }
}
