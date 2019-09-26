#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){

	int ptr;
	struct{
		int ticket;
	}entry;
	entry.ticket = 10;
	ptr = open("mydb",O_CREAT|O_RDWR,0744);
	write(ptr,&entry,sizeof(entry));
	close(ptr);
	ptr = open("mydb",O_RDONLY);
	read(ptr,&entry,sizeof(entry));
	printf("Ticket Number %d\n",entry.ticket);
	return 0;
}
