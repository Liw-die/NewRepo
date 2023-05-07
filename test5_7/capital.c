//编写一个程序，从标准输入读取一组字符串，然后将其中所有的大写字母转换为小写字母，并将结果输出到标准输出。
//编写一个程序，从标准输入读取一组单词，并将其中所有的元音字母（a、e、i、o、u）删除，并将结果输出到标准输出。
#include <stdio.h>
#include <string.h>

void capital(char *arr)
{
	int len=strlen(arr);
	int i;
	//int n='A'-'a';
	for(i=0;i<len;i++)
	{
		//if(arr[i]>='A' && arr[i] <='Z')
			//arr[i]=arr[i]-n;
		if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u')
		{
			for(int j=i;j<len;j++)
			{
				arr[j]=arr[j+1];
			}
			len--;
			i=i-1;
		}
			
	}
}

int main(void)
{
	char arr[50];
	scanf("%s",arr);
	capital(arr);
	printf("%s",arr);
	return 0;
}