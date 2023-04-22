#include <stdio.h>

void arryar(int (*p)[5])
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			printf("%d ", p[x][y]);
		}
		printf("\n");
	}
}

int main()
{
	int buf[3][5] = { { [0 ... 4] = 100},
		{ [0 ... 4] = 200 },
		{ [0 ... 4] = 300} };

	int (*p)[5] = buf;
	arryar(p);
	return 0;
}





//void arryar(int* p, int n)
//{
//	int x, y;
//	for (x = 0; x < 10; x++)
//	{
//		for (y = 0; y < 10; y++)
//		{
//			printf("%d \t", p[x * 10 + y]);
//		}
//		printf("\n");
//	}
//}
//
//
//int main()
//{
//	int arr[100]={[0 ... 29]=123,[70 ... 99]=456};
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	arryar(arr, 100);
//	return 0;
//}

