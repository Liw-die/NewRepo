#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//extern int fun();

void sin_p(double* sou_p, double* tar_p)
{
	*tar_p = *sou_p;
}
void transform( double* sou_p,
				double* tar_p, 
				int len,
				double(* Sin_p)(double*, double*))
{
	for (int i = 0; i < len; i++)//循环调用sin_p函数，且循环传参
	{
		Sin_p(&(sou_p[i]), &(tar_p[i]));
	}
}

int main()
{
	double(*Sin_p)(double*, double*) = (double(*)(double*, double*))sin_p;
	double source[100] = { 0 };

	int sou_len = sizeof(source) / sizeof(source[0]);
	for (int i = 0; i < sou_len; i++)//初始化原函数
	{
		source[i] = fabs((double)(i));//接收 i 的绝对值
		//printf("%.2lf \n", source[i]);
	}

	double target[100] = { 0 };//初始化原函数

	transform(source, target, sou_len, Sin_p);

	for (int i = 0; i < sou_len; i++)//初始化原函数
	{
		printf("i-> %.2lf \t", target[i]);
	}

	return 0;
}



//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
////extern int fun();
//
//
//void sin_p(double* sou_p, double* tar_p)
//{
//
//}
//viod transform(double* sou_p, double* tar_p, int len, double* sin_p(double*, double*))
//{
//
//}
//
//int main()
//{
//	double source[100] = { 0 };
//	int sou_len = sizeof(source) / sizeof(source[0]);
//	for (int i = 0; i < sou_len; i++)
//	{
//		source[i] = double exp(double i);
//		printf("%.2lf ", source[i]);
//	}
//	double target[100] = { 0 };	
//	return 0;
//}


//typedef union
//{
//	long i;
//	int k[5];
//	char c;
//} fruit;
//struct creature
//{
//	short cat; //2
//	fruit apple; //20
//	double dog; //8
//};
//fruit berry;
//int main()
//{
//	printf("%d\n", sizeof(struct creature) + sizeof(berry));
//	printf("creature %d\n", sizeof(struct creature));
//	printf("berry %d\n", sizeof(berry));
//	printf("long %d\n", sizeof(long));
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
////extern int fun();
//
//typedef struct Date
//{
//	union {
//		int leap_year;
//		int common_year;
//	}year;
//	/*enum {
//		Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Spe, Oct, Nov, Dec
//	}*/
//	int month;
//	int day;
//	int sign_year;
//}Date_My;
//
//int year_jud(int year, Date_My* p)//平闰年判断
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//	{
//		p->year.leap_year = year;
//		return 1;
//	}
//	else
//	{
//		p->year.common_year = year;
//		return 0;
//	}
//
//}
//
//int input_my(Date_My* p)
//{
//	int year = 0;
//	printf("请输入年份—>");
//	scanf("%d", &year);
//	p->sign_year = year_jud(year, p);
//
//	printf("请输入月份—>");
//	scanf("%d", &(p->month));
//
//	printf("请输入天数—>");
//	scanf("%d", &(p->day));
//}
//
//void show_day(Date_My* p)
//{
//	if (p->sign_year == 1)
//	{
//		switch (p->month)
//		{
//		case 1:
//			printf("你输入的这一年是闰年的第%d天", p->day);
//			break;
//		case 2:
//			printf("你输入的这一年是闰年的第%d天", p->day + 31);
//			break;
//		case 3:
//			printf("你输入的这一年是闰年的第%d天",
//				p->day + 31 + 29);
//			break;
//		case 4:
//			printf("你输入的这一年是闰年的第%d天",
//				p->day + 31 + 29 + 31);
//			break;
//		case 5:
//			printf("你输入的这一年是闰年的第%d天",
//				p->day + 31 + 29 + 31 + 30);
//			break;
//		case 6:
//			printf("你输入的这一年是闰年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30);
//			break;
//		case 7:
//			printf("你输入的这一年是闰年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 + 30);
//			break;
//		case 8:
//			printf("你输入的这一年是闰年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 + 30 + 31);
//			break;
//		case 9:
//			printf("你输入的这一年是闰年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 + 30 + 31 + 31);
//			break;
//		case 10:
//			printf("你输入的这一年是闰年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 + 30 + 31 + 31 + 30);
//			break;
//		case 11:
//			printf("你输入的这一年是闰年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 + 30 + 31 + 31 + 30 + 31);
//			break;
//		case 12:
//			printf("你输入的这一年是闰年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 + 30 + 31 + 31 + 30 + 31 + 30);
//			break;
//		default:
//			break;
//		}
//	}
//	else
//	{
//		switch (p->month)
//		{
//		case 1:
//			printf("你输入的这一年是平年的第%d天", p->day);
//			break;
//		case 2:
//			printf("你输入的这一年是平年的第%d天", p->day + 31);
//			break;
//		case 3:
//			printf("你输入的这一年是平年的第%d天",
//				p->day + 31 + 29 - 1);
//			break;
//		case 4:
//			printf("你输入的这一年是平年的第%d天",
//				p->day + 31 + 29 + 31 - 1);
//			break;
//		case 5:
//			printf("你输入的这一年是平年的第%d天",
//				p->day + 31 + 29 + 31 + 30 - 1);
//			break;
//		case 6:
//			printf("你输入的这一年是平年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 - 1);
//			break;
//		case 7:
//			printf("你输入的这一年是平年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 + 30 - 1);
//			break;
//		case 8:
//			printf("你输入的这一年是平年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 + 30 + 31 - 1);
//			break;
//		case 9:
//			printf("你输入的这一年是平年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 + 30 + 31 + 31 - 1);
//			break;
//		case 10:
//			printf("你输入的这一年是平年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 + 30 + 31 + 31 + 30 - 1);
//			break;
//		case 11:
//			printf("你输入的这一年是平年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 + 30 + 31 + 31 + 30 + 31 - 1);
//			break;
//		case 12:
//			printf("你输入的这一年是平年的第%d天",
//				p->day + 31 + 29 + 31 + 30 + 30 + 30 + 31 + 31 + 30 + 31 + 30 - 1);
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//int main()
//{
//	Date_My date_my = { 0 };//结构体初始化
//	Date_My* p = (Date_My*)malloc(sizeof(Date_My));//结构体指针申请空间
//	if (p == NULL)//判断指针是否为空
//		exit(1);
//	input_my(p);//输入日期
//	show_day(p);//打印日期
//	free(p);
//	return 0;
//}
