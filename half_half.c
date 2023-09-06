#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
	int fd1,fd2,fd3;
	char buf[100];
	fd1=open("sample.txt",O_RDONLY,0777);
	fd2=open("half1.txt",O_WRONLY,0777);
	fd3=open("half2.txt",O_WRONLY,0777);
	int l = lseek(fd1,0,SEEK_END);
	lseek(fd1,0,SEEK_SET);
	read(fd1,buf,l/2);
	write(fd2,buf,l/2);
	read(fd1,buf,l/2);
	write(fd3,buf,l/2);
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}

