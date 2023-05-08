#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
int ID=20230000;

typedef struct isrctn{
	char user[12];
	unsigned int id;
	char pass[25];
	struct isrctn *next;
	struct isrctn *prev;
}Isrctn,*ISRCTN;
//创建head节点
ISRCTN create_head()
{
	ISRCTN head=malloc(sizeof(Isrctn));
	if(head==NULL)
	{
		perror("head malloc failed!");
		return NULL;
	}
	stpcpy(head->user,"user");
	head->id=0;
	stpcpy(head->pass,"pass");
	head->next=head;
	head->prev=head;
	return head;
}
//创建node节点
ISRCTN create_node(const char *user,const int id,const char *pass)
{
	ISRCTN node=malloc(sizeof(Isrctn));
	if(node==NULL)
	{
		perror("node malloc failed!");
		return NULL;
	}
	stpcpy(node->user,user);
	node->id=id;
	stpcpy(node->pass,pass);
	node->next=node;
	node->prev=node;
	return node;
}
//节点入链表
void jion_last(ISRCTN head,ISRCTN node)
{
	node->next=head;
	node->prev=head->next;
	
	head->prev->next=node;
	head->prev=node;
	head->id++;
}
//前节点是front，后节点是last
void _list_del(ISRCTN front,ISRCTN last)
{
	front->next=last;
	last->prev=front;
}
//删除目标节点dest
void list_del(ISRCTN dest)
{
	_list_del(dest->prev,dest->next);
	//free(dest);//释放要删除的节点的空间
}
//通过user查找节点,没找到返回head节点
ISRCTN find_user(ISRCTN head,const char *user)
{
	ISRCTN temp=head->next;
	while(temp!=head)
	{
		if(!(strcmp(temp->user,user)))
			break;
		temp=temp->next;
	}
	return temp;
}
//通过id查找节点,没找到返回head节点
ISRCTN find_id(ISRCTN head,unsigned int id)
{
	ISRCTN temp=head->next;
	while(temp!=head)
	{
		if(temp->id==id)
			break;
		temp=temp->next;
	}
	return temp;
}
//修改节点内的数据,只修改密码
void change_node(ISRCTN head,const char *user,const char *pass)
{
	ISRCTN temp=find_user(head,user);
	if(temp==head)
		printf("修改时查找失败");
	else
		stpcpy(temp->pass,pass);
}
//next指向遍历（右）
void show_last(ISRCTN head)
{
	//printf("head next:\n");
	ISRCTN p=head;
	printf("%s\t\t%d\t\t%s\n",p->user,p->id,p->pass);
	while(p->next!=head)
	{
		p=p->next;
		printf("%s\t%d\t%s\n",p->user,p->id,p->pass);
	}
	printf("\n");
}
ISRCTN del_first(ISRCTN head)//头删
{
	ISRCTN temp=head->next;
	head->next=temp->next;
	(temp->next)->prev=head;
	temp->next=temp;
	temp->prev;
	return temp;
}
//销毁链表--先将链表中所有的节点删除-销毁，最后销毁头节点
void dlist_destory(ISRCTN head)
{
	while(head->next!=head)
	{
		ISRCTN p=del_first(head);
		free(p);
	}
	free(head);
}

void show()//界面显示
{
	printf("---------------------------------\n");
	printf("--------    来啦官人！  ---------\n");
	printf("----- 1.注册   2登录  0退出 -----\n");
	printf("---------------------------------\n");
}
//注册
void user_show(ISRCTN head)
{
	char user[12]={0};
	char pass[25]={0};
	printf("请输入手机号和密码->");
	scanf("%s %s",user,pass);
	ISRCTN node=create_node(user,ID,pass);
	jion_last(head,node);
	printf("注册成功你的账号是%d\n",ID);
	ID++;
}
//登录
int longin_show(ISRCTN head)
{
	unsigned int id;
	char pass[25];
	printf("输入你的ID与密码!\n");
	scanf("%d %s",&id,pass);
	ISRCTN temp=NULL;
	temp=find_id(head,id);
	if(temp==head)
	{
		printf("你的id不存在!\n");
		return -1;
	}
	if(!(strcmp(temp->pass,pass)))
	{
		printf("登录成功!\n");
		return 1;
	}
	else if(strcmp(temp->pass,pass))
	{
		printf("密码错误!\n");
		return -1;
	}
}
//文件入链
void load_file(const char *sou_file,ISRCTN head)
{
	FILE *fp=fopen(sou_file,"r+");
	if(fp==NULL)
	{
		perror("error!");
		fclose(fp);
		return ;
	}
	char user[12]={0};
	int id;
	char pass[25]={0};
	int n;
	fscanf(fp,"%[^\t]\t%d\t%s",user,&n,pass);
	printf("%d\n",n);
	
	bzero(user,sizeof(user));
	bzero(pass,sizeof(pass));
	while(n)
	{
		
		for(int i=0;i < n;i++)
		{
			fscanf(fp,"%s\t%d\t%s",user,&id,pass);
			printf("%s %d %s\n",user,id,pass);
			ISRCTN node=create_node(user,id,pass);
			jion_last(head,node);
			bzero(user,sizeof(user));
			bzero(pass,sizeof(pass));
		}
		ID=id+1;
		break;
	}
	if(n==0)
		printf("空文件\n");
	fclose(fp);
}	
//链表输出到文件
void output_file(const char *sou_file,ISRCTN head)
{
	FILE *fp=fopen(sou_file,"w+");
	if(fp==NULL)
	{
		perror("error!");
		fclose(fp);
		return ;
	}
	fprintf(fp,"%s\t%d\t%s\n",head->user,head->id,head->pass);
	ISRCTN p=head->next;
	while(p!=head)
	{
		fprintf(fp,"%s\t%d\t%s\n",p->user,p->id,p->pass);
		p=p->next;
	}
	fclose(fp);
}
//打开一个目录,并将目录内文件入链
ISRCTN create_dir(ISRCTN head,const char *dirname,const char *filename)
{
	DIR *pd=opendir(dirname);
	if(pd==NULL)
	{
		printf("目录不存在\n");
		mkdir(dirname,0777);
		printf("创建目录成功\n");
	}
	struct dirent *p=readdir(pd);
	while(p!=NULL)
	{
		if(p->d_type==DT_REG)
			printf("[%s]是一个普通文件-\n",p->d_name);
		if(p->d_type==DT_DIR)
			printf("[%s]是一个目录文件\n",p->d_name);
		break;
		//p=readdir(pd);
	}
	char user[12]={0};
	int id;
	char pass[25]={0};
	ISRCTN node=NULL;
	chdir("./zhanghao");

		FILE *fp=fopen(filename,"r+");
		if(fp==NULL)
			printf("文件打开失败\n");
				
		fscanf(fp,"%s\t%d\t%s",user,&id,pass);
		printf("%s %d %s\n",user,id,pass);
		node=create_node(user,id,pass);
		jion_last(head,node);
		bzero(user,sizeof(user));
		bzero(pass,sizeof(pass));
		fclose(fp);

			
	if(p==NULL)
	{	
		printf("没有该ID\n");
		return NULL;
	}
	
	closedir(pd);
	return node;
}

//链表内数据存储到目录内的文件夹下
void stor_file(ISRCTN head,const char *dirname)
{
	char n[50]={0};
	getcwd(n,sizeof(n));
	printf("%s\n",n);
	ISRCTN p=head->next;
	printf("ggg\n");
	while(p!=head)
	{
		char file[30]={0};
		printf("ggg\n");
		sprintf(file, "%d", p->id);
		int len=strlen(file);
		file[len]='.';
		file[len+1]='t';
		file[len+2]='x';
		file[len+3]='t';
		printf("%s\n",file);
		char ppp[10]={0};
		strcpy(ppp,file);
		FILE *fp=fopen(ppp,"w+");
		fprintf(fp,"%s\t%d\t%s\n",p->user,p->id,p->pass);
		p=p->next;
		fclose(fp);
	}
}
int main(void)
{
	int input;
	ISRCTN head=create_head();
	//
	//load_file("6.txt",head);
	char dir[50]={0};
	char file[50]={0};
	//printf("请输入要打开的目录->");
	//scanf("%s",dir);
	//printf("请输入要打开的文件->");
	//scanf("%s",file);
	ISRCTN node=create_dir(head,"zhanghao","22056.txt");
	while(1)
	{
		show();
		scanf("%d",&input);
		switch(input)
		{
			case 0:
				break;
			case 1:
				user_show(head);
				show_last(head);
				continue;
			case 2:
				longin_show(head);
				continue;
		}
		break;
	}
	stor_file(head,"zhanghao");
	//output_file("6.txt",head);
	dlist_destory(head);
	return 0;
}