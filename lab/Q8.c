/*
	8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
	Close the file when end of file is reached.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
	char c;
	int count;

	int fd1 = open("myfile_8.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	char buffer_start[] = "Test message\nHello World";
	write(fd1, buffer_start, sizeof(buffer_start));
	close(fd1);

	int fd = open("myfile_8.txt", O_RDONLY);
	while (count = read(fd, &c, 1))
	{
		if(c=='\n'){
			printf("\n");
		}
		else{
			write(1, &c, 1);
		}
	}
	close(fd);

	return 0;
}
