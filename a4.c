#include<stdlib.h>
#include <stdio.h>
#include <pthread.h>
void *sqr_thread(void *arg){
	int *a=(int *)arg;
	printf("Square of %d is %d\n",*a,(*a)*(*a));
	return NULL;
}
int main(){
	pthread_t t[5];
	int arr[5];
	for(int i=0;i<5;i++){
		arr[i]=i+1;
		 if (pthread_create(&t[i], NULL, sqr_thread, &arr[i]) != 0) {
        	    perror("Failed to create thread");
        	    return 1;
       		 }
		 pthread_join(t[i],NULL);

	}
	return 0;
}

