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
	int fd, dup_return;
	char buffer1[] = "This is some random data\n";
	ssize_t bytes_written;
	fd = open("myfile_11.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	printf("Duplicating the file descriptor using 'dup' for file descriptor %d\n", fd);
	dup_return = dup(fd);
	printf("dup return value is %d\n", dup_return);
	printf("Writing with file descriptor\n");
	write(fd, buffer1, sizeof(buffer1)-1);
	char buffer2[] = {"Hello World\n"};
	printf("Writing with duplicate file descriptor\n");
	bytes_written = write(dup_return, buffer2, sizeof(buffer2)-1);
	if(bytes_written>0){
		printf("File written successfully, Number of bytes written are %ld\n", bytes_written);
	}
	else{
		printf("File not written properly, Bytes written are %ld\n", bytes_written);
	}
	return 0;
}
/*output
$ ./a.out
Duplicating the file descriptor using 'dup' for file descriptor 3
dup return value is 4
Writing with file descriptor

Writing with duplicate file descriptor
File written successfully, Number of bytes written are 12

file data
-------This is some random data
Hello World
-----
*/
