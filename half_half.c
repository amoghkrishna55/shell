#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
	int fd1,fd2,fd3;
	char buf[10];
	fd1=open("sample.txt",O_RDONLY,0777);
	fd2=open("half1.txt",O_WRONLY,0777);
	fd3=open("half2.txt",O_WRONLY,0777);
	read(fd1,buf,10);
	write(fd2,buf,10);
	read(fd1,buf,10);
	write(fd3,buf,10);
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}

