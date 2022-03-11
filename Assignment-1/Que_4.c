/***
Program implementing all file operations(open/creat/write/read/lseek/close)
***/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
	int fd1, fd2;
	char rbuff[100];
	int len;
	
	fd1 = creat("new.txt", 0777);		//file created
		
	fd2 = open("data.txt", O_RDONLY, 777);		//opening a existing file	--data.txt
	
	len = read(fd2, rbuff, 60);			//reading from data.txt & saving it to rbuff[]	
	printf("Data in data.txt -\n%s\n",rbuff);	//printing the read data from file data.txt
	
	len = write(fd1, rbuff, 60);			//writing to 'new.txt'
	
	printf("Data written to new.txt\n");
	
	lseek(fd2, 5, SEEK_SET);			//lseek fd2 by 5
	read(fd2, rbuff, 50);
	printf("After lseek -- data read = %s\n",rbuff);
	
	close(fd2);
	close(fd1);
}
