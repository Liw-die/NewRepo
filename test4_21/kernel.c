#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct klist{
	int data;//数据域
	struct list_head list;//小结构体的指针域
}Klist,*KLIST;

//创建头节点
KLIST create_head()
{
	KLIST head = malloc(sizeof(Klist));
	if(head==NULL)
	{
		printf("head malloc申请失败");
		return NULL;
	}
	head->list.next=&head->list;
	head->list.prev=&head->list;
	
	return head;
}

//创建普通节点
KLIST create_node(int num)
{
	KLIST node = malloc(sizeof(Klist));
	if(node==NULL)
	{
		printf("node malloc申请失败");
		return NULL;
	}
	node->data=num;
	
	node->list.next=&node->list;
	node->list.prev=&node->list;
	
	return node;
}

//添加的API接口 ---参数是小结构体指针
//static inline void list_add_tail(struct list_head *_new, struct list_head *head)

//删除的API接口
//static inline void list_del(struct list_head *entry)

//遍历循环
/*
head->next 拿到的是小结构体，此处的head是小结构体的头结点，不是我们自定义的大结构体头结点，两者仅仅同名

#define list_for_each_entry()(pos, head, member)				\
	for (pos = list_entry((head)->next, typeof(*pos), member);	 //获取链表的第1个大结构体
		&pos->member != (head); 	\ //小结构体地址不能等于头节点
	     pos = list_entry(pos->member.next, typeof(*pos), member)) //得到下一个大结构体的地址
*/

int main()
{
	KLIST head=create_head();
	
	int i;
	for(i=1;i<10;i++)
	{
		KLIST node=create_node(i*10);
		list_add_tail(&node->list,&head->list);
	}
	
	//遍历
	KLIST pos=NULL;
	list_for_each_entry(pos,&head->list,list)
	{
		printf("-%d-",pos->data);
	}
	printf("\n");
	
	//删除节点---删除首元素
	struct list_head *p = head->list.next;
	list_del(p);
	
	//要被释放的是大结构体的堆空间
	pos = list_entry(p,Klist,list);
	free(pos);
	
	//遍历
	pos=NULL;
	list_for_each_entry(pos,&head->list,list)
	{
		printf("-%d-",pos->data);
	}
	printf("\n");
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
