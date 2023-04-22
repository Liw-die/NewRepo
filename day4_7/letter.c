#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

void pyramid()
{
	char input = 0;
	scanf("%c", &input);
	if (input < 'A' || input>'Z')
	{
	printf("0\n");
		 exit(1);
	}
	else
	{
		int i, j;
		char letter = 'A', res;
		for (i = 0; i <= (input - letter); i++)
		{
			for (j = (input - letter); j >= i + 1; j--)
			{
				printf(" ");
			}

			for (j = 0; j <= i; j++)
			{
				printf("%c", letter + j);
				res = letter + j - 1;
			}
			for (j = i; j > 0; j--)
			{
				printf("%c", res--);
			}
			printf("\n");
		}
	}
}

int main()
{
	pyramid();
	return 0;
}
