/*
	10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
		bytes (use lseek) and write again 10 bytes.
		a. check the return value of lseek
		b. open the file with od and check the empty spaces in between the data.
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
	int fd;
	char buffer1[] = "This is a test message\n";
	char buffer2[] = "Dummy message, doesn't mean anything\n";
	off_t lseek_cursor;
	ssize_t size_written;
	fd = open("myfile_10.txt", O_CREAT | O_RDWR| O_TRUNC, 0644);
	size_written = write(fd, buffer1, 10);
	printf("Moving file pointer by 10 bytes\n");
	lseek_cursor = lseek(fd, 10, SEEK_CUR);
	size_written = write(fd, buffer2, 20);
	printf("lseek returns %ld\n", lseek_cursor);

	/* Output
	mohit@mohit-300E4Z-300E5Z-300E7Z:~/Downloads/software system/lab$ ./a.out
  Moving file pointer by 10 bytes
  lseek returns 0
	$ od -c myfile_10.txt
	0000000   D   u   m   m   y       m   e   s   s   a   g   e   ,       d
	0000020   o   e   s   n
	0000024
	*/
	return 0;
}
