

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>


void* callThread(void *thrdId)
{
	printf("\ncallThread() function called by thread_id 'tid1' in execution....\n\n");
	while(1);		
}


int main(void)
{
	pthread_t tid1;
	int status;
	
	printf("creating thread\n");
	
	pthread_create(&tid1, NULL, callThread, NULL);		
	
	printf("thread id %ld\n", tid1);
		
	
	sleep(3);		
	printf("Cancelling thread .....\n");
	
	status = pthread_cancel(tid1);
	
	printf("Thread cancelled.....\n");
	
	
	return 0;
}
