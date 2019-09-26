/*
    12. Write a program to find out the opening mode of a file. Use fcntl.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
    int fd = open("myfile_12.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	char buffer_start[] = "International institute of information technology ,bangalore\nHello World";
	write(fd, buffer_start, sizeof(buffer_start));
	close(fd);

    fd = open("dummy1_12.txt", O_WRONLY);
    int open_mode = fcntl(fd, F_GETFL, 0)&O_ACCMODE;
    printf("%d",fcntl(fd, F_GETFL, 0));
    if(open_mode == O_RDONLY)
        printf("Read Only\n");
    else if(open_mode == O_RDWR)
        printf("Read Write\n");
    else if(open_mode == O_WRONLY)
        printf("Write Only\n");
    else
        printf("Unknown access mode\n");
    close(fd);
    return 0;
}
