#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void)
{
pid_t pid1;
pid1=fork();

if(pid1==0)
	{
	sleep(5);
	printf("Child pid: %d\n", getpid());
	execl("/bin/ls", "ls", "-lh", 0);
	}
else
	{
	int pid2;
	printf("Parent pid: %d\n", getpid());
	pid2 = wait(0);
	printf("Normal child termination %d\n", pid2);
	printf("Parent process pid: %d\n", getpid());
	}

return 0;
}
