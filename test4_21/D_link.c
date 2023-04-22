#include <stdio.h>
#include <stdlib.h>

typedef struct dlink
{
	int data;
	struct dlink *next;
	struct dlink *prev;
}Dlink,*DLINK;	

//创建头部链表
DLINK create_head()
{
	DLINK head=malloc(sizeof(Dlink));
	if(head==NULL)
	{
		printf("head申请失败");
		return NULL;
	}
	//循环链表创建后要让指针指向自己以形成一个循环链表
	head->next=head;
	head->prev=head;
	
	return head;
}

//创建普通节点
DLINK create_node(int num)
{
	DLINK node=malloc(sizeof(Dlink));
	if(node==NULL)
	{
		printf("node申请失败");
		return NULL;
	}
	node->data=num;
	node->next=node;
	node->prev=node;
	
	return node;
}

//任意节点插入,将node节点插入到front和last节点之间
void _add_list(DLINK node,DLINK front,DLINK last)
{
	node->next=last;
	node->prev=front;
	
	front->next=node;
	last->prev=node;
}

//优化后的将node节点插入到首元素的位置
void add_list_head(DLINK head,DLINK node)
{
	_add_list(node,head,head->next);
}

//优化后的将node节点插入到末尾的位置
void add_list_tail(DLINK head,DLINK node)
{
	_add_list(node,head->prev,head);
}

//插入到首元素的位置
void insert_first(DLINK head,DLINK node)
{
	//第一步将要插入的next地址指向head(next)节点指向的首元素的地址
	//第二步将要插入的prev的地址指向head节点的地址
	node->next=head->next;
	node->prev=head;
	
	//修改插入后原首元素的地址head->next==原首元素的地址，其地址的prev要指向插入的元素的地址
	(head->next)->prev=node;
	//原首元素->next是原首元素的下一个元素的地址，不必修改
	
	//最后将head节点的next指向插入的node地址
	head->next=node;
}

//尾部插入
void insert_last(DLINK head,DLINK node)
{
	//将要插入的节点node的next指向head
	//将要插入的节点node的prev指向头节点指向原尾节点（head->prev）
	node->next=head;
	node->prev=head->prev;
	
	//将原来尾节点的next指向head改为指向新节点的地址
	//原为尾节点的prev指向的是原节点的前一个元素的地址
	(head->prev)->next=node;
	
	//最后修改head节点prev指向，指至新节点的地址
	head->prev=node;
}

//优化后的next指向遍历,使用宏定义来进行设计
#define list_for_each(p,head) for(p=head->next;p!=head;p=p->next)
void SHOW_next(DLINK head)
{
	printf("head next:");
	//首先定义一个临时变量
	DLINK p=NULL;
	//for(p=head-next;p!=head;p=p->next)
	//使用宏定义来代替for循环
	list_for_each(p,head)
		printf("-%d-",p->data);
	printf("\n");
}

//优化后的prev指向遍历,使用宏定义来进行设计
#define list_for_each_prev(p,head) for(p=head->prev;p!=head;p=p->prev)
void SHOW_prev(DLINK head)
{
	printf("head next:");
	//首先定义一个临时变量
	DLINK p=NULL;
	list_for_each_prev(p,head)
		printf("-%d-",p->data);
	printf("\n");
}
//next指向遍历（右）
void show_next(DLINK head)
{
	printf("head next:");
	DLINK p=head;
	while(p->next!=head)
	{
		p=p->next;
		printf("-%d-",p->data);
	}
	printf("\n");
}

//prev指向遍历（尾部向左）
void show_prev(DLINK head)
{
	printf("head prev:");
	DLINK p=head;
	while(p->prev!=head)
	{
		p=p->prev;
		printf("-%d-",p->data);
	}
	printf("\n");
}

//优化后的删除任意节点，假设该节点的前节点是front，后节点是last
void _list_del(DLINK front,DLINK last)
{
	front->next=last;
	last->prev=front;
}
//优化，是目标节点dest
void list_del(DLINK dest)
{
	_list_del(dest->prev,dest->next);
	//free(dest);//释放要删除的节点的空间
}

//头部删除
DLINK del_first(DLINK head)
{
	//首先定义一个临时变量来存储所要删除的节点的地址
	//在将头部head->next所指向的删除节点的地址改为删除节点后面的地址
	//在将所删除节点的下一个节点的prev指向head
	DLINK temp=head->next;
	head->next=temp->next;
	(temp->next)->prev=head;
	
	//将所删除的节点的内容初始化（使其不再指向head和下一节点）
	temp->next=temp;
	temp->prev;
	return temp;
}

//尾部删除
DLINK del_last(DLINK head)
{
	//首先定义一个临时变量来存储所要删除的节点的地址
	//在将头部head->prev所指向的删除节点的地址改为删除节点前面的地址
	//在将所删除节点的前一个节点的prev指向head
	DLINK temp=head->prev;
	(temp->prev)->next=head;
	head->prev=temp->prev;
	
	//将所删除的节点的内容初始化（使其不再指向head和下一节点）
	temp->next=temp;
	temp->prev=temp;
	
	return temp;
}

//查找节点
DLINK dlist_find(DLINK head,int num)
{
	//先将定义一个临时变量p用来存放首元素的地址
	//在循环遍历整个链表（直到p=head）来查找num
	DLINK p=head->next;
	while(p!=head)
	{
		if(p->data==num)
			break;
		p=p->next;
	}
	//注意要是没有找到此时返回的将是head
	return p;
}

//修改节点内的数据，首先调用dlist_find函数来查找要修改的元素
void dlist_change(DLINK head,int lodnum,int newnum)
{
	DLINK p=dlist_find(head,lodnum);
	if(p==head)
		printf("修改时查找失败");
	else
		p->data=newnum;
}
//销毁链表--先将链表中所有的节点删除-销毁，最后销毁头节点
void dlist_destory(DLINK head)
{
	while(head->next!=head)
	{
		DLINK p=del_first(head);
		printf("销毁节点：%d\n",p->data);
		free(p);
	}
	free(head);
}

int main()
{
	DLINK t=NULL;
	DLINK head=create_head();
	
	int i;
	for(i=1;i<11;i++)
	{
		DLINK node=create_node(i);
		add_list_tail(head,node);//尾部插入
	}
	SHOW_next(head);
	SHOW_prev(head);
	printf("---------------------\n");
	
	t=head->prev;
	list_del(t);//删除节点t
	free(t);
	SHOW_next(head);
	SHOW_prev(head);
	return 0;	
}