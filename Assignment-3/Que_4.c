#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void function(void *thread)
{
 int pid;
 pid = getpid();
 printf("Calling process PID: %d\n", pid);
}

int main()
{
pthread_t t1;

pthread_create(&t1, NULL, function, NULL);
printf("Thread ID: %d\n", t1);
sleep(3);

printf("Exiting\n");

return 0;
}
