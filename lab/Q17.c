#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>


int main(){
	struct flock mylock;
	struct{
		int tic_no;
	}entry;
	int ptr = open("mydb",O_RDWR);
	read(ptr,&entry,sizeof(entry));
	mylock.l_type = F_WRLCK;
	mylock.l_whence = SEEK_SET;
	mylock.l_start = 0;
	mylock.l_len = 0;
	mylock.l_pid = getpid();
	printf("Before entering into critical section\n");
	int jayant = fcntl(ptr,F_SETLKW,&mylock);
	printf("Current ticket number %d\n",entry.tic_no);
	entry.tic_no++;
	lseek(ptr,0L,SEEK_SET);
	printf("Inside the critical section\n");
	printf("Enter to unlock..\n");
	int tiwari = write(ptr,&entry,sizeof(entry));
	printf("%d\n",tiwari);
	getchar();
	mylock.l_type = F_UNLCK;
	printf("Unlocked\n");
	fcntl(ptr,F_SETLK,&mylock);
	printf("Fin!");
	return 0;
}
