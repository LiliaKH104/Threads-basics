#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

void *thread_f(void *arg){
	int thread_num=*(int *)arg;
	printf("Thread %d is running\n", thread_num);
	return NULL;
}
int main(){
	pthread_t t[3];
	int j[3];
	for (int i=0;i<3;i++){
		j[i]=i+1;
		if(pthread_create(&t[i],NULL,thread_f, &j[i])!=0){
			perror("failed to create");
			return 1;
		}
	}
	for (int i=0;i<3;i++){
		pthread_join(t[i],NULL);
	}
	printf("Finished");
	return 0;
}
