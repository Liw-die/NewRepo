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
	char arr[50];
	int a;
	float b;
	bzero(arr,sizeof(arr));
	fprintf(fp,"姓名\t年龄\t长度\n");
	int len;
	scanf("%d",&len);
	for(int i=0;i<len;i++)
	{
		scanf("%s%d%f",arr,&a,&b);
		fprintf(fp,"%s\t%d\t%.2f\n",arr,a,b);
		bzero(arr,sizeof(arr));
	}
	fclose(fp);
	return 0;
}