//哈希表
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10000

typedef struct hash{
	int data;
	int set;
	struct hash *next;
}Hash,*HASH;

//创建无序数组
int *get_arr()
{
	int *arr=calloc(NUM,sizeof(int));
	if(arr==NULL)
	{
		perror("arr calloc failed!");
		return NULL;
	}
	int i;
	for(i=0;i<NUM;i++)
		arr[i]=rand()%10000;
	return arr;
}

//创建哈希表,假设哈希表的键值为100,key=arr[i]%100;范围0-99
HASH *create_hash(int *arr)
{
	HASH *h=calloc(100,sizeof(HASH));
	if(h==NULL)
	{
		perror("h calloc failed!");
		return NULL;
	}
	int i;
	for(i=0;i<100;i++)
	{
		h[i]=calloc(1,sizeof(Hash));
		if(h[i]==NULL)
		{
			perror("h_head calloc failed!");
			return NULL;
		}
		h[i]->next=NULL;
	}
	HASH node;
	int key;
	for(i=0;i<NUM;i++)
	{
		key=arr[i]%100;
		
		node=malloc(sizeof(Hash));
		if(node==NULL)
		{
			perror("node calloc failed!");
			return NULL;
		}
		node->data=arr[i];
		node->set=i;
		node->next=NULL;
		
		HASH p=h[key];
		while(p->next!=NULL)
			p=p->next;
		p->next=node;
	}
	return h;
}

int main(void)
{
	srand(time(NULL));
	int *arr=get_arr();
	HASH *h=create_hash(arr);
	
	Scan:
	while(1)
	{
		int data,ret;
		ret=scanf("%d",&data);
		if(ret!=1)
		{
			while(getchar()!='\n');
			continue;
		}
		
		int key=data%100;
		
		HASH p=h[key]->next;
		while(p!=NULL)
		{
			if(p->data==data)
			{
				printf("找到了->%d，在第%d个\n",p->data,p->set);
				
				goto Scan;
			}
			p=p->next;
		}
		if(p==NULL)
			printf("没找到\n");
		return 0;
	}
}
	
	
	
	
	
	
	
	
	
	
	
