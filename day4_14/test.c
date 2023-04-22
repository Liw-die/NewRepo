#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//extern int fun();

typedef struct stu_info
{

	char name[10];
	int id;
	int arg;
	char sex[5];
}stu_i;

void type_stu(stu_i* p_stu, int len_stu)//学生信息输入
{
	int i = 0;
	for (i = 0; i < len_stu; i++)
	{
		printf("输入第%d个学生信息->\n", i + 1);

		printf("姓名->");
		scanf("%s", (p_stu + i)->name);
		getchar();
		printf("学号->");
		scanf("%d", &((p_stu + i)->id));
		printf("年龄->");
		scanf("%d", &((p_stu + i)->arg));
		printf("性别->");
		scanf("%s", (p_stu + i)->sex);
	}
}

void show_stu(stu_i* p_stu, int len_stu)//学生信息显示
{
	int i = 0;
	printf("姓名\t学号\t年龄\t性别\t\n");

	for (i = 0; i < len_stu; i++)
	{
		printf("%s\t", (p_stu + i)->name);
		printf("%d\t", (p_stu + i)->id);
		printf("%d\t", (p_stu + i)->arg);
		printf("%s\t\n", (p_stu + i)->sex);
	}
}

int main(int argc, const char* argv[])
{
	stu_i info[5] = { 0 };//结构体数组初始化
	int len_stu = sizeof(info) / sizeof(info[0]);//计算结构体数组个数

	type_stu(info, len_stu);//学生信息输入
	show_stu(info, len_stu);//学生信息显示
	return 0;

}



//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
////extern int fun();
//
//struct stu_info
//{
//	int id;
//	char name[20];
//	int age;
//	float grade;
//}stu;
//
//void stu_print(struct stu_info* p)
//{
//	printf("%d\n", p->id);
//	printf("%s\n", p->name);
//	printf("%d\n", p->age);
//	printf("%f\n", p->grade);
//}
//
//int main()
//{
//	struct stu_info* p = (struct stu_info*)malloc(sizeof(stu));
//	if (p == NULL)
//		return 1;
//	bzero(p, sizeof(stu));
//	strcpy(p->name, "楠楠");
//	p->id = 1933;
//	p->age = 24;
//	p->grade = 99.99;
//	stu_print(p);
//	//printf("%d\n", p->id);
//	//printf("%s\n", p->name);
//	//printf("%d\n", p->age);
//	//printf("%f\n", p->grade);
//	free(p);
//	return 0;
//}