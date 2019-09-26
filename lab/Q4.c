/*
    4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
void display(int val){
  printf("%d\n",val);
}
int main(int argc, char const *argv[])
{
    int fd1 = open("myfile_4.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	char arr[] = "Test message\nHello World";
	write(fd1, arr, sizeof(arr));
	close(fd1);
    fd1 = open("myfile_4.txt", O_RDWR);
     display( fd1);
    close(fd1);

    // Trying with O_EXCL flag
   int fd2 = open("myfile_4.txt", O_CREAT|O_RDONLY|O_EXCL, 0644);
    if (fd2==-1){
        perror("Error");
    }

    return 0;
}
/*
output
mohit@mohit-300E4Z-300E5Z-300E7Z:~/Downloads/software system/lab$ ./a.out
3
Error: File exists
*/
