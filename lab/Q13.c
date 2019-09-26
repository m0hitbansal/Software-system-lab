/*
    13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
    verify whether the data is available within 10 seconds or not (check in $man 2 select).
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    fd_set readfd1;
    struct timeval t1;
    int select_return;
    FD_ZERO(&readfd1);
    FD_SET(0, &readfd1);
    t1.tv_sec = 10;
    t1.tv_usec = 0;
    select_return = select(1, &readfd1, NULL, NULL, &t1);
    if(select_return){
        printf("Data is available now\n");
    }
    else{
        printf("No data was available within 10 seconds\n");
    }
    return 0;
}
/*output
$ ./a.out
No data was available within 10 seconds

$ ./a.out
hfghf
Data is available now
*/
