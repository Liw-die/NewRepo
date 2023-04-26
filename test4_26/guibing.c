#include <stdio.h>
#include <string.h>

void show(int *arr,int n);
void guibing_sort(int *arr,int len)
{
	if(len<=1)
		return ;
		
	int curr_len=len/2;
	guibing_sort(arr,curr_len);
	guibing_sort(arr+curr_len,len-curr_len);
	
	int *a=arr;
	int *b=arr+curr_len;
	int temp[len];
	int i=0;
	int j=0;
	while(i<curr_len && j<len-curr_len)
	{
		if(a[i]<b[j])
		{
			temp[i+j]=a[i];
			i++;
		}
		else if(a[i]>b[j])
		{
			temp[i+j]=b[j];
			j++;
		}
	}
	
	while(i<curr_len)
	{
		temp[i+j]=a[i];
		i++;
	}
	while(j<len-curr_len)
	{		
		temp[i+j]=b[j];
		j++;
	}
	for(i=0;i<len;i++)
		arr[i]=temp[i];
	show(arr,len);
}
void show(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("-%d-",arr[i]);
	printf("\n");
}
int main(void)
{
	int arr[10] = {5,6,4,9,7,3,8,1,2,0};
	guibing_sort(arr,10);
	
	show(arr,10);
	return 0;
}