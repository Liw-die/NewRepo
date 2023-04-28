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

//单链表的插入排序
void insert_sort(LIST head)
{
	//链表中没有元素或者只有一个元素，不需要做排序
	if( head->next==NULL || head->next->next==NULL)
		return ;
	
	LIST a = head->next;//a始终指向已排序链表的末尾节点
	LIST p = a->next;//p始终指向未排序链表的首节点
	
	//直到p指针指向NULL之前，都需要做排序对比
	while(p != NULL)
	{
		//p节点要插入到a节点前面，因为是单链表，所以需要重新遍历
		//插入结束以后，a节点仍然是已排序节点的尾节点
		if( p->data < a->data)
		{
			//把p节点从链表中删除
			a->next = p->next;
			p->next = NULL;
			
			//重新遍历链表，找到比p->data要大的节点的前一个
			LIST q = head;
			while(q->next->data < p->data)
				q = q->next;

			//把p节点插入到 q与q->next之间
			p->next = q->next;
			q->next = p;
			
			//指针a仍然指向已排序链表的末尾节点
			//指针p指向了已排序链表的中间位置,需要重置p指针
			//a->next是未排序节点的首元素
			p = a->next;
		}
		
		//p节点插入到a节点的后面
		else if( p->data > a->data)
		{
			//p节点在链表中的位置保持不变
			//此时p是已排序链表的末尾
			//a是已排序链表的倒数第二个，两个指针都需要重置
			
			a = p;
			p = p->next;
		}

	}
}
int main()
{
	int arr[10]={5,8,1,2,3,7,6,0,9,4};
	LIST head=cresta_head();
	
	
	for(int i=0;i<10;i++)
	{
		LIST node=create_node(arr[i]);//创建子节点
		insert_front(head,node);//头部插入
		
	}
	shuowlist(head);
	insert_sort(head);
	shuowlist(head);
	
	
	return 0;
}













	
	
	