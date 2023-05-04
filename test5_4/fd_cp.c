#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

#define SIZ 1024

void file_cp(const char *source_filename,const char *bourn_filename)
{
	int fd_sou=open(source_filename,O_RDONLY);
	if(fd_sou==-1)
	{
		printf("文件不存在,是否创建该文件0/1:");
		int temp;
		scanf("%d",&temp);
		getchar();
		if(temp==1)
		{
			fd_sou=open(source_filename,O_RDWR|O_CREAT,0777);
			printf("%s文件创建成功\n",source_filename);
		}
		else
			return ;
	}
	int fd_bou=open(bourn_filename,O_RDWR);
	if(fd_bou==-1)
	{
		printf("文件不存在,是否创建该文件0/1:");
		int temp;
		scanf("%d",&temp);
		getchar();
		if(temp==1)
		{
			fd_bou=open(bourn_filename,O_RDWR|O_CREAT,0777);
			printf("%s文件创建成功\n",bourn_filename);
		}
		else
			return ;
	}
	int res;
	char temp[SIZ];
	bzero(temp,sizeof(temp));
	lseek(fd_bou,0,SEEK_SET);
	int i=0,te;
	while((res=read(fd_sou,temp,SIZ))>0)
	{
		i++;
		printf("res=%d写入完成->%d\n",res,i);
		if((te=write(fd_bou,temp,SIZ))!=res)
		{
			printf("te=%d写入完成!\n",te);
			close(fd_sou);
			close(fd_bou);
		}
	}
}

int main(void)
{
	char sou_fil[15]= "ikun.txt";
	char bou_fil[15]= "4.txt";
	//bzero(sou_fil,sizeof(sou_fil));
	//bzero(bou_fil,sizeof(bou_fil));
	//printf("请输入两个文件的地址：");
	//scanf("%s %s",sou_fil,bou_fil);
	file_cp(sou_fil,bou_fil);
	return 0;
}