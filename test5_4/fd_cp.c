#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>


void file_cp(int fd_source,int fd_bourn)
{
}

int main(void)
{
	int fd_source=open("3.txt",O_RDONLY);
	int fd_bourn=open("4.txt",O_RDWR);