/*
    24. Write a program to create an orphan process.
*/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int child_pid = fork();
    if(child_pid > 0){
        printf("Parent Process\n");
        printf("Parent process PID %d\n", getpid());
    }
    else if(child_pid == 0){
        printf("Child Process\n");
        printf("Before Sleep: Child Process parent PID %d\n", getppid());
        sleep(10);
        printf("After Sleep: Child Process parent PID %d\n", getppid());


    }
    return 0;
}
/*
output
$ ./a.out
Parent Process
Parent process PID 15406
Child Process
Before Sleep: Child Process parent PID 15406
mohit@mohit-300E4Z-300E5Z-300E7Z:~/Downloads/software system/lab$ After Sleep: Child Process parent PID 1
*/
