/*
	6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
	char buffer[1024];
	int  count;
	count = read(1, buffer, sizeof(buffer));
	 write(1, buffer, count);
	 printf("%d\n", count);
	return 0;
}
