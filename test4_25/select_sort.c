#include <stdio.h>
void show_select(int *arr,int len);
void select_sort(int *arr,int len)
{
	int i,j,temp;
	for(i=0;i<len-1;i++)//外层循环表示循环多少次
	{
		int min=i;
		for(j=i+1;j<len;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
		show_select(arr,len);
	}
}
void show_select(int *arr,int len)
{
	for(int i=0;i<len;i++)
		printf("-%d-",arr[i]);
	printf("\n");
}
int main()
{
	int arr[10]={8,1,6,7,2,4,9,3,5,0};
	int len =sizeof(arr)/sizeof(arr[0]);
	select_sort(arr,len);
	show_select(arr,len);
	return 0;
}