#include <stdio.h>
//#include <math.h>

int main()
{
	double input = 0;
	printf("输入一个华氏温度->");
	scanf("%lf", &input);

	double Fahre = 5 * (input - 32) / 9;
	printf("%2.lf华氏度的摄氏温度是%.2lf", input, Fahre);
	return 0;
}
