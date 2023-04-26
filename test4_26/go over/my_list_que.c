#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dnode{
	int data;
	struct dnode *next;
}Dnode,*DNODE;

typedef struct listque{
	int size;
	DNODE front;
	DNODE last;
}Lque,*LQUE;

LQUE create_que()
{
	LQUE que=malloc(sizeof(Lque));
	if(que==NULL)
	{
		perror("que malloc failed");
		return NULL;
	}
	que->front=NULL;
	que->last=NULL;
	que->size=0;
	return que;
}
DNODE create_node(int num)
{
	DNODE node=malloc(sizeof(Dnode));
	if(node==NULL)
	{
		perror("node malloc failed");
		return NULL;
	}
	node->data=num;
	node->next=NULL;
	return node;
}
void join_que(LQUE que,DNODE node)
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
bool Is_empty(LQUE que)
{
	return que->size==0;
}
DNODE out_que(LQUE que)
{
	if(Is_empty(que))
	{
		printf("NULL que\n");
		return NULL;
	}
	
	DNODE temp=que->front;
	que->front=que->front->next;
	temp->next=NULL;
	que->size--;
	return temp;
}
void show(LQUE que)
{
	if(Is_empty(que))
	{
		printf("队列为空");
		return ;
	}
	
	DNODE temp=que->front;
	while(temp!=NULL)
	{
		printf("-%d-",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main(void)
{
	LQUE que=create_que();
	
	int num;
	while(1)
	{
		scanf("%d",&num);
		if(num>0)
		{
			DNODE node=create_node(num);
			join_que(que,node);
		}
		else if(num<0)
		{
			out_que(que);
		}
		else
			break;
		show(que);
	}
	
	return 0;
}
	
	
	
	
	
	
	
	