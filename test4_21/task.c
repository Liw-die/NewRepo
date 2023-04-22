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
	
//修改节点指向
void node_date_point(DLIST head,DLIST colpoint,DLIST newpoint)//1 2 3 4 5 
{
	if(colpoint->next==newpoint&&newpoint!=head)
	{
		DLIST node=create_node(10);
		_add_list(node,colpoint,newpoint);
		
		DLIST col_next=colpoint->next;
		DLIST col_prev=colpoint->prev;
		DLIST new_next=newpoint->next;
		DLIST new_prev=newpoint->prev;

		newpoint->next=col_next;
		newpoint->prev=col_prev;
		colpoint->next=new_next;
		colpoint->prev=new_prev;
	
		col_prev->next=newpoint;
		col_next->prev=newpoint;
		new_prev->next=colpoint;
		new_next->prev=colpoint;
		_node_find_del(head,10);
	}
	else if(colpoint->next!=newpoint&&newpoint!=NULL)
	{
		DLIST col_next=colpoint->next;
		DLIST col_prev=colpoint->prev;
		DLIST new_next=newpoint->next;
		DLIST new_prev=newpoint->prev;

		newpoint->next=col_next;
		newpoint->prev=col_prev;
		colpoint->next=new_next;
		colpoint->prev=new_prev;
	
		col_prev->next=newpoint;
		col_next->prev=newpoint;
		new_prev->next=colpoint;
		new_next->prev=colpoint;
	}
}	
//如果某个节点是偶数,返回偶数的地址
DLIST even_find(DLIST head)
{
	DLIST p=NULL;
	for(p=head->next;p->next!=head;p=p->next)
	{
		if((p->data)%2==0&&(p->next->data)%2!=0)
			return p;
	}
	return NULL;
}
//#define IF_P_HEAD(p) (p->next->data)%2!=0&&(p->next->next-data)%2!=0
//如果某个节点是奇数,他前方面与后面都是偶数，着输出奇数
DLIST odd_find(DLIST head)
{
	DLIST p=NULL;
	for(p=head->next;p->next!=head;p=p->next)
	{
		//if((p->data)%2==0&&(p->next->data)%2!=0&&p->prev)
		if((p->data)%2==0&&p->next->data%2!=0)
				return p->next;
	}
	return NULL;
}

int main()
{
	DLIST p=NULL;
	DLIST head=create_head();
	DLIST arr[9]={NULL};
	
	int i;
	for(i=1;i<10;i++)
	{
		DLIST node=create_node(i);
		add_list_tail(node,head);
	}
	show_next(head);
	
	DLIST even=head;
	DLIST odd=head;
	// do
	// {
	// even=even_find(head);
	// printf("%d ",even->data);
	// odd=odd_find(head);
	// printf("%d \n",odd->data);
	
	// node_date_point(head,even,odd);
	// show_next(head);
	// }while(even!=NULL||odd!=NULL);
	
	while(even!=NULL||odd!=NULL)
	{
		even=even_find(head);
		printf("%d ",even->data);
		odd=odd_find(head);
		printf("%d \n",odd->data);
		if(even!=NULL||odd!=NULL)
		{
			node_date_point(head,even,odd);
			show_next(head);
		}
		show_next(head);
	}
		
	//node_date_point(even_find(head),odd_find(head));
	//show_next(head);
	
	// for(int i=i;i<=9;i+2)
	// {
	// list_find(DLIST head,int num)
	
	
/* 	show_prev(head);
	
	//查询删除
	_node_find_del(head,4);
	show_next(head);
	
	//改
	p=dlist_find(head,5,15);
	if(p!=NULL)
		show_next(head);
	
	//中间增加节点
	_add_list(create_node(52),list_find(head,1),list_find(head,2));
	show_next(head);
	return 0; */
}
	
	
	
	
	
	
	
	
	
	
	