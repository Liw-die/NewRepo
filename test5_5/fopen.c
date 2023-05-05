#include <stdio.h>
#include <strings.h>
#include <string.h>
#define SIZE 1024

void file_cp(const char *source_filename,const char *bourn_filename)
{
	FILE *fp_sou=fopen(source_filename,"r");
	FILE *fp_bou=fopen(bourn_filename,"w");
	if(fp_sou==NULL)
	{
		perror("你的源文件为空!");
		fclose(fp_sou);
		return ;
	}
	int ret,count;
	fseek(fp_sou,0,SEEK_END);
	int len=ftell(fp_sou);
	ret=len/SIZE;
	printf("%d %d\n",ret,len);
	fseek(fp_sou,0,SEEK_SET);
	char buf[SIZE+1];
	while(ret)
	{
		fread(buf,SIZE,1,fp_sou);
		count=fwrite(buf,SIZE,1,fp_bou);
		printf("count=%d\n",count);
		bzero(buf,sizeof(buf));
		ret--;
	}
	bzero(buf,sizeof(buf));
	ret=fread(buf,1,SIZE,fp_sou);
	count=fwrite(buf,ret,1,fp_bou);
	printf("count=%d\n",count);
	fclose(fp_sou);
	fclose(fp_bou);
}
int main(void)
{
	char sou_fil[15]= "ikun.txt";
	char bou_fil[15]= "4.txt";
	file_cp(sou_fil,bou_fil);
/* 	FILE *fp=fopen("1.txt","a");
	if(fp==NULL)
	{
		perror("open file failed!");
		return -1;
	}
	char buf[24]="0123456789012345678901";
	//bzero(buf,sizeof(buf));
	//int ret=fread(buf,5,5,fp);
	//int ret=fwrite(buf,5,5,fp);
	//printf("ret=%d buf=%s\n",ret,buf);
	int n=ftell(fp);
	printf(" n=%d\n",n);
	fclose(fp) */;
	return 0;
}