#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
int main()
{
	struct itimerval val;
	val.it_interval.tv_usec=0;
	val.it_interval.tv_sec=0;
	val.it_value.tv_usec=0;
	val.it_value.tv_sec=10;
	setitimer(ITIMER_VIRTUAL,&val,NULL);
	return 0;
}
