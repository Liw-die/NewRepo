#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp=fopen("5.txt","w+");
	if(fp==NULL)
	{
		perror("error!");
		fclose(fp);
		return -1;
	}
	char *arr=(char *)malloc(sizeof(char)*10);
	bzero(arr,sizeof(arr));
	for(int i=0;i<3;i++)
	{
		scanf("%s",arr);
		fprintf(fp,"%s\n",arr);
		bzero(arr,sizeof(arr));
	}
	fclose(fp);
	return 0;
}