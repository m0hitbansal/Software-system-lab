/*
    15. Write a program to display the environmental variable of the user (use environ).
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

extern char **environ;
int main()
{
    int count = 0;
    while(environ[count] != NULL)
    {
        printf("%s\n", environ[count]);
        count++;
    }
    return 0;
}
/*output



:/bin:/usr/games:/usr/local/games:/snap/bin:/home/mohit/.local/bin:/home/mohit/.local/bin
GJS_DEBUG_TOPICS=JS ERROR;JS LOG

SESSION_MANAGER=local/mohit-300E4Z-300E5Z-300E7Z:@/tmp/.ICE-unix/1255,unix/mohit-300E4Z-300E5Z-300E7Z:/tmp/.ICE-unix/1255
LESSOPEN=| /usr/bin/lesspipe %s
GTK_IM_MODULE=ibus
_=./a.out*/
