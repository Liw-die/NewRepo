#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 250

typedef struct hash{
	int arr;
	int cnt;
	struct hash *next;//下一个节点的指针
}Hash,*HASH;


//创建无序数组
int *get_arr()
{
	int *arr =calloc(NUM,sizeof(int));
	if(arr==NULL)
	{
		printf("calloc arr failed\n");
		return NULL;
	}
	
	int i;
	for(i=0;i<NUM;i++)
	{
		int data;
		data=rand()%256;
		arr[i] = data;
	}
	return arr;
}

//把字符串转成四进制的数，然后再转换成对应的十进制数值
int str_to_int(char *str)
{
	int a[4];
	int i;
	for(i=0;i<4;i++)
	{
		switch(str[i]){
			case 'A':
				a[i] = 0; break;
			case 'C':
				a[i] = 1; break;
			case 'T':
				a[i] = 2; break;
			case 'G':
				a[i] = 3; break;
		
		}
	}
	int data = a[0]*4*4*4 + a[1]*4*4 + a[2]*4 + a[3];
	
	return data;
}

//把十进制数值转成四进制，然后换算成对应的字符串
char *int_to_str(int data)
{
	int a[4];
	int i;
	for(i=0;i<4;i++)
	{
		a[i] = data%4;
		data /=4;
	}
	char *buf=calloc(5,sizeof(char));
	for(i=0;i<4;i++)
	{
		switch( a[i] ){
			case 0:
				buf[3-i] = 'A'; break;
			case 1:
				buf[3-i] = 'C'; break;
			case 2:
				buf[3-i] = 'T'; break;
			case 3:
				buf[3-i] = 'G'; break;
		}
	}
	return buf;
}
//队列排序
int compar_char(const void *p1,const void *p2)
{
	//修改数据类型
	const int *left = p1;
	const int *right= p2;
	
	if( *left < *right )
		return 0;
	else
		return 1;
	
}
//创建哈希表
HASH create_hash(int *arr)
{
	HASH my_node = malloc(sizeof(Hash));
	if(my_node == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}	
	my_node->arr=arr[0];
	my_node->cnt++;//计数自增
	my_node->next = NULL;//指向空
	for(int i=0;i<NUM;i++)
	{
		
		HASH temp=my_node;
		if(arr[i]==my_node->arr)
		{
			temp->cnt++;//计数自增
		}
		else
		{
			HASH my_node = malloc(sizeof(Hash));
			my_node->arr=arr[i];
			my_node->cnt++;//计数自增
			my_node->next = NULL;//指向空
			temp->next=my_node;
				
		}
	}



	return my_node;
}
int main()
{
	srand(time(NULL));
	int *arr=get_arr();
	//本质上是快速排序
	qsort(arr,250,sizeof(int),compar_char);
	
/* 	for(int i=0;i<250;i++)
	{
		char *str=int_to_str(arr[i]);
		printf("-%s-",str);
	}
	printf("\n"); */
		
	HASH node=create_hash(arr);
	HASH p=node;
	while(p!=NULL)
	{
		char *my_str=int_to_str(p->arr);
		printf("%s,出现%d次",my_str,p->cnt);
		p = p->next;
	}	
	
	return 0;
}
