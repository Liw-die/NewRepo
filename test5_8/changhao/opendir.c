#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
	//chdir("../test5_7");
	char arr[50]={0};
	getcwd(arr,sizeof(arr));
	mkdir("./mdaksd",0777);
	DIR *pd=opendir(arr);
	if(pd==NULL)
	{
		perror("dir open failed!");
		return -1;
	}
	//FILE *d=fopen("9.txt","w+");
	struct dirent *p=readdir(pd);
	while(p!=NULL)
	{
		if(p->d_type==DT_REG)
			printf("[%s]是一个普通文件-%d\n",p->d_name,p->d_type);
		if(p->d_type==DT_DIR)
			printf("[%s]是一个目录文件\n",p->d_name);
		p=readdir(pd);
	}
	
	//fclose(d);
	closedir(pd);
	return 0;
}