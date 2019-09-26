/*
27. Write a program to execute ls -Rl by the following system calls
    a. execl
    b. execlp
    c. execle
    d. execv
    e. execvp
*/

#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    int execl_return1 = execle("/bin/ls", "ls", "-Rl", (char *)NULL, (char *)NULL);
    perror("Error: ");
    printf("%d\n", execl_return1);
    return 0;
}
