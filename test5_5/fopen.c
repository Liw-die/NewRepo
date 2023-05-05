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
	char buf[25];
	bzero(buf,sizeof(buf));
	int ret=fread(buf,5,5,fp);
	printf("ret=%d buf=%s\n",ret,buf);
	fclose(fp);
	return 0;
}