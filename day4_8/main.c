#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        if (2 == argc)
        {
            if (strcmp(argv[1], "123456") == 0)
            {
                printf("欢迎！\n");
            }
            else
            {
                printf("ERROR\n");
            }
        }
        if (argc > 2)
        {
            printf("密码过长\n");
        }
    }
    else
    {
        printf("请输入密码\n");
    }
    return 0;
}
