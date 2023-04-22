#include <stdio.h>
#include <stdlib.h>

double Double_Diff(double* p, int len)
{
	double conout_min = p[0];
	for (int i = 1; i < len; i++)//遍历查找最小的值
	{
		if (conout_min > p[i])
		{
			conout_min = p[i];
		}
	}

	double conout_max = p[0];
	for (int i = 1; i < len; i++)//遍历查找最大的值
	{
		if (conout_max < p[i])
		{
			conout_max = p[i];
		}
	}
	return conout_max - conout_min;//返回最大值与最小值的差
}


int main()
{
	double array[8] = { 1.3,
		1.4,
		2.222,
		555.0,
		7.012,
		0.3333,
		7.999,
		0.751 };
	double* p = array;

	int len = sizeof(array) / sizeof(array[0]);
	//printf("%d\n", len);
	double Diff = Double_Diff(p, len);
	printf("%lf\n", Diff);
	return 0;
}

