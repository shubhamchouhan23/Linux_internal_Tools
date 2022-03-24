#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int a = 4;
void f1(void)
{
  printf("Square is: %d\n",a*a);
}
void f2(void)
{
  printf("Cube is: %d\n",a*a*a);
}
void f3(void)
{
 a++;
 printf("Value incremented to: %d\n",a);
}
int main()
{
 printf("Value: %d\n", a);
 pthread_t t1, t2, t3;
 
 pthread_create(&t1, NULL, f1, NULL);
 pthread_create(&t2, NULL, f2, NULL);
 pthread_create(&t3, NULL, f3, NULL);

 pthread_join(t1, NULL);
 pthread_join(t2, NULL);
 pthread_join(t3, NULL);

 printf("Shared Varible is: %d\n", a);
 return 0;
}
