#include <stdio.h>
int a=0;
int b;
static char c;
int main(int avgc,const char *argv[])
{
	char d=4;
	static short e;
	a++;
	b=100;
	c=(char)++a;
	//e=(++d)++;
	printf("a=%d b=%d c=%d d=%d e=%d\n",a,b,c,d,e);
	return 0;
}

