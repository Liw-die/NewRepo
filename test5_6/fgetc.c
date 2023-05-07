#include <stdio.h>

int main(void)
{
	FILE *fp=fopen("1.txt","r+");
	if(fp==NULL)
	{
		perror("error!");
		fclose(fp);
		return -1;
	}
	char a=fgetc(fp);
	printf("%d\n",a);
	
	fclose(fp);
	return 0;
}
	
