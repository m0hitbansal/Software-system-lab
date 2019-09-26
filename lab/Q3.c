/*
    3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
void display(int val){
  printf("%d\n",val);
}
int main(int argc, char const *argv[])
{
    int create_return = creat("dummy1_3.txt", 0644);
     display(create_return);
    return 0;
}
