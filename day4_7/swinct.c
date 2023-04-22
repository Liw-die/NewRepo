#include <stdio.h>

int main()
{
	char input = 0;
	scanf("%c",&input);
	switch(input)
	{
		case 'a' ... 'z':
			printf("a -- z\n");
			break;
		case 'A' ... 'Z':
			printf("A -- Z\n");
			break;
		case '0' ... '9':
			printf("0 -- 9\n");
			break;
		default:
			printf("其他字符\n");
	}
	return 0;
}

	
