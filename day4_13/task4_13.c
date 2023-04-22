#include <stdio.h>
#include <stdlib.h>

int fun()
{
	static int a = 0;
	return ++a;
}

int main()
{
	int i = 0;
	int time = 0;
	for (i = 0; i < 10; i++)
	{
		time = fun();
	}
	printf("函数一共调用了%d次\n", time );
	return 0;

}

