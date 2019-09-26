/*
	7. Write a program to copy file1 into file2 ($cp file1 file2).
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
	int fd1 = open("myfile_7.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	char buffer_start[] = "Test message\nHello World";
	write(fd1, buffer_start, sizeof(buffer_start));
	close(fd1);

	fd1 = open("myfile_7.txt", O_RDONLY);
	int fd2 = open("myfile2_7.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	char buffer[1024];
	printf("%d\n",fd2);
	int count;
	count = read(fd1, buffer, sizeof(buffer));
	 write(fd2, buffer, count);
	 printf("%d\n", count);
	return 0;
}
