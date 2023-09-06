#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd1 = open("read.txt", O_RDONLY, 0777);
	int a;
	while(1){
		char buf;
		a = read(fd1,&buf,1);
		if(a==0){
			break;
		}
		write(1,&buf,a);
	}
}
