#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct que{
	int *arr;
	int size;
	int *front;
	int *last;
}Que,*QUE;

//创建控制的结构体
QUE create_que(int num)
{
	QUE q=malloc(sizeof(Que));
	if(q==NULL)
	{
		printf("malloc failed");
		return NULL;
	}
	
	q->arr=malloc(sizeof(int)*num);
	
	if(q->arr==NULL)
	{
		printf("malloc failed");
		return NULL;
	}
	
	q->size=num;
	//队列为空时，front和last都为NULL
	q->front=NULL;
	q->last=NULL;
	
	return q;
}

//判断队列是否已满
bool Is_full(QUE q)
{
	return (q->last+1 == q->front) || (q->last+1 == q->front+q->size);
}
//判断队列是否为空
bool Is_empty(QUE q)
{
	return q->front==q->last;
}

//入队
void push(QUE q,int num)
{
	if(Is_full(q))
	{
		printf("队列已满!\n");
		return ;
	}
	if(q->front==q->last)//在第一次存入数据时
	{
		
		q->front=&q->arr[0];//front指向arr的首元素
		*q->front=num;//存入数据
		q->last=q->front+1;//last指向下一个元素位置
	}
	else//不是第一次存入数据时
	{
		*q->last=num;
		q->last++;
		//当last越界时将p->last至为首元素
		if(q->last==q->arr+q->size)
			q->last=&q->arr[0];
	}
}

//出队
int pop(QUE q)
{
	if(Is_empty(q))//判断队列是否为空
	{
		printf("队列为空");
		return 0;
	}
	
	
	int temp=*q->front;//获取要出队的数据
	q->front++;//front右移一位
	
	if(q->front == q->arr+q->size)//判断front是否要越界
		q->front = &q->arr[0];
	
	return temp;
}
//遍历
void show(QUE q)
{
	if(Is_empty(q))//判断队列是否为空
		return ;
	
	int *dest=q->front;//用来存储当前front的位置
	while(1)
	{
		printf("-%d-",*dest);
		dest++;
		if(dest == q->last)//当dest等于last时表示已经遍历完队列
			break;
		if(dest == q->arr+q->size)//判断dest是否越界
			dest = &q->arr[0];
	}
	printf("\n");
}

int main()
{
	QUE q=create_que(10);
	int data;
	while(1)
	{
		scanf("%d",&data);
		if(data>0)//入队
			push(q,data);
			
		else if(data<0)//出队
		{
			int n=pop(q);
			if(n!=0)
			{
				printf("%d 出队",n);
			}
		}
		else
			break;
		show(q);
	}
	return 0;
}







