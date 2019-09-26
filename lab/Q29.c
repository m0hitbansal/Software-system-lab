#include<stdio.h>
#include<sched.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{

    struct sched_param param_scheduler;
    param_scheduler.sched_priority = 2;
    printf("Scheduling Policy: %d\n", sched_getscheduler(getpid()));
    printf("Modifying the scheduling policy SCHED_FIFO\n");
    if(sched_setscheduler(getpid(), SCHED_FIFO, &param_scheduler) != -1){
        printf("Modified Successfully\n");
        printf("Scheduling Policy: %d\n", sched_getscheduler(getpid()));
    }
    else{
        perror("Error: ");

    }

    printf("Modifying the scheduling policy SCHED_RR\n");
    if(sched_setscheduler(getpid(), SCHED_RR, &param_scheduler) != -1){
        printf("Modified Successfully\n");
        printf("Scheduling Policy: %d\n", sched_getscheduler(getpid()));
    }
    else{
        perror("Error: ");

    }

    return 0;
}
