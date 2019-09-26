/*
26. Write a program to execute an executable program.
    a. use some executable program
    b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/

#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    int execl_return1 = execl("/home/mohit/Downloads/software system/a.out", "26_ExecutableProgram","mohit", (char *)NULL);
    printf("%d\n", execl_return1);
    return 0;
}
/* output
./a.out
Hello mohit*/
