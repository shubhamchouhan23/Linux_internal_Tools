#include<stdio.h>

void call1(void) 
{
	printf("Call for first function\n");
}
void call2(void) 
{
	printf("Call for second function\n");
}
void call3(void) 
{
	printf("Call for third function\n");
}

int main()
{
printf("1\n");
atexit(call1);

printf("2\n");
atexit(call2);

printf("3\n");
atexit(call3);

exit(0);
}

