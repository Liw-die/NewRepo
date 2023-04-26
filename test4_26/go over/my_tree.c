#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
}Tree,*TREE;

typedef struct diublenode{
	TREE dest;
	struct diublenode *next;
}Dnode,*DNODE;

typedef struct diubleque{
	TREE size;
	DNODE front;
	DNODE last;
}Dque,*DQUE;

DQUE create_que()
{
	DQUE que=malloc(sizeof(Dque));
	if(que==NULL)
	{
		perror("que malloc failed!");
		return NULL;
	}
	que->size=0;
	que->front=NULL;
	que->last=NULL;
	return que;
}
DNODE create_dnode(TREE ptr)
{
	DNODE node=malloc(sizeof(Dnode));
	if(node==NULL)
	{
		perror("node malloc failed!");
		return NULL;
	}
	node->dest=ptr;
	node->next=NULL;
	return node;
}
void join_que(DQUE que,DNODE node)
{
	if(que->size==0)
	{
		que->front=node;
		que->last=node;
		que->size++;
	}
	else
	{
		que->last->next=node;
		que->last=node;
		que->size++;
	}
}
bool Is_empty(DQUE que)
{
	return que->size==0;
}
DNODE out_que(DQUE que)
{
	if(Is_empty(que))
	{
		printf("空链表！\n");
		return NULL;
	}
	DNODE temp=que->front;
	que->front=que->front->next;
	que->size--;
	return temp;
}


TREE create_root(int num)
{
	TREE root=malloc(sizeof(Tree));
	if(root==NULL)
	{
		perror("root malloc failed");
		return NULL;
	}
	root->data=num;
	root->left=NULL;
	root->right=NULL;
	return root;
}

void insert_tree(TREE root,TREE node)
{
	if(node->data < root->data)
	{
		if(root->left!=NULL)
			insert_tree(root->left,node);
		else
			root->left=node;
	}
	else if(node->data > root->data)
	{
		if(root->right!=NULL)
			insert_tree(root->right,node);
		else
			root->right=node;
	}
}

//前序遍历 根左右
void front_display(TREE root)
{
	printf("-%d-",root->data);
	
	if(root->left!=NULL)
		front_display(root->left);
	
	if(root->right!=NULL)
		front_display(root->right);
}
//中序遍历 左根右
void mid_display(TREE root)
{
	if(root->left!=NULL)
		front_display(root->left);
	
	printf("-%d-",root->data);
	
	if(root->right!=NULL)
		front_display(root->right);
}
//后序遍历 左根右
void last_display(TREE root)
{
	if(root->left!=NULL)
		front_display(root->left);
	
	if(root->right!=NULL)
		front_display(root->right);
	
	printf("-%d-",root->data);
}
//按层遍历
void show(TREE root)
{
	DQUE que=create_que();
	DNODE node=create_dnode(root);
	join_que(que,node);
	while(!Is_empty(que))
	{
		DNODE temp=out_que(que);
		if(temp->dest->left!=NULL)
		{
			DNODE node=create_dnode(temp->dest->left);
			join_que(que,node);
		}
		if(temp->dest->right!=NULL)
		{
			DNODE node=create_dnode(temp->dest->right);
			join_que(que,node);
		}
		printf("-%d-",temp->dest->data);
		free(temp);
	}
	printf("\n");
	free(que);
}
TREE del_tree(TREE root,int num)
{
	if(root->data > num)
	{
		if(root->left!=NULL)
			root->left = del_tree(root->left,num);
		else
			printf("无该节点\n");
	}
	else if(root->data < num)
	{
		if(root->right!=NULL)
			root->right = del_tree(root->right,num);
		else
			printf("无该节点\n");
	}
	else
	{
		if(root->left!=NULL)
		{
			TREE max = root->left;
			while(max->right!=NULL)
				max=max->right;
			root->data=max->data;
			root->left=del_tree(root->left,max->data);
		}
		else if(root->right!=NULL)
		{
			TREE min = root->right;
			while(min->right!=NULL)
				min=min->left;
			root->data=min->data;
			root->right=del_tree(root->right,min->data);
		}
		else
		{
			free(root);
			return NULL;
		}
	}
	return root;
}
		
int main(void)
{
	int  arr[8] = {50,40,60,30,45,55,42,57};
	
	TREE root = create_root(arr[0]);
	
	int i;
	for(i=1;i<8;i++)
	{
		TREE node = create_root(arr[i]);
		insert_tree(root,node);
	}
	
	front_display(root);
	printf("\n==================\n");
	
	mid_display(root);
	printf("\n==================\n");
	
	last_display(root);
	printf("\n==================\n");
	
	del_tree(root,60);
	show(root);
	return 0;
}
		
		
		
		