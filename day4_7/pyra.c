#include <stdio.h>
//#include <math.h>

int main()
{
	int i, j, n;
	for (i = 1; i <= 4; i++)//上半部分
	{
		for (j = 4; j > i; j--)
		{
			printf(" ");
		}
		for (n = (2 * i - 1); n >= 1; n--)
		{
			printf("*");
		}
		printf("\n");
	}

	for (i = 3; i >= 1; i--)//下半部分
	{
		for (j = 3; j >= i; j--)
		{
			printf(" ");
		}
		for (n = (2 * i - 1); n >= 1; n--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

