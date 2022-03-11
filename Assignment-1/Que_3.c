/***
Program Returning “ls -l ” kind of structure of information from an existing file or
opend file.
***/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
		
	char file[20];
	
	//taking file name as input
	printf("Enter file name.extension : ");
	scanf("%s", file);
	
	printf("Executing ls -l\n");
	
	//performing 'ls -l' operation on user file
	execl("/bin/ls", "ls", "-l", file, 0);
	
	return 0;
}
