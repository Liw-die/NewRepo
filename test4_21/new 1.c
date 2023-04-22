#include <stdio.h>
#include <stdlib.h>

typedef struct student{
	int a;
	struct student *next;
}stu,*STU;

STU create_head()//创建head节点
{
	STU head=malloc(sizeof(stu));
	if(head==NULL)
	{
		printf("head申请失败");
		return NULL;
	}
	
	head->next=NULL;
	return head;
}

//创建普通节点
STU create_node(int a)
{
	STU node=malloc(sizeof(stu));
	if(node==NULL)
	{
		printf("node申请失败");
		return NULL;
	}
	
	node->a=a;
	node->next=NULL;
	return node;
}

//尾部添加
void insert_last(STU head,STU node)
{
	STU p=head;
	while(p->next!=NULL)
		p=p->next;
	p->next=node;
	
}

//查找
STU find_dest(STU head,int a)
{
	STU p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		if(p->a==a)
			return p;
	}
	return NULL;
}

//删除
STU del_dest(STU head,int a)
{
	STU dest=find_dest(head,a);
	if(dest!=NULL)
	{
		STU p=head;
		while(p->next!=dest)
			p=p->next;
		p->next=dest->next;
		return dest;
	}
	else
		return NULL;
}

//改
STU dete_stu(STU head,int a)
{
	STU dest=find_dest(head,a);
	if(dest==NULL)
	{
		dest->a=a;
		return dest;
	}
	else 
		return dest;
}

//遍历
void showlist(STU head)
{
	STU p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		printf("a=%d ",p->a);
	}
}
/* viod flashback()
{
	head=p[5];
	p[0]->next=NULL;
	p[5]->next=p[4];
	p[4]->next=p[3];
	p[3]->next=p[2];
	p[2]->next=p[1];
	p[1]->next=p[0];
	
	p[0]->a=p[1]->a;
	p[1]->a=p[2]->a;
	p[2]->a=p[3]->a;
	p[3]->a=p[4]->a;
	p[4]->a=p[5]->a;
	p[5]->a=0;
	showlist(head);
} */

STU flashback(STU p,STU *res)
{
	if(p->next!=NULL)
	{
		STU t=flashback(p->next,res);
		p->next=NULL;
		p->next=t;
	}
	else
		*res=p;
	return p;
	
}
int main()
{
	STU p[6]={NULL};
	STU head=create_head();
	p[0]=head;
	int a=0;
	
	for(a=1;a<6;a++)
	{
		STU node=create_node(a);
		p[a]=node;
		insert_last(head,node);
	}
	showlist(head);
	printf("\n");
	
	STU res=NULL;
	flashback(head->next,&res);
		
	showlist(head);
	printf("\n");
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	