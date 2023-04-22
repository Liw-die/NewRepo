#include <stdio.h>

int main()
{
	int input = 1;
	while(input >= 0)
	{
		printf("输入天数->");
		scanf("%d",&input);
		printf("%d days are %d weeks, %d days",input,input/7,input%7);
	}
	return 0;
}
