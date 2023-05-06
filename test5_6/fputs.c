#include <stdio.h>

int main(void)
{
	FILE *fp=fopen("5.txt","r+");
	
	char buf[10]="holle";
	fputs(buf,fp);
	char a[10]={0};
	rewind(fp);
	fscanf(fp,"%s",a);
	printf("%s\n",a);
	fclose(fp);
	return 0;
}