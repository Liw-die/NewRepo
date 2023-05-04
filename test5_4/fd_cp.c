#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#define SIZ 1024

void file_cp(int fd_source,int fd_bourn)
{
	char buf[SIZ];
	bzero(buf,SIZ);
	int ret;
	ret=read(fd_source,buf,SIZ);
	write(fd_bourn,buf,strlen(buf));
	printf("ret=%d write->%s \n",ret,buf);
}

int main(void)
{
	int fd_source=open("3.txt",O_RDONLY);
	int fd_bourn=open("4.txt",O_RDWR);
	file_cp(fd_source,fd_bourn);
	close(fd_source);
	close(fd_bourn);
	
	return 0;
}