#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student{
	char *name;
	int age;
	struct student *next;
}stu,*STU;

//创建head节点
STU create_head()
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
STU create_node(char *name,int age)
{	

	STU node=malloc(sizeof(stu));
	if(node==NULL)
	{
		printf("node->malloc familiar（失败）");
		return NULL;
	}
	node->name=malloc(sizeof(char)*16);
	if(node->name==NULL)
	{
		printf("node->name malloc familiar（失败）");	
		return 0;
	}
	
	strcpy(node->name,name);
	node->age=age;
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
//通过name查找
STU find_dest(STU head,	char *name)
{
	STU p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		
		if(strcmp(p->name,name)==0)
			return p;
	}
	
	return NULL;
}
//通过name删除
STU del_dest(STU head,char *name)
{
	STU dest=find_dest(head,name);
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
STU dete_stu(STU head,char *name_sou,char *name_dou,int age)
{
	STU dest=find_dest(head,name_sou);
	if(dest!=NULL)
	{
		stpcpy(dest->name,name_dou);
		dest->age=age;
		return dest;
	}
	else
		return dest;
}
//遍历打印
void showlist(STU head)
{
	STU p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		printf("name:%10s  age:%d\n",p->name,p->age);
	}
}
//输入判断
void input_esti(char *name,int *age)
{
	
	printf("请输入名字：");
	scanf("%s",name);
	getchar();
	printf("请输入年龄：");
	while(scanf("%d",age)!=1)
		while(getchar()!='\n');
}
	

	
int main()
{
	STU head=create_head();
	char name[16];
	int age;
	
	
	for(int i=0;i<3;i++)
	{
		input_esti(name,&age);
		STU node=create_node(name,age);
		insert_last(head,node);
		
	}
	showlist(head);
	
	//查找
	char arr[16];
	scanf("%s",arr);
	
	STU temp=find_dest(head,arr);
	if(temp==NULL)
		printf("查找失败！\n");
	else
		printf("%p,name:%s,age:%d\n",temp,temp->name,temp->age);
	
/* 	//修改
	temp=dete_stu(head,"abc","ppp",99);
	if(temp==NULL)
		printf("修改时查找失败！\n");
	else
		printf("%p,name:%s,age:%d\n",temp,temp->name,temp->age);
	
	//删除
	temp=del_dest(head,"ppp");
	if(temp==NULL)
		printf("删除时查找失败！\n");
	else
		showlist(head);
	free(temp); */
	
	return 0;	
}