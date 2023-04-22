#include <stdio.h>
#include <stdlib.h>

void func(void);
int main(void)
{
	extern int a;
	int b=0;
	static int c;
	a += 3;
	func();
	b += 3;
	func();
	return 0;
}
int a=5;

void func(void)
{
	int b=3;
	static int c=2;
	a += 5;
	b += 5;
	c += 5;
	printf("%d, %d, %d\n", a, b, c);
	c=b;
}

