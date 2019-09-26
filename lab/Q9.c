/*
	9. Write a program to print the following information about a given file.
		a. inode
		b. number of hard links
		c. uid
		d. gid
		e. size
		f. block size
		g. number of blocks
		h. time of last access
		i. time of last modification
		j. time of last change
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
	struct stat file;
	int stat_return;
	int fd1 = open("myfile_9.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	char arr[] = "Test message\nHello World";
	write(fd1, arr, sizeof(arr));
	close(fd1);

	stat("myfile_9.txt", &file);
	printf("Inode of the given file: %ld\n", file.st_ino);
	printf("Number of Hard Links of the given file: %ld\n", file.st_nlink);
	printf("UID of the given file: %d\n", file.st_uid);
	printf("GID of the given file: %d\n", file.st_gid);
	printf("Size of the given file: %ld\n", file.st_size);
	printf("Block Size of the given file: %ld\n", file.st_blksize);
	printf("Number of Blocks of the given file: %ld\n", file.st_blocks);
	printf("Time of Last Access of the given file: %ld\n", file.st_atime);
	printf("Time of Last Modification of the given file: %ld\n", file.st_mtime);
	printf("Time of Last Change of the given file: %ld\n", file.st_ctime);
	return 0;
}
