/*
    19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
*/

#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int main(){
		uint64_t time1 = rts();
		int pid = getpid();
		uint64_t time2 = rts();
		printf("Time to execute pid() is %lfs\n",(double)time2-(double)time1);
	return 0;
}
