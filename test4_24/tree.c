#include <stdio.h>
#include <stdlib.h>

typedef struct doubletree{
	int data;
	struct doubletree *left;
	struct doubletree *right;
}Dtree,*DTREE;

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

//插入节点
void insert(DTREE root,DTREE node)
{
	//当新节点的数值小于根节点时，将其插入在根节点的左子树
	if(root->data>node->data)
	{
		if(root->left!=NULL)
			insert(root->left,node);
		else
			root->left=node;		
	}
	else if(root->data<node->data)
	{
		if(root->right!=NULL)
			insert(root->right,node);
		else
			root->right=node;
	}
}

//先序遍历 根--左--右
void front_display(DTREE root)
{
	//先打印根节点
	printf("-%d-",root->data);
	
	//如果存在左子树就递归打印左子树
	if(root->left!=NULL)
		front_display(root->left);
	if(root->right!=NULL)
		front_display(root->right);
}

//中序遍历，左--根--右
void mid_display(DTREE root)
{
	if(root->left!=NULL)
		mid_display(root->left);
	
	printf("-%d-",root->data);
	
	if(root->right!=NULL)
		mid_display(root->right);
}

//后续遍历 ，左--右--根--
void last_display(DTREE root)
{
	if(root->left!=NULL)
		mid_display(root->left);
	
	if(root->right!=NULL)
		mid_display(root->right);
	printf("-%d-",root->data);
}

int main()
{
	int arr[8]={50,40,60,30,45,55,42,57};
	
	DTREE root=create_root(arr[0]);
	
	int i;
	for(i=1;i<8;i++)
	{
		DTREE node=create_root(arr[i]);
		insert(root,node);
	}
	
	front_display(root);
	printf("\n----------------------\n");
	
	mid_display(root);
	printf("\n----------------------\n");
	
	last_display(root);
	printf("\n----------------------\n");
	
	return 0;
}

	
	
	
	
	
	
