#include <stdio.h>
#include <stdlib.h>

typedef struct dlist{
	int data;//数据域
	struct dlist *next;
	struct dlist *prev;//指针域
}Dlist,*DLIST;

//创建头节点
DLIST create_head()
{
	DLIST head=malloc(sizeof(Dlist));
	if(head==NULL)
	{
		printf("head malloc failed(失败)");
		return NULL;
	}
	
	head->next=head;
	head->prev=head;
	return head;
}

//创建节点
DLIST create_node(int num)
{
	DLIST node=malloc(sizeof(Dlist));
	if(node==NULL)
	{
		printf("node malloc failed(失败)");
		return NULL;
	}
	node->data=num;
	node->next=node;
	node->prev=node;
	return node;
}

//节点插入,latter表示要插入到中间的节点，front表示要插入的节点的前面的节点地址
//back表示要插入结点的后面的节点地址
void _add_list(DLIST latter,DLIST front,DLIST back)
{
	latter->prev=front;
	latter->next=back;
	
	front->next=latter;
	back->prev=latter;
}

//插入到首元素的节点
void add_list_head(DLIST insert,DLIST head)
{
	_add_list(insert,head,head->next);
}

//插入到末尾的节点
void add_list_tail(DLIST insert,DLIST head)
{
	_add_list(insert,head->prev,head);
}

//查找节点
DLIST list_find(DLIST head,int num)
{
	DLIST temp=head->next;
	while(temp!=head)
	{
		if(temp->data==num)
			return temp;
		temp=temp->next;
	}
	return temp;
}

//修改节点
DLIST dlist_find(DLIST head,int lodnum,int newnum)
{
	DLIST temp=list_find(head,lodnum);
	if(temp==head)
	{
		printf("没有找到该代码段");
		return NULL;
	}
	else
	{
		temp->data=newnum;
		return temp;

	}
}

//删除任意节点,无返回值,注意要将删除的节点free，front->要删除的前节点,last->要删除的后节点
void _node_list_del(DLIST front,DLIST last)
{
	front->next=last;
	last->prev=front;
}

//删除目标节点
void list_dle(DLIST dest)
{
	_node_list_del(dest->prev,dest->next);
	dest->next=dest;
	dest->prev=dest;
	free(dest);
}

//删除查找的节点
void _node_find_del(DLIST head,int num)
{
	DLIST temp=list_find(head,num);
	if(temp==head)
		printf("没有找到该节点");
	else
	{
		printf("num->%d 删除成功！\n",temp->data);
		list_dle(temp);
		free(temp);
	}
}

//遍历链表使用宏定义
#define list_for_each_next(p,head) for(p=head->next;p!=head;p=p->next)
#define list_for_each_prev(p,head) for(p=head->prev;p!=head;p=p->prev)
void show_next(DLIST head)
{
	printf("head next:\n");
	
	DLIST p=NULL;
	//for(p=head->next;p->next!=head;p=p->next)
	list_for_each_next(p,head)
		printf("-%d- ",p->data);
	printf("\n");
}
void show_prev(DLIST head)
{
	printf("head prev:\n");
	
	DLIST p=NULL;
	//for(p=head->prev;p->prev!=head;p=p->prev)
	list_for_each_prev(p,head)
		printf("-%d- ",p->data);
	printf("\n");
}	
	
//链表插入,将整个链表插入到只有一个头节点的链表中
void list_insert(DLIST colhead,DLIST nowhead)
{
	DLIST now_next=nowhead->next;
	DLIST now_prev=nowhead->prev;
	nowhead->next=nowhead;
	nowhead->prev=nowhead;
	
	now_next->prev=colhead;
	now_prev->next=colhead;
	colhead->next=now_next;
	colhead->prev=now_prev;
	free(nowhead);
}
//链表插入,将整个链表插入到另一个链表的末尾
void list_insert_dil(DLIST colhead,DLIST nowhead)
{
	DLIST now_next=nowhead->next;
	DLIST now_prev=nowhead->prev;

	nowhead->next=nowhead;
	nowhead->prev=nowhead;
	
	DLIST col_prev=colhead->prev;
	colhead->prev->next=now_next;
	colhead->prev=now_prev;
	now_next->prev=col_prev;
	now_prev->next=colhead;	
	
	free(nowhead);
}

int main()
{
	DLIST odd=create_head();//奇数头
	DLIST even=create_head();
	DLIST head=create_head();
	
	int i;
	for(i=1;i<10;i++)
	{
		DLIST node=create_node(i);
		add_list_tail(node,head);
	}
	show_next(head);
	
	DLIST p=head;
	while(p->next!=head)
	{
		if(p->data%2==1)
		{
			DLIST odd_node=create_node(p->next->data);
			add_list_head(odd_node,odd);
		}
		else
		{
			DLIST even_node=create_node(p->next->data);
			add_list_tail(even_node,even);
		}
		p=p->next;
	}
	
	//删除head后的所有节点
	p=head;
	DLIST temp=p->next;
	while(temp!=head)
	{
		list_dle(temp);
		//free(temp->next);
		temp=p->next;
	}
	show_next(odd);
	show_next(even);
	
	list_insert(head,even);
	list_insert_dil(head,odd);
	show_next(head);
	
}
	
	
	
	
	
	
	
	
	
	
	