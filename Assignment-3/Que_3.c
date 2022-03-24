#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/mman.h>

void * function(void *attr)
{
 sleep(3);
 printf("Thread attributes has been changed\n");
}
int main()
{
 pthread_attr_t attr;
 pthread_t t1;
 int data;
 
 pthread_attr_init(&attr);
 pthread_attr_getinheritsched(&attr, &data);

 if(data==PTHREAD_INHERIT_SCHED)
 printf("Inherit: Getting policies from parent\n");
 else
 printf("Explicit: Has own policies\n");
 sleep(5);

 pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
 pthread_attr_getinheritsched(&attr, &data);

 if(data==PTHREAD_INHERIT_SCHED)
 printf("Inherit: Getting policies from parent\n");
 else
 printf("Explicit: Has own policies\n");

 pthread_create(&t1, &attr, function, NULL);
 pthread_join(t1,NULL);

 return 0;
}
