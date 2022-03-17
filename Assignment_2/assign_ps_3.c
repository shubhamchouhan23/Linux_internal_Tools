#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
 execl("/usr/bin/pstree", "./pstree", 0);

 return 0;
}

