#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp=fopen("5.txt","r+");
	if(fp==NULL)
	{
		perror("error!");
		fclose(fp);
		return -1;
	}
	char str[50];
	int a;
	int b;
	char arr[50];
	bzero(str,sizeof(str));
	
	fscanf(fp,"%[^\n]",arr);
	printf("%s\n",arr);
	bzero(str,sizeof(str));
	for(int i=0;i<3;i++)
	{
		fscanf(fp,"%s %d %d",str,&a,&b);
		printf("%s \t%d \t%d\n",str,a,b);
	}
	fclose(fp);
	return 0;
}
	