#include <stdio.h>

int main()
{
	char input = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	printf("请输入->");

	while (1)
	{
		input = getchar();

		if (input == '#')
		{
			break;
		}

		switch (input)
		{
		case ' ':
			a++;
			continue;
		case '\n':
			b++;
			continue;
		default:
			c++;
			continue;
		}
	}
	printf("空格%d个，换行%d个，其他字符%d个\n", a, b, c);
	return 0;
}

