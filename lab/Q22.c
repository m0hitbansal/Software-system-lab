/*
    22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
    parent processes. Check output of the file.
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd;
    char data1[] = "This is parent's data\n";
    char data2[] = "This is child's data\n";
	  pid_t child_pid;
    fd = open("myfile_22.txt", O_CREAT|O_TRUNC|O_RDWR, 0644);

    child_pid = fork();
    if(child_pid == 0){
        write(fd, data2, sizeof(data2));
    }else{
        write(fd, data1, sizeof(data1));
    }
    close(fd);
    return 0;
}
