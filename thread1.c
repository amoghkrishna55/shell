#include<stdio.h>
#include<pthread.h>

void* conc(void* arr, void* ans){
	char* myarr, myans;
	myarr = (char*) arr;
	myans = (char*) ans;
	strcopy(arr,ans);
	return ans;
}


int main(){
	char* line, ans="";
	int a;
	pthread_t thread1;
	scanf("%d", &a);
	while(a--){
		scanf("%c",line);
		pthread_create(&thread1, NULL, conc, (void*)line);
		pthread_join(thread1, &ans);
	}
	printf("%c",ans)
}
