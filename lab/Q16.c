/*
16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
*/
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char **argv) {
  if (argc > 1) {
    int fd = open(argv[1], O_WRONLY);

    if(fd == -1) {
      printf("Unable to open the file\n");
      exit(1);
    }
    static struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_start = 0;
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;
    lock.l_pid = getpid();

    int ret = fcntl(fd, F_SETLKW, &lock);
    printf("Return value of fcntl:%d\n",ret);
    printf("Enter to unlock..\n");
    getchar();
printf("\n release lock \n");

lock.l_type   = F_UNLCK;
fcntl(fd, F_SETLK, &lock); /* unset lock */
}
  }
