/*
    5. Write a program to create five new files with infinite loop. Execute the program in the background
    and check the file descriptor table at /proc/pid/fd.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    int count = 1;
    int fd[5];
    for(;;){
        if(count <= 5){
            char integer_string[2];
            sprintf(integer_string, "%d", count);

            char filename[1024] = "dummy";
            char postfix_filename[1024] = "_5.txt";
            strcat(filename, integer_string);
            strcat(filename, postfix_filename);
            fd[count-1] = creat(filename, 0644);
            ++count;
        }
    }
    return 0;
}
