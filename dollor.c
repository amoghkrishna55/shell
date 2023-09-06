#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
int main(){
	int fd1,a;
	char buf[10];
	fd1=open("dollor.txt",O_WRONLY,0777);
	while(1){
		a=read(0,buf,1);
		if(*buf == '$'){
			break;
		}
		write(fd1,buf,a);
	}
	close(fd1);
}

