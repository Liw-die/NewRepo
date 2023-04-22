#include <stdio.h>
#include <string.h>

char e_arr[100];
int enroll(char c);
int main(int argc, char const* argv[])
{
	char arr[100];
	printf("请输入一个字符串:");
	scanf("%s", arr);
	for (int i = 0; i < strlen(arr); i++)
	{
		if (enroll(arr[i]) == 1)
		{
			printf("%c", arr[i]);
		}
	}
	printf("\n");
	return 0;
}

int enroll(char c)
{
	int i;
	for (i = 0; i < strlen(e_arr); i++)
	{
		if (e_arr[i] == c)
		{
			return 0;
		}
	}
	e_arr[strlen(e_arr)] = c;
	return 1;
}
//void remove_duplicates(char* str) {
//    int len = strlen(str); // 获取字符串长度
//
//    if (len <= 1) {
//        return; // 字符串长度小于等于1时，不需要去重，直接返回
//    }
//
//    int tail = 1; // 用于记录去重后字符串的尾部索引
//
//    for (int i = 1; i < len; i++) {
//        int j;
//        for (j = 0; j < tail; j++) {
//            if (str[i] == str[j]) {
//                break; // 如果当前字符在去重后的字符串中已经存在，则跳过
//            }
//        }
//
//        if (j == tail) {
//            // 如果当前字符不在去重后的字符串中，则将其添加到去重后的字符串尾部
//            str[tail++] = str[i];
//        }
//    }
//
//    str[tail] = '\0'; // 在去重后的字符串尾部添加字符串结束符
//}
//
//int main() {
//    char str[] = "google";
//    printf("原始字符: %s\n", str);
//
//    remove_duplicates(str);
//    printf("去重后字符: %s\n", str);
//
//    return 0;
//}



//#include <stdio.h>
//int sum_tie(int* p[3], int len, int len1)
//{
//	int sum = 0;
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = 0; j < len1; j++)
//		{
//			sum += *(p[i] + j);
//		}
//	}
//	return sum;
//}
//
//int main(int argc, const char* argv[])
//{
//	int a[3][5] = { 1,1,1,1,1,
//		1,1,1,1,1,
//		1,1,1,1,1 },
//		sum = 0;
//
//	int* p[3] = { a[0],a[1],a[2] };
//
//	int len = sizeof(p) / sizeof(p[0]);
//	int len1 = sizeof(a[0]) / sizeof(a[0][0]);
//
//	sum = sum_tie(p, len, len1);
//	printf("%d\n", sum);
//	return 0;
//}


//#include <stdio.h>
//int max(int a, int b) {
//    return a > b ? a : b;
//}
//int maxSubArraySum(int arr[], int n) {
//    int maxSum = arr[0]; // 初始化最大子数组和为第一个元素
//    int curSum = arr[0]; // 初始化当前子数组和为第一个元素
//
//    for (int i = 1; i < n; i++) {
//        curSum = max(arr[i], curSum + arr[i]); // 更新当前子数组和  
//        maxSum = max(maxSum, curSum); // 更新最大子数组和
//    }
//
//    return maxSum;
//}
//
//int main(void) {
//    int a[7] = { -11, 5, 3, -6, 4, 8, 6 };
//    int len = sizeof(a) / sizeof(a[0]);
//
//    int maxSum = maxSubArraySum(a, len);
//    printf("最大子数组和: %d\n", maxSum);
//
//    return 0;
//}




//#include <stdio.h>
//#include <stdlib.h>
//
//void init_array(int rows, int cols, double** arr)
//{
//    double count = 0.0;
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            arr[i][j] = count++;
//        }
//    }
//}
//
//void display_array(int rows, int cols, double** arr)
//{
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            printf("%.2f ", arr[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main()
//{
//    // 动态分配内存来创建3x5的二维数组
//    int rows = 3;
//    int cols = 5;
//    double** arr1 = (double**)malloc(rows * sizeof(double*));
//    for (int i = 0; i < rows; i++)
//    {
//        arr1[i] = (double*)malloc(cols * sizeof(double));
//    }
//
//    // 初始化数组1
//    init_array(rows, cols, arr1);
//
//    printf("Array 1:\n");
//    display_array(rows, cols, arr1);
//
//    // 动态分配内存来创建另一个3x5的二维数组
//    double** arr2 = (double**)malloc(rows * sizeof(double*));
//    for (int i = 0; i < rows; i++)
//    {
//        arr2[i] = (double*)malloc(cols * sizeof(double));
//    }
//
//    // 将数组1赋值给数组2
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//        {
//            arr2[i][j] = arr1[i][j];
//        }
//    }
//
//    printf("Array 2:\n");
//    display_array(rows, cols, arr2);
//
//    // 释放动态分配的内存
//    for (int i = 0; i < rows; i++)
//    {
//        free(arr1[i]);
//        free(arr2[i]);
//    }
//    free(arr1);
//    free(arr2);
//
//    return 0;
//}