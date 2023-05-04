#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
	int fd=open("2.txt",O_RDWR);
	if(fd==-1)
	{
		printf("文件不存在,是否创建该文件0/1:");
		int temp;
		scanf("%d",&temp);
		getchar();
		if(temp==1)
		{
			open("2.txt",O_RDWR|O_CREAT,0777);
			printf("文件创建成功\n");
		}
		else
			return 0;
	}
	char *p=(char *)mmap(NULL,30,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	printf("p=%s\n",p);
	
	munmap(p,10);
	close(fd);
	return 0;
}