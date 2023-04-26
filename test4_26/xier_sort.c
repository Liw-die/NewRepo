#include <stdio.h>
#include <string.h>

int xier_count;
int insert_count;

void show(int *arr,int len)
{
	for(int i=0;i<len;i++)
		printf("-%d-",arr[i]);
	printf("\n");
}
void xier_sort(int *arr, int len, int delt)
{
	int x,y,z,temp;
	while(delt>0)
	{
		for(x=0;x<delt;x++)
		{
			for(y=delt+x;y<len;y+=delt)
			{
				for(z=y-delt;z>=0;z-=delt)
				{
					if(arr[z]>arr[z+delt])
					{
						temp=arr[z];
						arr[z]=arr[z+delt];
						arr[z+delt]=temp;
						xier_count++;
					}
				}
			}
		}
		delt/=2;
	}
}
void insert_sort(int *arr,int n)
{	
	int i,j,k;
	
	//n个元素的数列一共循环插入 n-1 次  i是已排序数列中最后一个元素的位置
	for(i=0;i<n-1;i++)
	{
		//每次插入结束，待排序数列首元素的位置会偏移1位
		//j初始化后是待排序数列的第1个元素,并且逐渐与已排序数列中的元素进行比较
		for(j=i+1; j>0 ;j--)
		{
			//如果待排序数列中的数值小于目标值，那么交换两个数
			if( arr[j-1] > arr[j] )
			{
				k = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = k;
				insert_count++;
			}
		}
		
		
		//show(arr,n);
	}
}

int main()
{
	int arr[10]={5,8,1,6,2,9,7,4,3,0};
	int arr1[10]={5,8,1,6,2,9,7,4,3,0};
	int len = sizeof(arr)/sizeof(arr[0]);
	xier_sort(arr,len,len/2);
	show(arr,len);
	printf("%d\n",xier_count);
	insert_sort(arr1,len);
	show(arr1,len);
	printf("%d\n",insert_count);
	return 0;
}
	
