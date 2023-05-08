#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *judge_power(const unsigned int _mode,char *arr)//权限转rwx-
{
	short port = 0xFFF;
	port &= _mode;
	//printf("port=%o\n",port);
	int a;
	for(int i=0;i<9;i++)
	{
		a = 0x01 & (port>>(8-i));
		if(a == 1)
		{
			if(i%3 == 0)
				arr[i]='r';
			else if(i%3 == 1)
				arr[i]='w';
			else if(i%3 == 2)
				arr[i]='x';
		}
		else
			arr[i]='-';
	}
	return arr;
}
void page_file(char *filename)
{
	struct stat *sb;
	char arr[10]={0};
	sb = (struct stat*) malloc(sizeof(struct stat));
	if (stat(filename,sb)==-1)
	{
		printf("打开失败\n");
		return ;
	}
	
	if (S_ISREG(sb->st_mode))//如果为普通文件
	{

		stpcpy(arr,judge_power(sb->st_mode,arr));
		printf("[--普通文件--%s--%ld--%s]\n",arr,sb->st_size,filename);
	}
	
	if (S_ISDIR(sb->st_mode))//如果为目录文件
	{
		DIR *pp=opendir(filename);//打开目录
		if(pp==NULL)
		{
			printf("该目录/文件不存在\n");
			closedir(pp);
			return ;
		}
		struct dirent *pd=readdir(pp);//读取目录
		if(pd==NULL)
		{
			printf("目录读取失败\n");
			closedir(pp);
			return ;
		}
		chdir(filename);
		while(pd!=NULL)
		{
			struct stat *file_sb;
			file_sb = (struct stat*) malloc(sizeof(struct stat));
			if ((stat(pd->d_name,file_sb))==-1)
			{
				//printf("%d]\n",pd->d_name);
				printf("获取文件[%s]失败\n",pd->d_name);
				goto _pd;
			}
			bzero(arr,sizeof(arr));
			stpcpy(arr,judge_power(file_sb->st_mode,arr));//将权限识别函数返回值的
			if(pd->d_type==DT_UNKNOWN)
				printf("[--未知文件--%s--%ld--%s]\n",arr,file_sb->st_size,pd->d_name);
			if(pd->d_type==DT_FIFO)
				printf("[--管道文件--%s--%ld--%s]\n",arr,file_sb->st_size,pd->d_name);
			if(pd->d_type==DT_CHR)
				printf("[--字符设备文件--%s--%ld--%s]\n",arr,file_sb->st_size,pd->d_name);
			if(pd->d_type==DT_DIR)
				printf("[--目录文件--%s--%ld--%s]\n",arr,file_sb->st_size,pd->d_name);
			if(pd->d_type==DT_BLK)
				printf("[--块设备文件--%s--%ld--%s]\n",arr,file_sb->st_size,pd->d_name);
			if(pd->d_type==DT_REG)
				printf("[--普通文件--%s--%ld--%s]\n",arr,file_sb->st_size,pd->d_name);
			if(pd->d_type==DT_LNK)
				printf("[--链接文件--%s--%ld--%s]\n",arr,file_sb->st_size,pd->d_name);
			if(pd->d_type==DT_SOCK)
				printf("[--套接字文件--%s--%ld--%s]\n",arr,file_sb->st_size,pd->d_name);
			_pd:
			pd=readdir(pp);
			free(file_sb);
		}
		
		closedir(pp);		
	}
		
}
		
int main(void)
{
	char arr[50]={0};
	scanf("%s",arr);
	page_file(arr);
	
	return 0;
}