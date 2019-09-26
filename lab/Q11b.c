/*
	11. Write a program to open a file, duplicate the file descriptor and append the file with both the
	descriptors and check whether the file is updated properly or not.
	a. use dup
	b. use dup2
	c. use fcntl
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
	int fd, fd1=10;
	char buffer1[] = {"This is some random data"};
	char buffer2[] = {"Hello World\n"};
	ssize_t count;
	close(fd1);
	fd = open("myfile2_11.txt", O_CREAT|O_RDWR|O_TRUNC, 0644);
	printf("Duplicating the file descriptor using 'dup2' for file descriptor %d\n", fd);
  int val=dup2(fd, fd1);

	printf("return value of dup2 is %d\n", val);
	printf("Writing with file descriptor\n");
	write(fd, buffer1, sizeof(buffer1)-1);
	off_t lseek_cursor = lseek(fd1, -10, SEEK_CUR);  //change pointer 
	printf("Writing with duplicate file descriptor\n");
	count = write(fd1, buffer2, sizeof(buffer2)-1);
	return 0;
}
/*output
$ ./a.out
Duplicating the file descriptor using 'dup2' for file descriptor 3
return value of dup2 is 10

Writing with file descriptor
Writing with duplicate file descriptor


file output----------------
This is some rHello World
*/
