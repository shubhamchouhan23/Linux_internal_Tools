#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
int fd;
pid_t pid1;
char buf[50];

pid1 = fork();

if(pid1==0)
	{
	 sleep(3);
	 printf("Child started\n");
	 fd = open("assignment2_5_copy.txt", O_RDONLY, 777);
	 read(fd,buf,50);
	 printf("The data is: %s\n",buf);
	 int close(int fd);
	}
else
	{
	 int pid2;
	 printf("Parent PID: %d\n",getpid());
	 pid2 = wait(0);
	 printf("Child is terminated\n");
	 printf("Parent PID: %d\n",getpid());	 	
	}

return 0;
}
