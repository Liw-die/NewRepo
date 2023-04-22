#include <stdio.h>

int main()
{
	char input = 0;
	scanf("%c",&input);
	if(input<0||input>127)
	{
		printf("输入非法");
		return 0;
	}
	if(input>='a' && input<='z')
		printf("a -- z");
	else if(input>='A' && input <= 'Z')
		printf("A -- Z");
	else if(input>='0' && input <= '9')
		printf("0 -- 9");
	else
		printf("其他字符");
	return 0;
}
