#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
	int *arr;
	int size;
	int cnt;
}Heap,*HEAP;

HEAP new(int num)
{
	HEAP heap = malloc(sizeof(Heap));
	if(heap==NULL)
	{
		printf("申请失败");
		return NULL;
	}
	
	heap->arr=malloc(sizeof(int)*num);
	if(heap==NULL)
	{
		printf("heap->arr 申请失败");
		return NULL;
	}
	
	heap->size=num;
	heap->cnt=0;
	return heap;
}

void pop(HEAP heap,int num)//存数据
{
	if(heap->cnt==heap->size)
	{
		printf("顺序表已满");
		return ;
	}
	
	else {
		heap->arr[heap->cnt]=num;
		heap->cnt++;
	}
}

int push(HEAP heap)//删数据
{
	if(heap->cnt==0)
	{
		printf("顺序表为空");
		return 0;
	}
	else
	{
		int temp=heap->arr[heap->cnt-1];
		heap->arr[heap->cnt-1]=0;
		heap->cnt--;
		return temp;
	}
}


int sense()//判断
{
	int temp=0;
	printf("请键入->");
	scanf("%d",&temp);
	
	
	if(temp<0)
		return -1;
	else if(temp==0)
		return 0;
	else
		return temp;
}

	
int main()
{
	HEAP heap=new(100);
	
	for(int i=0;i<5;i++)
	pop(heap,5*i);
	for(int i=0;i<heap->cnt;i++)
		printf("%d ",heap->arr[i]);
	printf("\n");
	
	int n=0;
	while(n=sense())
	{
		if(n>0)
		{
			pop(heap,n);
			for(int i=0;i<heap->cnt;i++)
			printf("%d ",heap->arr[i]);
			printf("\n");
		}
		else if(n=0)
		{
			printf("退出输入");
			break;
		}
		else
			printf("删除末尾元素：%d\n",push(heap));
	}

	

	
	// for(int i=0;i<3;i++)
		// pop(heap,3*i);
	
	// for(int i=0;i<heap->cnt;i++)
		// printf("%d ",heap->arr[i]);
	// printf("\n");
	
	// printf("删除末尾元素：%d\n",push(heap));
	
	for(int i=0;i<heap->cnt;i++)
		printf("%d ",heap->arr[i]);
	printf("\n");
	
	free(heap->arr);
	free(heap);
	
	return 0;
}
		
		
		
		
		