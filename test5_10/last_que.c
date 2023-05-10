#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct last{
	int buf;
	struct last *next;
}Last,*LAST;

typedef struct queue{
	int size;
	LAST front;
	LAST last;
}Queue,*QUEUE;

//创建控制节点
QUEUE create_control()
{
	QUEUE que=malloc(sizeof(Queue));
	if(que==NULL)
	{
		perror("que create failed!");
		return NULL;
	}
	que->size = 0;
	que->front=NULL;
	que->last =NULL;
	return que;
}

//创建元素节点
LAST create_node(int buf)
{
	LAST node=malloc(sizeof(LAST));
	if(node==NULL)
	{
		perror("node create failed!");
		return NULL;
	}
	node->buf=buf;
	node->next=NULL;
	return node;
}
//入队
void push(QUEUE const que,LAST const node)
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
//判断队列为空
bool is_empty(QUEUE que)
{
	return que->size==0;
}
//出队
LAST pop(QUEUE const que)
{
	if(is_empty(que))
		return NULL;
	
	LAST temp=que->front;
	que->front=temp->next;
	que->size--;
	return temp;
}

//遍历
void showque(QUEUE const que)
{
	LAST temp=que->front;
	while(temp!=NULL)
	{
		printf("-%d-",temp->buf);
		temp=temp->next;
	}
	printf("\n");
}

int main(void)
{
	QUEUE que=create_control();
	int num;
	while(1)
	{
		scanf("%d",&num);
		if(num>0)
		{
			LAST node=create_node(num);
			push(que,node);
		}
		else if(num<0)
		{
			LAST temp=pop(que);
			if(temp==NULL)
				printf("空队\n");
			else
			{
				printf("%d 出队\n",temp->buf);
				free(temp);
			}
		}
		
		else 
			break;
		showque(que);
	}
	showque(que);
}
	
	
	
	