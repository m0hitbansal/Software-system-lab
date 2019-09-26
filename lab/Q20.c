/*
    20. Find out the priority of your running program. Modify the priority with nice command.
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
    int i = 0, before_mod, after_mod;

    before_mod = nice(0);
    printf("Priority of the program is %d\n", before_mod);
    while(1){
        if(i<0)
            break;
        i++;
    }
    printf("Modifying priority of the program to -7\n");
    after_mod = nice(-7);
    if(after_mod == -1){
        perror("Error: ");
        return -1;
    }
    printf("Priority of the program is %d\n", after_mod);
    return 0;
}
