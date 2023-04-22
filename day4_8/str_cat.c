#include <stdio.h>
#include <string.h>

void str_cat(char* arr1, char* arr2, char* arr3,int len1, int len2)
{
    int j = 0;
    for (int i = 0; i < len1 + len2; i++)
    {
        if (i < len1)
        {
            arr3[i] = arr1[i];
        }
        else
        {
            arr3[i] = arr2[j];
            j++;
        }
    }
}

int main()
{
    char arr1[] = "holle";
    char arr2[] = "world";
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    char arr3[15] = { 0 };
    str_cat(arr1, arr2, arr3, len1, len2);
    printf("%s\n", arr3);
    return 0;
}