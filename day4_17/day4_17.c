#include <stdio.h>
#define MAX(x,y) \ (x>y?x:y)

int main()
{
	printf("%d", MAX(5, 4));
	return 0;
}