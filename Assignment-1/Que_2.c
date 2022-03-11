/***
Program to demonstrate repositioning of file offset using SEEK_SET, SEEK_CUR
and SEEK_END.
***/

#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, fd3;
	int len=0;


	char wbuff[] = "This is VM5 Writing data to write1.txt file\n";

	//write to write.txt
	
	fd1 = open("write.txt", O_CREAT | O_RDWR, 0666);
	len = write(fd1 , wbuff, sizeof(wbuff));
	printf("File descriptor fd1 : %d\nData written length is: %d\n",fd1,len);


	lseek(fd1, 0, SEEK_SET);		//set cursor to beginning


	char rbuff[len];

	//read from write.txt
	
	read(fd1, rbuff, len);
	printf("File contents are: %s",rbuff);
	close(fd1);


	int length=0;
	char buffer[]="This file contains test data to perform concept of lseek and it's flags: SEEK_SET, SEEK_CUR, SEEK_END";
	int curr=0;


	curr = lseek(fd1, 0, SEEK_CUR);
	printf("Current position of file is: %d\n",curr);


	fd2 = open("write.txt", O_RDWR, 0666);
	lseek(fd2, 0, SEEK_END);


	length = write(fd2 , buffer, sizeof(buffer));
	printf("File descriptor returned by fd2 is: %d and data written length is: %d\n",fd1,length);


	lseek(fd2, len, SEEK_SET);
	char buffer1[length];


	read(fd2, buffer1, length);
	printf("File contents are: %s\n",buffer1);


	close(fd2);


	return 0;
}
