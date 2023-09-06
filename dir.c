#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	int a;
	a = mkdir("amogh",0666);
	write(1,&a,1);
}
