#include <stdio.h>
#include <string.h>

void str_blank(char* p, int len)
{
	int i = 0;
	while (i < len)
	{
		if (p[i] != 32)
		{
			printf("%c", p[i]);
			i++;
		}
		else if (p[i] == 32)
		{
			i++;
			continue;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	char input[100] = { 0 };
	gets(input);
	str_blank(input, strlen(input));
	return 0;
}
