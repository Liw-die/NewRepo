#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct datanode{
	int data;
	struct datanode *next;
}Dnode,*DNOED;

typedef struct lque{
	int size;
	DNOED front;
	DNOED last;
}Lque,*LQUE;

LQUE create_que()
{
	LQUE que=malloc(sizeof(Lque));
	if(que==NULL)
	{
		perror("que malloc failed");
		return NULL;
	}
	que->size=0;
	que->front=NULL;
	que->last=NULL;
	return que;
}

DNOED create_node(int num)
{
	DNOED node=malloc(sizeof(Dnode));
	if(node==NULL)
	{
		perror("node malloc failed");
		return NULL;
	}
	node->data=num;
	node->next=NULL;
	return node;
}

void join_que(LQUE que,DNOED node)
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
DNOED out_que(LQUE que)
{
	if(Is_empty(que))
	{
		printf("队列为空！\n");
		return NULL;
	}
	else
	{
		DNOED temp=que->front;
		que->front=que->front->next;
		return temp;
	}
}

void show_que(LQUE que)
{
	if(Is_empty(que))
	{
		printf("队列为空！\n");
		return ;
	}
	else
	{
		DNOED temp=que->front;
		while(temp!=NULL)
		{
			printf("-%d-",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void insert_sort(LQUE que)
{
	DNOED outer=que->front;
	int temp;
	while(outer!=NULL)
	{
		DNOED subcoat=outer->next;
		while(subcoat!=NULL)
		{
			if(subcoat->data < outer->data)
			{
				temp=outer->data;
				outer->data=subcoat->data;
				subcoat->data=temp;
			}
			else
				subcoat=subcoat->next;
		}
		outer=outer->next;
	}
}

void bulling_sort(LQUE que)
{
	DNOED outer=que->front;
	DNOED subcoat=que->last;
	int temp;
	while(outer!=NULL)
	{
		while(subcoat!=outer)
		{
			



int main(void)
{
	int arr[10] = {5,6,4,9,7,3,8,1,2,0};
	LQUE que=create_que();
	for(int i=0;i<10;i++)
	{
		DNOED node=create_node(arr[i]);
		join_que(que,node);
	}
	show_que(que);
	insert_sort(que);
	show_que(que);
	return 0;
}
	
	
