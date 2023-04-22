#include <stdio.h>
#include <stdlib.h>


typedef struct list{
	int data;
	struct list *next;
}List,*LIST;

LIST cresta_head()//创建头节点
{
	LIST head=malloc(sizeof(List));
	if(head==NULL)
	{
		printf("head申请失败");
		return NULL;
	}
	
	head->next=malloc(sizeof(List));
	if(head->next==NULL)
	{
		printf("head->next申请失败");
		return NULL;
	}
	
	head->next=NULL;
	return head;
}

LIST create_node(int num)//创建子节点
{
	LIST node = malloc(sizeof(List));
	if(node==NULL)
	{
		printf("node申请失败");
		return NULL;
	}
	node->data=num;
	node->next=NULL;
	
	return node;
}

void insert_front(LIST head,LIST node)//头部插入
{
	node->next=head->next;
	
	head->next=node;
}

void insert_last(LIST head,LIST node)//尾部插入
{
	LIST p=node;
	while(p!=NULL)
		p=p->next;
	p->next=node;
}


//遍历
void shuowlist(LIST head)
{
	printf("head-");
	
	LIST p=head;
	
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d-",p->data);
	}
	printf("\n");
}

/* int insert_data()//输入判断
{
	int temp;
	while(1)
	{
		int n=scanf("%d",&temp);
		if(n==-1)
		{
			while(getch()!='\n');
			continue;
		}
		else
			return temp;
	}
} */

//头部删除,删除head头节点后面的节点，被删除的节点没有被释放，所以返回被删除的节点地址
LIST del_front(LIST head)
{
	LIST temp=head->next;//先拿到需要被删除的节点的地址
	head->next=head->next->next;//在将头节点指向的下一个节点重新指被删除的节点后的节点地址
	return temp;//返回被删除的节点地址，以便被释放
}

//尾部删除，删除链表中尾部的节点，也需要返回被删除的节点的地址
LIST del_last(LIST head)
{
	LIST p=head;
	if(p->next==NULL)//首先判断节点是否为空
	{
		printf("链表为空");
		return NULL;
	}
	//循环结束时p将指向链表中的倒数第二节点
	while(p->next->next!=NULL)
		p=p->next;
	//定义p指向尾节点
	LIST temp=p->next;
	
	p->next=NULL;//将倒数第二个节点的next指向空
	return temp;
}
//查找节点
LIST find_dest(LIST head,int num)
{
	LIST p=head;
	while(p->next!=NULL)
	{
		p=p->next;//将指针p后移到下一个节点
		if(p->data==num)//判断该节点的数据
			return p;
	}
	return NULL;//如果没有找到返回空
}

//修改节点的数据
void change_data(LIST head,int old,int new)//old原始数据，new修改数据
{
	LIST temp=find_dest(head,old);//调用查找节点的函数
	if(temp!=NULL)
	{
		temp->data=new;
	}
	else
		printf("没有找到该数据");
}

int main()
{
	LIST head=cresta_head();
	LIST temp;
	
	for(int i=0;i<10;i++)
	{
		LIST node=create_node(20*i);//创建子节点
		insert_front(head,node);//头部插入
		
	}
	shuowlist(head);
	
	/* temp=del_front(head);删除头部的一个节点
	free(temp); */
	
	/* temp=del_last(head);尾部删除一个节点
	free(temp); */
	
	temp = del_last(head);
	if(temp!=NULL)
		free(temp);
	
	shuowlist(head);
	temp = find_dest(head,100);
	if(temp!=NULL)
		printf("查找成功，temp=%p,temp->data=%d\n",temp,temp->data);
	else
		printf("查找失败，链表中没有该值\n");
	
	change_data(head,40,55);
	shuowlist(head);
	
	
	return 0;
}













	
	
	