#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

int main(void)
{
	FILE *fp=fopen("1.txt","r+");
	if(fp==NULL)
	{
		perror("open file failed!");
		return -1;
	}
	else
	{
		printf("打开文件成功!\n");
		fclose(fp);
	}
	return 0;
}