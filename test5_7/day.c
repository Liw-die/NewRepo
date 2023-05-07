//编写一个程序，从标准输入读取一组单词，并按字母顺序对它们进行排序，然后将它们输出到标准输出。
#include <stdio.h>
#include <string.h>
void sort_word(char *arr,int len)
{
	if(len==1)
		return ;
	int i,j;
	for(i=len-1;i>=0;i--)
	{
		for(j=0;j<=i;j++)
		{
			char temp;
			if(arr[i]<arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
}
int main(void)
{
	char arr[20];
	scanf("%s",arr);
	sort_word(arr,strlen(arr));
	printf("arr=%s\n",arr);
	return 0;
}