#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	struct stat *sb;
	sb=(struct stat*)malloc(sizeof(struct stat));
	if(stat("1.txt",sb)==-1)
	{
		printf("打开失败\n");
		return -1;
	}
	printf("%ld\n",sb->st_size);
	printf("%o\n",sb->st_mode);
	//if((sb->st_mode & S_IFMT) == S_IFREG)
	int a=0555;
	printf("%o\n",a);
	int arr[9];
	/* for(int i=0;i<9;i++)
	{
		arr[i]=(a>>j)&0x0001;
		j--;
		printf("%d\n",arr[i]);
	} */
	//j=8
	for(int i=0;i<9;i++)
	{
		int b=0x01&(a>>(8-i));
		if(b==1)
		{	
			if(i%3==0)
				printf("r");
			if(i%3==1)
				printf("w");
			if(i%3==2)
				printf("x");
		}
		else
			printf("-");
	}
	printf("\n");
			
	if(S_ISREG(sb->st_mode))
	{
		printf("普通文件\n");
	}
	return 0;
}