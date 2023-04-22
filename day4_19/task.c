#include <curses.h>
#include <stdlib.h>
#include <time.h>

#define COO_X 20			//棋盘原点坐标X
#define COO_Y 5				//棋盘原点坐标Y
#define ROW 10				//宽
#define COL 48				//长
#define KONG 0	//空
#define WALL 1	//墙
#define FOOD 2	//食物
#define HEAD 3	//蛇头
#define BODY 3	//蛇身

#define UP 72 //向上
#define DOWW 80 //向下
#define LEFT 75 //向左
#define RIGHT 77 //向右
#define SPACE 30 //暂停
#define ESC 27 //退出

int goal_x,goal_y;			//分数坐标
int goal_score=0;			//分数变量

char game_str[]="SNAKE  GAME";
char goal_str[]="Current score:";
char exit_str[]="Press 'Q' to exit!";
char begin_str[]="Press 'K' to begin!";

struct Snake{
	int len;//蛇身长度
	int x;	//蛇头横坐标
	int y;	//蛇头纵坐标
}snake_head;

struct body{
	int x;	//蛇身横坐标
	int y;	//蛇身纵坐标
}snake_body[ROW*COL];

int sign_satate[ROW][COL];  //用于标志每个区域的状态：空，墙，食物，蛇头，蛇身

void init_snake()//初始化蛇
{
	snake_head.len=2;
	snake_head.x=ROW/2;
	snake_head.y=COL/2;
	
	snake_body[0].x=ROW/2; 		 //蛇头坐标
	snake_body[0].y=COL/2-1;	 //蛇头坐标
	snake_body[1].x=ROW/2; 		 //蛇身坐标
	snake_body[1].y=COL/2-2;	 //蛇身坐标
	
	//将蛇头蛇身进行标记
	sign_satate[snake_head.x][snake_head.y]=HEAD;
	
	sign_satate[snake_body[0].x][snake_body[0].y]=BODY;
	sign_satate[snake_body[1].x][snake_body[1].y]=BODY;

}

int up,doww,leet,right;

int key()
{
	keypad(stdscr,TRUE);
	int key;
	while(1)
	{
		key = getch();
		switch(key)
		{
			case KEY_UP://按下上时
				up=1;
				break;
			case KEY_DOWN:
				doww=1;
				break;
			case KEY_LEFT:
				leet=1;
				break;
			case KEY_RIGHT:
				right=1;
				break;
				//if()
		}
	}
}
				
			
		

void Rand_food(int *i,int *j)//生成随机食物
{
	
	do
	{
		*i=rand()%ROW;
		*j=rand()%COL;
	}while(sign_satate[(*i)][(*j)]!=KONG);
	
	sign_satate[(*i)][(*j)]=FOOD;//标记为食物		
}

void print_snake(int flag)//显示蛇
{
	
	//打印蛇
	if(flag==1)
	{
		attron(COLOR_PAIR(3));
		mvaddch(COO_Y+snake_head.x,COO_X+snake_head.y,ACS_CKBOARD);//打印蛇头
		
		for(int i=0;i<snake_head.len;i++)
		{
			mvaddch(COO_Y+snake_body[i].x,COO_X+snake_body[i].y,ACS_CKBOARD);//打印蛇身
	
		}
		attroff(COLOR_PAIR(3));
		refresh();	
	}
	//覆盖蛇
	else
	{
		if(snake_body[snake_head.len-1].x!=0)
		{
			mvaddch(COO_Y+snake_body[snake_head.len-1].x,COO_X+snake_body[snake_head.len-1].y,' ');
		}
	}
}

void snake_move()//移动蛇
{
	print_snake(0);
	sign_satate[snake_body[snake_head.len-1].x][snake_body[snake_head.len-1].y]=KONG;//移动后将蛇尾计空
	sign_satate[snake_head.x][snake_head.y]=BODY;//蛇头变为蛇身
	
	snake_head.x=ROW/2-1;//每次移动一格,移动后检查是否有食物
	if(sign_satate[snake_head.x][snake_head.x]==FOOD)
	{
		snake_head.len += 1;
		int key();
		if(up==1)
		{
			snake_head.x=ROW/2;
			snake_head.y=COL/2;
		}
	}
	
	
}

void print_food()//打印食物
{
	int i,j;//食物的随机数坐标
	attron(COLOR_PAIR(4));
	//获取食物随机数
	Rand_food(&i,&j);
	//打印食物
	mvaddch(COO_Y+i+1,COO_X+j+1,'*');
	attroff(COLOR_PAIR(4));
}


void show_inter()
{
    initscr();          //初始化curses库
	clear();
	curs_set(0);		//不显示光标
    start_color();      //开启颜色索引
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);	//设置颜色索引1,黄色,背景黑--外框
	init_pair(2, COLOR_CYAN, COLOR_BLACK);		//设置颜色索引2,青色,背景黑--字体
	init_pair(3, COLOR_MAGENTA , COLOR_BLACK);	//设置颜色索引3,粉色,背景黑--蛇
	init_pair(4, COLOR_RED , COLOR_BLACK);		//设置颜色索引4,红色,背景黑--蛇

	//开启颜色索引1
	attron(COLOR_PAIR(1));
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
	
	attroff(COLOR_PAIR(1));			//关闭颜色索引1
	//attroff(A_BOLD);				//关闭加粗
	
	//提示游戏名称
	//开启颜色索引1
	attron(COLOR_PAIR(2));
	//开启加粗模式
	attron(A_BOLD);
	mvprintw(4,38,"%s",game_str);
	attroff(A_BOLD);				//关闭加粗
	
	mvprintw(7,71,"%s",goal_str);   //显示当前分数
	getyx(stdscr, goal_y,goal_x);	//获取当前分数冒号后的坐标
	mvprintw(goal_y,goal_x,"%d",goal_score);	//打印分数
	
	mvprintw(9,71,"%s",exit_str);		//退出字符
	mvprintw(10,71,"%s",begin_str);		//开始字符
	
	
	//--------------------打印食物--------------
	print_food();
	
	//--------------------打印蛇--------------
	init_snake();//初始化蛇
	print_snake(1);//打印蛇

	
	

	
	attroff(COLOR_PAIR(2));			//关闭颜色索引2
	
	
	refresh();						//刷新显示
	getch();                        //等待用户输入
	clear();
    endwin();                       //结束curses库
	

}

int main()
{	

	srand((unsigned)time(NULL));
    show_inter();

    return 0;
}
