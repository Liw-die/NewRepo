#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
	char filem[20];
	printf("输入你要打开的文件名目录：");
	scanf("%s",filem);
	getchar();
	int fd=open(filem,O_RDWR);
	if(fd==-1)
	{
		printf("文件不存在,是否创建该文件0/1:");
		int temp;
		scanf("%d",&temp);
		getchar();
		if(temp==1)
		{
			open(filem,O_RDWR|O_CREAT,0777);
			printf("文件创建成功\n");
		}
		else
			return 0;
	}
/* 	else
	{
		open(filem,O_RDWR|O_TRUNC);
		printf("文件清空成功\n");
	} */
	//open(filem,O_RDWR|O_TRUNC);
	//printf("文件清空成功\n");
	
	char buf[25];
	int ret;
	bzero(buf,25);
	

	
	//bzero(buf,25);
	ret=read(fd,buf,5);
	printf("读取%d个字符成功!->%s\n",ret,buf);
	
	printf("输入你要写入的数据:");
	scanf("%s",buf);
	ret=write(fd,buf,strlen(buf));
	printf("写入%d个字符成功!\n",ret);
	
	lseek(fd,0,SEEK_SET);
	bzero(buf,25);
	ret=read(fd,buf,5);
	printf("读取%d个字符成功!->%s\n",ret,buf);
	close(fd);
	
	return 0;
}