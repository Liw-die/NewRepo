#include <stdio.h>

void show_select(int *arr,int len)
{
	for(int i=0;i<len;i++)
		printf("-%d-",arr[i]);
	printf("\n");
}

void quick_sort(int *arr,int left,int right)
{
	if(left>=right)
		return ;
	int key=arr[left];
	int i=left;
	int j=right;
	
	while(i<j)
	{
		while(arr[j]>key &&i<j)
			j--;
		arr[i]=arr[j];
		
		while(arr[i]<key && i<j)
			i++;
		arr[j]=arr[i];
	}
	//循环结束时就是i=j也就是key 的位置
	arr[i]=key;
	show_select(arr,10);
	quick_sort(arr,left,i-1);
	quick_sort(arr,j+1,right);
	
}

int main()
{
	int arr[10]={8,1,6,7,2,4,9,3,5,0};
	int len =sizeof(arr)/sizeof(arr[0]);
	show_select(arr,10);
	quick_sort(arr,0,9);
	return 0;
	
}