/*
25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call)
*/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    int parent_pid = getpid();
    int wstatus;
    pid_t cpid1, cpid2, cpid3;
    printf("Parent Process PID %d\n", parent_pid);
    cpid1 = fork();
    if(cpid1 == 0){
        sleep(5);
    }
    else{
        cpid2 = fork();
        if(cpid2 == 0){
            sleep(10);
        }
        else{
            cpid3 = fork();
            if(cpid3 == 0){
                sleep(15);
            }
        }

    }
    if(parent_pid == getpid()){
        printf("Child PIDs are\n");
        printf("Child 1 PID: %d\n", cpid1);
        printf("Child 2 PID: %d\n", cpid2);
        printf("Child 3 PID: %d\n", cpid3);
        printf("Waiting for Child 2 PID %d\n", cpid2);
        pid_t return_wait = waitpid(cpid2, &wstatus, 0);
        if(return_wait == cpid2){
            printf("Parent successfully waited for Child 2, Return value is %d\n", return_wait);
        }
        else{
            perror("Error: ");
        }
    }
    return 0;
}
/* output
$ ./a.out
Parent Process PID 16309

Child PIDs are
Child 1 PID: 16310
Child 2 PID: 16311
Child 3 PID: 16312
Waiting for Child 2 PID 16311
Parent successfully waited for Child 2, Return value is 16311*/
