﻿
#include <stdio.h>

int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr3[10] = { 0 };

	int len = sizeof(arr3) / sizeof(arr3[0]);

	for (int i = 0; i < len; i++)
	{
		arr3[i] = arr1[i] + arr2[i];
	}

	for (int j = 0; j < len; j++)
	{
		printf("%d ", arr3[j]);
	}
	return 0;
}
