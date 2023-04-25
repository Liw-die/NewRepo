#include <stdio.h>

void show_arr(int *arr,int len);
void inse_sort(int *arr,int len)//插入排序
{
	int i,j,temp;
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j>0;j--)
		{
			if(arr[j-1]>arr[j])
			{
				temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
		}
		show_arr(arr,10);
	}
}

void bubble_sort(int *arr,int len)
{
	int i,j,temp;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		show_arr(arr,10);
	}
}

void show_arr(int *arr,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("-%d-",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[10]={5,8,1,2,3,7,6,0,9,4};
	//inse_sort(arr,10);
	//show_arr(arr,10);
	
	bubble_sort(arr,10);
	show_arr(arr,10);
	return 0;
}
	
