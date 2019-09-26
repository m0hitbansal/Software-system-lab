/*
    23. Write a program to create a Zombie state of the running program.
*/
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main(int argc, char const *argv[])
{
    pid_t child_pid = fork();
    if(child_pid > 0){
        sleep(15);
    }
    else{
        exit(0);
    }
    return 0;
}