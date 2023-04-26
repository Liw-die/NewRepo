#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//元素节点
typedef struct datanode{
	int data;//队列的数据段
	struct datanode *next;//指针域，指向下一个元素节点
}Datanode,*DATANODE;

//队列控制结构体
typedef struct listque{
	int size;//用来放置队列中元素的个数
	DATANODE front;//始终指向第一个节点的地址
	DATANODE last;//始终指向尾节点的地址
}Listque,*LISTQUE;

//创建队列的控制节点
LISTQUE create_listque()
{
	LISTQUE que=malloc(sizeof(Listque));
	if(que==NULL)
	{
		perror("que malloc failed!");
		return NULL;
	}
	que->size=0;
	que->front=NULL;
	que->last=NULL;
	return que;
}

//创建元素的节点
DATANODE create_node(int num)
{
	DATANODE node=malloc(sizeof(Datanode));
	if(node==NULL)
	{
		perror("node malloc failed!");
		return NULL;
	}
	node->data=num;
	node->next=NULL;
	return node;
}

//入队
void join_que(LISTQUE que,DATANODE node)
{
	if(que->size==0)
	{
		que->front=node;
		que->last=node;
		que->size++;
	}
	else
	{
		que->last->next=node;
		que->last=node;
		que->size++;
	}
}

//判断队列是否为空
bool Is_empty(LISTQUE que)
{
	return que->size == 0;
}
//出队
DATANODE out_que(LISTQUE que)
{
	if(Is_empty(que))
	{	
		printf("NULL que!\n");
		return NULL;
	}
	DATANODE dest=que->front;
	que->front=que->front->next;
	que->size--;
	return dest;
}
//遍历
void showque(LISTQUE que)
{
	DATANODE temp=que->front;
	while(temp!=NULL)
	{
		printf("-%d-",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	//创建队列的控制节点
	LISTQUE que=create_listque();
	int num;
	while(1)
	{
		scanf("%d",&num);
		if(num>0)
		{
			DATANODE node=create_node(num);
			join_que(que,node);
		}
		else if(num<0)
		{
			DATANODE temp=out_que(que);
			free(temp);
		}
		else
			break;
		showque(que);
	}
	return 0;
}
		
		
		
		
		
