#include "list.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STU.h"
#define uint_32 unsigned int 
#define COO_X 20 //外框的原点坐标X
#define COO_Y 5	 //外框的原点坐标y

// #define STU_STR "STU_MAN_SYSTEM"
// #define STU_WELCOME "     Welcome to the Student Management System   "
// #define STU_1	    "                                                "
// #define STU_INCER 	" Increase student Information "
// #define STU_QUERY 	" Query    Student Information "
// #define STU_FIND 	" Find     Student Information "
// #define STU_MODIFY 	" Modify   Student Information "
// #define STU_INTE 	"-->"
// #define STU_CHAR 	4
int stu_ch[4]={4,5,6,7};
int N[4]={0,1,2,3};
int *p=N;
void show_stu_inte(int i);
void show_stu_char();

typedef struct stu{
	char name[15];
	uint_32 age;
	uint_32 id;
	struct list_head list;
}Stu,*STU;
//创建头节点
STU create_head()
{
	STU head=(STU)malloc(sizeof(Stu));
	if(head==NULL)
	{
		perror("head malloc fialed(失败)");
		return NULL;
	}
	
	head->list.next=&head->list;
	head->list.prev=&head->list;
	return head;
}
//创建普通节点
STU create_node(char *name,uint_32 age,uint_32 id)
{
	STU node=(STU)malloc(sizeof(Stu));
	if(node==NULL)
	{
		perror("node malloc fialed(失败)");
		return NULL;
	}
	strcpy(node->name,name);
	node->age=age;
	node->id=id;
	node->list.next=&node->list;
	node->list.prev=&node->list;
	return node;
}
/* int input_dete_stu(char* name,uint_32 *age,uint_32 *id)
{
	printf("")
}	 */

//一级界面按键检测
void key_show_inte()
{
	keypad(stdscr,TRUE);
	//mvprintw(0,0,"%d",temp);
	while(1)
	{
		int ch = getch(); // 获取用户输入

			if(ch==KEY_UP)
			{
				show_stu_char();
				if(p==&N[0])
					p=&N[3];
				else
					p--;
				show_stu_inte(stu_ch[*p]);
				refresh();
			}
			else if(ch==KEY_DOWN)
			{
				show_stu_char();
				if(p==&N[3])
					p=N;
				else
					p++;
				show_stu_inte(stu_ch[*p]);
				refresh();
			}
			else if(ch==27)//Esc
				break;//考虑是否需要返回值来结束整个程序
			// else if(ch==13)
			// {
				// switch(*p)
				// {
					// case 0:
					
					// case 1:
					// case 2:
				// case 3:}
				
	}
}
//二级新增界面显示
void show_please()
{

	attron(COLOR_PAIR(3));//欢迎字符
	mvprintw(COO_Y+1,COO_X+1,"%s",STU_INCER);
	attroff(COLOR_PAIR(3));
	
	attron(COLOR_PAIR(7));
	mvprintw(COO_Y+2,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+3,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+4,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+5,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+6,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+7,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+8,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+9,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+10,COO_X+1,"%s",STU_1);
	attroff(COLOR_PAIR(7));
	
	attron(COLOR_PAIR(8));
	mvprintw(COO_Y+4,COO_X+10,"%s",_name);
	mvprintw(COO_Y+5,COO_X+10,"%s",_age);
	mvprintw(COO_Y+6,COO_X+10,"%s",_id);
	attroff(COLOR_PAIR(8));
}
	
//一级界面箭头
void show_stu_inte(int i)
{
	attron(COLOR_PAIR(8));//箭头指向
	mvprintw(COO_Y+i,COO_X+4,"%s",STU_INTE);
	attroff(COLOR_PAIR(8));
}
//一级字符串显示
void show_stu_char()
{
	attron(COLOR_PAIR(2));
	//开启加粗模式
	attron(A_BOLD);
	mvprintw(4,38,"%s",STU_STR);
	attroff(A_BOLD);				//关闭加粗
	attroff(COLOR_PAIR(2));	
	
	attron(COLOR_PAIR(3));//欢迎字符
	mvprintw(COO_Y+1,COO_X+1,"%s",STU_WELCOME);
	attroff(COLOR_PAIR(3));
	
	attron(COLOR_PAIR(7));
	mvprintw(COO_Y+2,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+3,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+4,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+5,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+6,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+7,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+8,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+9,COO_X+1,"%s",STU_1);
	mvprintw(COO_Y+10,COO_X+1,"%s",STU_1);
	attroff(COLOR_PAIR(7));
	
	attron(COLOR_PAIR(8));
	mvprintw(COO_Y+4,COO_X+10,"%s",STU_INCER);
	mvprintw(COO_Y+5,COO_X+10,"%s",STU_QUERY);
	mvprintw(COO_Y+6,COO_X+10,"%s",STU_FIND);
	mvprintw(COO_Y+7,COO_X+10,"%s",STU_MODIFY);
	attroff(COLOR_PAIR(8));
}
//显示外框
void color_profile()
{
	//开启颜色索引5
	attron(COLOR_PAIR(5));
	//开启加粗模式
	attron(A_BOLD);
    move(COO_Y,COO_X);          	//移动光标
	hline(ACS_CKBOARD,50);		  	//从左上角(5,20)的位置去绘制 
	move(COO_Y+11,COO_X);			//移动光标
	hline(ACS_CKBOARD,50);			//从左上角(16,20)
	move(COO_Y+1,COO_X+49);			//把光标移动到(6,69)的位置
	vline(ACS_CKBOARD,10);			
	move(COO_Y+1,COO_X);			//把光标移动到(6,20)的位置
	vline(ACS_CKBOARD,10);			
	attroff(COLOR_PAIR(5));			//关闭颜色索引1
	attroff(A_BOLD);				//关闭加粗
	refresh();						//刷新显示
}

void show_stu()
{
	initscr();//初始化curses库
	start_color();//开启颜色索引
	init_pair(1, COLOR_BLACK , COLOR_BLACK);//设置颜色索引1,黑,背景黑--
	init_pair(2, COLOR_RED, COLOR_BLACK);//2,红,背景黑--
	init_pair(3, COLOR_WHITE,COLOR_GREEN);//3,白,背景绿--
	init_pair(4, COLOR_YELLOW , COLOR_BLACK);//4,黄,背景黑--
	init_pair(5, COLOR_BLUE  , COLOR_BLACK);//5,蓝,背景黑--
	init_pair(6, COLOR_MAGENTA  , COLOR_BLACK);//6,粉,背景黑--
	init_pair(7, COLOR_WHITE , COLOR_WHITE);//7,白,背景白--
	init_pair(8, COLOR_BLACK , COLOR_WHITE);//8,白,背景黑--
	
	//color_profile();
	show_please();
	show_stu_char();
	show_stu_inte(4);
	key_show_inte();
	refresh();
}
	
int main()
{
	show_stu();
	//getch();                        //等待用户输入
    endwin();                       //结束curses库
}