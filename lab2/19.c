#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char const *argv[])
{
	int ch,d=1;
	int a;
	printf("\n enter 1 for mknod command 2 for mkfifo command 3 for strace 4 for mknod sys call 5 for mkfifo lib function\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
execl("/bin/mknod", "mknod", "19a_fifo_file1", "p", (char *)NULL);
	break;
	case 2:
execl("/usr/bin/mkfifo", "mkfifo", "19b_fifo_file2", (char *)NULL);
	break;
	case 3:
	execlp("/usr/bin/strace", "strace", "-c", "mknod", "19c_fifo_file1", "p", (char *)NULL);
	execlp("/usr/bin/strace", "strace", "-c", "mkfifo", "19c_fifo_file2", (char *)NULL);
	break;
	case 4:
mknod("mk_file", __S_IFIFO|S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH, 0);
	break;
	case 5:
mkfifo("mk_file1", S_IWGRP|S_IRGRP|S_IRUSR|S_IWUSR|S_IROTH);
	break;

	default:
		printf("error\n");
		return 0;
}
return 0;
}
