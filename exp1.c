#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
	DIR *dp;
	struct dirent *dptr;
	int a = mkdir("exp1",0777);
	dp=opendir("exp1");
	int b = open("exp1/test.txt",O_CREAT | O_RDWR ,0777);
	while(NULL !=(dptr=readdir(dp))){
		printf("\%s \n", dptr->d_name);
		printf("\%d \n", dptr->d_type);
	}
}
