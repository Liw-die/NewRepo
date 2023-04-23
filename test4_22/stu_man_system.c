#include "list.h"
#include "STU.h"
int stu_ch[4]={4,5,6,7};
int N[4]={0,1,2,3};
int *p=N;

typedef struct stu{
	char name[15];
	uint_32 age;
	uint_32 id;
	struct list_head list;
}Stu,*STU;

STU head = NULL;
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
	char name[15];
	uint_32 age;
	uint_32 id;	
	//mvprintw(0,0,"%d",temp);
	while(1)
	{
		show_stu_char();//一级字符串显示
		show_stu_inte(stu_ch[*p]);//箭头显示
		int ch = getch(); // 获取用户输入
		//mvprintw(0,0,"%d",ch);
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
			{
				// attron(COLOR_PAIR(4));
				// mvprintw(COO_Y+9,COO_X+14,"%s","Press EXC once to exit");
				// refresh();
				// attroff(COLOR_PAIR(4));
				break;//考虑是否需要返回值来结束整个程序
			}
			else if(ch==10)//回车键
			{
				switch(*p)//判断目前小箭头所指状态
				{
					case 0://新增
						show_please();
						refresh();
						move(COO_Y+4,COO_X+23);
											
						scanw("%s",name);
						show_please();
						
						move(COO_Y+5,COO_X+22);	
						scanw("%d",&age);
						show_please();
						
						move(COO_Y+6,COO_X+21);
						scanw("%d",&id);
						
						show_please();//二级新增界面显示					
						STU node=create_node(name,age,id);
						list_add_tail(&node->list,&head->list);
						refresh();
						continue;
					case 1://删除
						show_delete();
						move(COO_Y+4,COO_X+21);					
						scanw("%d",&id);
						STU pos=NULL;
						
						while(1)
						{
							list_for_each_entry(pos,&head->list,list)
							{
								attron(COLOR_PAIR(3));
								if(pos->id==id)
								{
									list_del(&pos->list);
									//free(&pos->list);
									Clear_screen();//先清屏
									
									
									mvprintw(COO_Y+2,COO_X+17,"%s",delete_prosper);//显示查找成功
									
									mvprintw(COO_Y+8,COO_X+15,"%s","Press any key to exit");//提示按下任意键退出
									attroff(COLOR_PAIR(3));
									getch();
									goto end_delete;
								}	
								
							}
							Clear_screen();//先清屏
							attron(COLOR_PAIR(3));
							mvprintw(COO_Y+1,COO_X+1,"%s",_STU_FIND);//二级标头
							attroff(COLOR_PAIR(3));
							attron(A_BOLD);//开启加粗模式
							attron(COLOR_PAIR(4));
							mvprintw(COO_Y+5,COO_X+18,"%s",delete_fail);//显示删除失败
							mvprintw(COO_Y+8,COO_X+14,"%s","Press any key to exit");
							attroff(A_BOLD);//关闭加粗
							attroff(COLOR_PAIR(4));
							getch();
							goto end_delete;
						}
						end_delete:
						continue;
						
						getch();
						continue;
					case 2://查找
						show_seek();
							
						move(COO_Y+4,COO_X+23);					
						scanw("%d",&id);
						refresh();					
						pos=NULL;
						//STU pos=NULL;						
						while(1)
						{
							list_for_each_entry(pos,&head->list,list)
							{
								attron(COLOR_PAIR(8));
								if(pos->id==id)
								{
									Clear_screen();//先清屏
									mvprintw(COO_Y+2,COO_X+19,"%s",seek_prosper);//显示查找成功
									show_please();//在使用二级新增标题用于显示查找
									
									mvprintw(COO_Y+4,COO_X+23,"%s",pos->name);
									mvprintw(COO_Y+5,COO_X+22,"%d",pos->age);
									mvprintw(COO_Y+6,COO_X+21,"%d",pos->id);
									mvprintw(COO_Y+8,COO_X+15,"%s","Press any key to exit");//提示按下任意键退出
									attroff(COLOR_PAIR(8));
									getch();
									goto end_while;
								}	
								
							}
							Clear_screen();//先清屏
							attron(COLOR_PAIR(3));
							mvprintw(COO_Y+1,COO_X+1,"%s",_STU_FIND);//二级标头
							attroff(COLOR_PAIR(3));
							attron(A_BOLD);//开启加粗模式
							attron(COLOR_PAIR(4));
							mvprintw(COO_Y+5,COO_X+18,"%s",seek_fail);//显示查找失败
							mvprintw(COO_Y+8,COO_X+14,"%s","Press any key to exit");
							attroff(A_BOLD);//关闭加粗
							attroff(COLOR_PAIR(4));
							getch();
							goto end_while;
						}
						end_while:
						continue;
					case 3://修改
						show_amend();
						move(COO_Y+4,COO_X+23);					
						scanw("%d",&id);
						refresh();					
						pos=NULL;
						while(1)
						{
							list_for_each_entry(pos,&head->list,list)
							{
								attron(COLOR_PAIR(8));
								if(pos->id==id)
								{
									Clear_screen();//先清屏
									mvprintw(COO_Y+2,COO_X+19,"%s",seek_prosper);//显示查找成功
									show_please();//在使用二级新增标题用于显示查找
									move(COO_Y+4,COO_X+23);
											
									scanw("%s",name);
									show_please();
						
									move(COO_Y+5,COO_X+22);	
									scanw("%d",&age);
									show_please();
						
									move(COO_Y+6,COO_X+21);
									scanw("%d",&id);
									show_please();
									stpcpy(pos->name,name);
									pos->age;
									pos->id=id;
									mvprintw(COO_Y+7,COO_X+15,"%s",amend_fail);
									mvprintw(COO_Y+8,COO_X+15,"%s","Press any key to exit ");//提示按下任意键退出
									attroff(COLOR_PAIR(8));
									getch();
									goto end_amend;
								}	
								
							}
							Clear_screen();//先清屏
							attron(COLOR_PAIR(3));
							mvprintw(COO_Y+1,COO_X+1,"%s",_STU_FIND);//二级标头
							attroff(COLOR_PAIR(3));
							attron(A_BOLD);//开启加粗模式
							attron(COLOR_PAIR(4));
							mvprintw(COO_Y+5,COO_X+18,"%s",seek_fail);//显示查找失败
							mvprintw(COO_Y+8,COO_X+14,"%s","Press any key to exit!");
							attroff(A_BOLD);//关闭加粗
							attroff(COLOR_PAIR(4));
							getch();
							goto end_amend;
						}
						end_amend:
						continue;					
				}
				
			}
	}
}
//清屏界面函数
void Clear_screen()
{	
	attron(COLOR_PAIR(7));
	mvprintw(COO_Y+1,COO_X+1,"%s",STU_1);
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
};

//二级新增界面显示
void show_please()
{

	Clear_screen();
	
	attron(COLOR_PAIR(3));//欢迎字符
	mvprintw(COO_Y+1,COO_X+1,"%s",_STU_INCER);//二级标头
	attroff(COLOR_PAIR(3));
	
	attron(COLOR_PAIR(8));
	mvprintw(COO_Y+4,COO_X+10,"%s",_name);
	mvprintw(COO_Y+5,COO_X+10,"%s",_age);
	mvprintw(COO_Y+6,COO_X+10,"%s",_id);
	attroff(COLOR_PAIR(8));
}
//二级删除界面显示
void show_delete()
{

	Clear_screen();
	
	attron(COLOR_PAIR(3));
	mvprintw(COO_Y+1,COO_X+1,"%s",_STU_QUERY);//二级标头
	attroff(COLOR_PAIR(3));
	
	attron(COLOR_PAIR(8));
	//mvprintw(COO_Y+4,COO_X+10,"%s",delete_name);
	mvprintw(COO_Y+4,COO_X+10,"%s",delete_id);
	//mvprintw(COO_Y+6,COO_X+10,"%s",_id);
	attroff(COLOR_PAIR(8));
}

//二级查找界面显示
void show_seek()
{

	Clear_screen();
	
	attron(COLOR_PAIR(3));
	mvprintw(COO_Y+1,COO_X+1,"%s",_STU_FIND);//二级标头
	attroff(COLOR_PAIR(3));
	
	attron(COLOR_PAIR(8));
	//mvprintw(COO_Y+4,COO_X+10,"%s",seek_name);
	mvprintw(COO_Y+4,COO_X+10,"%s",seek_id);
	//mvprintw(COO_Y+6,COO_X+10,"%s",_id);
	attroff(COLOR_PAIR(8));
}
//二级修改界面显示
void show_amend()
{

	Clear_screen();
	
	attron(COLOR_PAIR(3));
	mvprintw(COO_Y+1,COO_X+1,"%s",_STU_MODIFY);//二级标头
	attroff(COLOR_PAIR(3));
	
	attron(COLOR_PAIR(8));
	//mvprintw(COO_Y+4,COO_X+10,"%s",amend_name);
	mvprintw(COO_Y+4,COO_X+10,"%s",amend_id);
	//mvprintw(COO_Y+6,COO_X+10,"%s",_id);
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

//显示操作函数
void show_stu()
{
	initscr();//初始化curses库
	start_color();//开启颜色索引
	init_pair(1, COLOR_BLACK , COLOR_BLACK);//设置颜色索引1,黑,背景黑--
	init_pair(2, COLOR_RED, COLOR_BLACK);//2,红,背景黑--
	init_pair(3, COLOR_WHITE,COLOR_GREEN);//3,白,背景绿--
	init_pair(4, COLOR_BLACK , COLOR_RED);//4,黑,背景红--警告语句
	init_pair(5, COLOR_BLUE  , COLOR_BLACK);//5,蓝,背景黑--
	init_pair(6, COLOR_MAGENTA  , COLOR_BLACK);//6,粉,背景黑--
	init_pair(7, COLOR_WHITE , COLOR_WHITE);//7,白,背景白--
	init_pair(8, COLOR_BLACK , COLOR_WHITE);//8,黑,背景白--
	
	color_profile();
	show_stu_char();
	show_stu_inte(4);
	
	key_show_inte();
	refresh();
}
	
int main()
{
	head=create_head();
	show_stu();
	//getch();                        //等待用户输入
    endwin();                       //结束curses库
}