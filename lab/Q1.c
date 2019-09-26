/*
    1. Create the following types of a files using (i) shell command (ii) system call
        a. soft link (symlink system call)
        b. hard link (link system call)
        c. FIFO (mkfifo Library Function or mknod system call)
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char const *argv[])
{
    int fd1 = open("mohit.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	char buffer_start[] = "Test message\nHello World";
	write(fd1, buffer_start, sizeof(buffer_start));
	close(fd1);
    const char target[] = "./mohit.txt";
    const char linkpath[] = "./soft_linkfile_1.txt";
    // Creating soft link
    int sf_link = symlink(target, linkpath);
     printf("%d\n", sf_link);

    // Creating hard link
    const char h_linkpath[] = "./hard_linkfile_2.txt";
    int hd_link = link(target, h_linkpath);
     printf("%d\n", hd_link);

    // Creating a special file, fifo file
    const char mk_file[] = "./fifofile.txt";
    int mk_return = mknod(mk_file, __S_IFIFO, 0);
    printf("%d\n", mk_return);
                              /* $ mkfifo pipename
                                 $ echo "foo" > pipename
                                other terminal
                                $ cat < pipename
                                  foo*/
    return 0;
}
