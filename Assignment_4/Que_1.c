#include<pthread.h>
#include<stdio.h>

void *mythread(void *i)
{
	printf("\n I am in my thread %d\n",(int *)i);
}

int main()
{

	pthread_t thread1, thread2,thread3;
	pthread_create(&thread1,NULL,mythread,(void *)1);
	printf("\n exit for main thread\n");
	pthread_exit(NULL);
}
