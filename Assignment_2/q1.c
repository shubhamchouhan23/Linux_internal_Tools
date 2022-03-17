#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
int fd;

fd = open("assignment2_1_exc_assign.c", O_RDONLY, 777);
printf("The fd of the file is: %d\n", fd);

return 0;
}
