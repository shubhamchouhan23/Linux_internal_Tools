#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
 printf("I am executing execl statement\n");

 execl("/bin/ls", "ls", "-lh", 0);

 printf("Not executed execl");

 return 0;
}

