#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int i = 10;

pthread_mutex_t mutex1;

void square(void)
{
 pthread_mutex_lock(&mutex1);
 printf("square: %d\n", i*i);
 pthread_mutex_unlock(&mutex1);
}
void cube(void)
{
 pthread_mutex_lock(&mutex1);
 printf("cube: %d\n", i*i*i);
 pthread_mutex_unlock(&mutex1);
}

int main()
{
 pthread_t t1, t2;
 pthread_mutex_init(&mutex1, NULL);

 pthread_create(&t1, NULL, square, NULL);
 pthread_create(&t2, NULL, cube, NULL);

 pthread_join(t1, NULL);
 pthread_join(t2, NULL);

 printf("Number is: %d\n", i);

 return 0;
}
