#include <stdio.h>

int Fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else if (n > 2)
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int main()
{
	int n ;
	scanf("%d", &n);
	if (n < 0)
	{
		printf("请输入大于0的数");
		return 0;
	}
	int num = Fibonacci(n);
	printf("%d\n", num);
	return 0;
}