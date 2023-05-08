#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *judge_power(unsigned int _mode,char *arr)
{
	short port = 0xFFF;
	port &= _mode;
	printf("port=%o\n",port);
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
	sb = (struct stat*) malloc(sizeof(struct stat));
	if (stat(filename,sb)==-1)
	{
		printf("打开失败\n");
		return ;
	}
	if (S_ISREG(sb->st_mode))//如果为普通文件
	{
		char arr[10]={0};
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
		while(pd!=NULL)
		{
			if(pd->d_type==DT_REG)
				printf("[%s]是一个普通文件\n",pd->d_name);
			if(pd->d_type==DT_DIR)
				printf("[%s]是一个目录文件\n",pd->d_name);
			pd=readdir(pp);
		}	
	}
		
}
		
int main(void)
{
	page_file("\\");
	
	return 0;
}