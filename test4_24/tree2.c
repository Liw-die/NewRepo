#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//创建二叉树节点类型
typedef struct doubletree{
	int data;//数据段
	struct doubletree *left;//二叉树的左子树
	struct doubletree *right;//二叉树的右子树
}Dtree,*DTREE;

//创建队列 
typedef struct doublenode{
	DTREE dest;//指向二叉树节点的指针
	struct doublenode *next;//数据域,指向的是队列中下一个节点的地址。
}Dnode,*DNODE;

//创建队列控制结构体
typedef struct doubleque
{
	int size;//元素个数
	DNODE front;//始终指向第一个入队的节点
	DNODE last;//始终指向最后一个入队的节点
}Dque,*DQUE;

//创建根节点/普通节点
DTREE create_root(int num)
{
	DTREE root=malloc(sizeof(Dtree));
	if(root==NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	root->data=num;
	root->left=NULL;
	root->right=NULL;
	
	return root;
}

//节点插入
void insert(DTREE root,DTREE node)
{
	//判断新节点的值
	if(root->data>node->data)
	{
		if(root->left!=NULL)
			insert(root->left,node);
		else
			root->left=node;
	}
	else if(root->data < node->data)
	{
		if(root->right!=NULL)
			insert(root->right,node);
		else
			root->right = node;
	}
}

//前序遍历 根--左--右
void front_display(DTREE root)
{
	printf("-%d-",root->data);
	if(root->left != NULL)
		front_display(root->left);
	if(root->right != NULL)
		front_display(root->right);
}

//中序遍历 左--根--右
void mid_display(DTREE root)
{
	if(root->left != NULL)
		mid_display(root->left);
	printf("-%d-",root->data);
	if(root->right != NULL)
		mid_display(root->right);
}

//后续遍历 左--右--根
void last_display(DTREE root)
{
	if(root->left!=NULL)
		last_display(root->left);
	if(root->right != NULL)
		last_display(root->right);
	printf("-%d-",root->data);
}

//创建队列控制节点
DQUE create_que()
{
	DQUE que=malloc(sizeof(Dque));
	if(que==NULL)
	{
		perror("que malloc failed\n");
		return NULL;
	}
	que->size=0;
	que->front=NULL;//先指空，在后续操作时始终指向第一个入队的节点
	que->last=NULL;//先指空，在后续操作时始终指向最后一个入队的节点
	
	return que;
}

//创建队列普通节点
DNODE create_dnode(DTREE ptr)//注意队列元素是二叉树的节点
{
	DNODE node=malloc(sizeof(Dnode));
	if(node==NULL)
	{
		perror("node malloc failed\n");
		return NULL;
	}
	node->dest=ptr;//队列的元素要指向二叉树的节点
	node->next=NULL;
	
	return node;
}

//入队,传入一个控制节点，一个新节点
void que_push(DQUE que,DNODE node)
{
	if(que->size==0)//如果队列没有元素
	{
		que->front=node;//控制节点的front指向第一个节点地址
		que->last=node;//控制节点的last指向最后一个节点的地址
		que->size++;
	}
	else//如果队列中有元素
	{
		que->last->next=node;//则que->last指向队列的下一个next的地址为新节点的地址
		que->last=node;//则que->last指向新队列的最后一个元素
		que->size++;
	}
}

//判断队列是否为空,(因为在队列为空/不为空时,队列,链表,指向或为空)
//注意二叉树的元素可以是无限的，所以不需进行队列满溢检查
bool Is_empty(DQUE que)
{
	return que->size== 0;//队列链表中的元素个数为0时为空
}

//出队,传入一个控制节点,(队列先进先出)注意free
DNODE que_pop(DQUE que)
{
	if(Is_empty(que))
		return NULL;//队列为空返回
	DNODE p=que->front;//队列先进先出,所以拿到第一个元素的地址
	que->front=p->next;//在将front重新指向出队后的新的节点
	que->size--;
	
	return p;//注意释放被出队的内存
}

//二叉树的按层遍历
void show(DTREE root)
{
	//创建队列控制节点
	DQUE que=create_que();
	
	DNODE node=create_dnode(root);//创建队列的第一个节点,并将根节点放入队列
	//入队
	que_push(que,node);
	
	//队列不为空继续循环
	while(!Is_empty(que))
	{
		//出队一个元素
		DNODE p=que_pop(que);
		
		//判断出队的节点是否有左子节点
		if(p->dest->left!=NULL)
		{
			//创建一个左节点的元素,并把元素入队
			node=create_dnode(p->dest->left);
			que_push(que,node);
		}
		
		//判断出队的节点是否有右子节点
		if(p->dest->right!=NULL)
		{
			//创建一个右节点的元素，并把该元素入队
			node=create_dnode(p->dest->right);
			que_push(que,node);
		}
		
		printf("-%d-",p->dest->data);
		free(p);
	}
	
	free(que);
}

int main()
{
	int arr[8]={50,40,60,30,45,55,42,57};
	DTREE root=create_root(arr[0]);
	
	int i;
	for(i=1;i<8;i++)
	{
		DTREE node = create_root(arr[i]);
		insert(root,node);
	}
	
	front_display(root);
	printf("\n--------------\n");
	
	mid_display(root);
	printf("\n--------------\n");
	
	last_display(root);
	printf("\n--------------\n");
	
	show(root);
	printf("\n--------------\n");
	
	return 0;
}