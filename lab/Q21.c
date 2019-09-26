/*
    21. Write a program, call fork and print the parent and child process id.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t parent_pid, child_pid;
    parent_pid = getpid();
    printf("Parent process id is %d\n", parent_pid);
    child_pid = fork();
    if(child_pid > 0){
        printf("Child process id is %d\n", child_pid);
    }
    return 0;
}
/*output
./a.out
Parent process id is 14661
Child process id is 14662
*/
