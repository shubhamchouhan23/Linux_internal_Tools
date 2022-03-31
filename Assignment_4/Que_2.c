#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

struct my_thread
{
	int thread_id;
	char msg[100];
};

void *PrintHello(void *threadobj)
{
	pthread_t thread_ID;
	struct my_thread *t1;
	t1 = (struct my_thread *) threadobj;
	thread_ID = pthread_self();
	printf("\n Thread Id : %u\n",thread_ID);
	printf("\n %d Thread message :%s\n",t1->thread_id,t1->msg);
}

int main()
{
	pthread_t thread2,thread3,thread4,thread_ID;
	int RC;
	struct my_thread t1,t2,t3;
	t3.thread_id = 3;
	strcpy(t3.msg,"I am third thread\n");
	t1.thread_id=1;
	strcpy(t1.msg,"I am first thread\n");
	t2.thread_id=2;
	strcpy(t2.msg,"I am second thread\n");
	
	thread_ID = pthread_self();
	printf("\n Main thread ID : %u",thread_ID);
	
	pthread_create(&thread4,NULL,PrintHello,(void *)&t3);
	pthread_create(&thread4,NULL,PrintHello,(void *)&t1);
	pthread_create(&thread4,NULL,PrintHello,(void *)&t2);
	
	printf("\n exit from main thread");
	pthread_exit(NULL);
}
