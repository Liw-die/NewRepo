#include <stdio.h>

int main(void)
{
	char buf[10];
	gets(buf);
	printf("%s",buf);
	return 0;
}