#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//#define LEAP_YEAR 366
//#define COMM_YEAR 365

static inline int add(int a, int b);

// 定义一个使用 inline 关键字的函数
inline int add(int a, int b) { // 使用 inline 关键字定义一个简单的加法函数
    return a + b;
}

int main() {
    int result = add(2, 3);// 内联调用 add 函数
    printf("%d\n", result);
    return 0;
}
