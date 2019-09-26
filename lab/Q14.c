/*
    14 Write a program to find the type of a file.
        a. Input should be taken from command line.
        b. program should be able to identify any type of a file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    struct stat file1;
    if(argc != 2){
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    /*if(lstat(argv[1], &file1) == -1){
        perror("lstat");
        exit(EXIT_FAILURE);
    }*/
    stat(argv[1], &file1);
    printf("File type of the given file is\n");
    switch (file1.st_mode & __S_IFMT) {
        case __S_IFBLK:
            printf("block device\n");
            break;
        case __S_IFCHR:
            printf("character device\n");
            break;
        case __S_IFDIR:
            printf("directory\n");
            break;
        case __S_IFIFO:
            printf("FIFO/pipe\n");
            break;
        case __S_IFLNK:
            printf("symlink\n");
            break;
        case __S_IFSOCK:
            printf("socket\n");
            break;
        default:
            printf("regular file\n");
            break;
    }
    return 0;
}
/*output
$ ./a.out mohit
File type of the given file is
FIFO/pipe
*/
