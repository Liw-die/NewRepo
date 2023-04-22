#include <stdio.h>

int main()
{
	int input;
	printf("输入一个大于0的整数->");
	scanf("%d", &input);
	if (input < 0)
	{
		printf("非法输入！\n");
		return 0;
	}
	int i, n;
	for (i = 2; i <= input; i++)
	{
		int flag = 1;//标志
		for (n = 2; n <= i; n++)
		{
			if (i % n == 0)
			{
				flag = 0;//不是素数标志为0
				break;
			}
		}
		if (flag == 1)
			printf("%d ", i);
	}
	return 0;
}
