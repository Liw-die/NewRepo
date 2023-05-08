#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

typedef struct hash{
	char arr[26];
	int set;
	struct hash *next;
}Hash,*HASH;

HASH create_node(char *arr,int set)
{
	HASH node=malloc(sizeof(Hash));
	if(node==NULL)
	{
		perror("node malloc failed!\n");
		return NULL;
	}
	stpcpy(node->arr,arr);
	node->set=set;
	node->next=NULL;
	return node;
}
//尾部插入
void join_last(HASH head,HASH node)
{
	HASH temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=node;
}
//查找
HASH show_last(HASH head,char *arr)
{
	HASH temp=head->next;
	while(temp!=NULL)
	{
		if((strcmp(arr,temp->arr)))
			break;
		temp=temp->next;
	}
	return temp;
}
//文件入表,
HASH *fine_read(char *finename)
{
	FILE *fp=fopen(finename,"r+");
	if(fp==NULL)
	{
		perror("fine read failed!\n");
		return NULL;
	}
	char arr[1024]={0};
	HASH *h=calloc(26,sizeof(HASH));
	int i;
	for(i=0;i<26;i++)
	{
		h[i]=calloc(1,sizeof(Hash));
		h[i]->next=NULL;
	}

	int key;
	int n='A'-'a';

	while(fgets(arr,1024,fp))
	{
		char *token=NULL;
		token = strtok(arr, " ,.;?!-\n");
		while (token != NULL) 
		{
			key=token[0];
			printf("%c\n", key);
			if((key<'A'||key>'Z')&&(key<'a'||key>'z'))
				goto _step;
			if(key>='A'&&key<='Z')
				key-=n;
			key=key%'a';
			printf("%c\n", key);
			HASH node=create_node(token,0);
			join_last(h[key],node);
			_step:
			token = strtok(NULL, " ,.;?!-\n");
		} 
		//printf("gg\n");
		bzero(arr,sizeof(arr));
	}
	//printf("gg\n");
	fclose(fp);
	return h;
}

int main(void)
{
	char arr[10]="1.txt";
	HASH *h=fine_read(arr);
	for(int i=0;i<26;i++)
	{
		HASH p=h[i]->next;
		while(p!=NULL)
		{
			//printf("%s ",p->arr);
			p=p->next;
		}
		//printf("\n");
	}
	return 0;
}
	