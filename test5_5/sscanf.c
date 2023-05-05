#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

	char arr[20]="hello-123-3.14";
	char buf[10];
	int a;
	float b;
	sscanf(arr,"%[^-]-%d-%f",buf,&a,&b);
	printf("%s\n",arr);
	printf("%s\n",buf);
	printf("%d\n",a);
	printf("%.2f\n",b);
	return 0;
}