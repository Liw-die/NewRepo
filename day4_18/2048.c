#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int board[4][4]={0};
int empty;
int old_x,old_y;

void darw_one(int x,int y);
void draw_grid(void);
void init(void);
void paly(void);
int cnt_one(int x,int y);
void cnt_value(int* new_x,int* new_y);
int game_over(void);

void draw_grid(void)
{
	int m,n,x,y;
	//initscr();
	clear();
	
	for(m = 0;m < 9;m += 2)
	{
		for(n=0;n<21;n++)
		{
			move(m,n);
			addch('-');
			refresh();//刷新屏幕
		}
	}
	
	for(n = 0;n < 22;n += 5)
	{
		for(m=1;m<8;m++)
		{
			move(m,n);
			addch('|');
			refresh();//刷新屏幕
		}
	}
	
	for(x = 0;x < 4;x++)
	{
		for(y=0;n<4;y++)
		{
			darw_one(x,y);
		}
	}
	
}

void darw_one(int x,int y)
{
	int i,k,j,m=0;
	char c[5]={0x00};
	i=board[x][y];
	while(i>0)
	{
		j=i%10;
		c[m++]=j+'0';
		i=i/10;
	}
	m=0;
	k=(y+1)*5-1;
	while(c[m] != 0x00)
	{
		move(2*x+1,k);
		addch(c[m++]);
		k--;
	}

}

void init(void)//初始化函数
{
	int x,y;
	initscr();//开启curses
	cbreak();//
	noecho();//控制在键盘上输入时不显示字元
	curs_set(0);//设置光标不可见
	
	empty = 15;
	srand(time(0));
	
	x=rand()%4;//0 1 2 3 4
	y=rand()%4;//0 1 2 3 4
	
	board[x][y]=2;
	draw_grid();
		
}


void paly(void)
{
	int x,y,i,new_x,new_y,temp;//x->行，y->列，new_x,new_y新出现的数字坐标
	int old_empty,move;
	
	while(1)
	{
		move =0;
		old_empty = empty;
		switch(getch())
		{
			case 'a':
			case 68:
				for(x=0;x<4;x++)
				{
					for(y=0;y<4;)
					{
						if(board[x][y]==0)
						{
							y++;
							continue;
						}
						else
						{
							for(i=y+1;i<4;i++)
							{
								if(board[x][i] == 0)
									continue;
								else
								{
									if(board[x][y]==board[x][i])
									{
										board[x][y]+=board[x][i];
										board[x][i]=0;
										empty++;
									break;
									}
									else
										break;
								}
							}
							y = i;
						}
					}
				}
				for(x=0;x<4;x++)
				{
					for(y=0;y<4;y++)
					{
						if(board[x][y]==0)
							continue;
						else
							for(i=y;(i>0)&&(board[x][i-1]==0);i--)
							{
								board[x][i-1]=board[x][i];
								board[x][i]=0;
								move = 1;
							}
					}
				}
				break;
			case 'd':
			case 67:
					for(x=0;x<4;x++)
				{
					for(y=3;y>=0;)
					{
						if(board[x][y]==0)
						{
							y--;
							continue;
						}
						else
						{
							for(i=y-1;i>=0;i--)
							{
								if(board[x][i] == 0)
									continue;
								else
								{
									if(board[x][y]==board[x][i])
									{
										board[x][y]+=board[x][i];
										board[x][i]=0;
										empty++;
									break;
									}
									else
										break;
								}
							}
							y = i;
						}
					}
				}
				for(x=0;x<4;x++)
				{
					for(y=3;y>=0;y--)
					{
						if(board[x][y]==0)
							continue;
						else
							for(i=y;(i<3)&&(board[x][i+1]==0);i++)
							{
								board[x][i+1]=board[x][i];
								board[x][i]=0;
								move = 1;
							}
					}
				}
				break;
			case 'w':
			case 65:
				for(y=0;y<4;y++)
				{
					for(x=0;x<4;)
					{
						if(board[x][y]==0)
						{
							x++;
							continue;
						}
						else
						{
							for(i=x+1;i<4;i--)
							{
								if(board[i][y] == 0)
									continue;
								else
								{
									if(board[x][y]==board[i][y])
									{
										board[x][y]+=board[i][y];
										board[i][y]=0;
										empty++;
									break;
									}
									else
										break;
								}
							}
							x = i;
						}
					}
				}
				for(y=0;y<4;y++)
				{
					for(x=0;x<4;x++)
					{
						if(board[x][y]==0)
							continue;
						else
							for(i=x;(i>0)&&(board[i-1][y]==0);i--)
							{
								board[i-1][y]=board[i][y];
								board[i][y]=0;
								move = 1;
							}
					}
				}
				break;
			case 's':
			case 66:
				for(y=0;y<4;y++)
				{
					for(x=3;x>=0;)
					{
						if(board[x][y]==0)
						{
							x--;
							continue;
						}
						else
						{
							for(i=x-1;i>=0;i--)
							{
								if(board[i][y] == 0)
									continue;
								else
								{
									if(board[x][y]==board[i][y])
									{
										board[x][y]+=board[i][y];
										board[i][y]=0;
										empty++;
									break;
									}
									else
										break;
								}
							}
							x = i;
						}
					}
				}
				for(y=0;y<4;y++)
				{
					for(x=3;x>=0;x--)
					{
						if(board[x][y]==0)
							continue;
						else
							for(i=x;(i<3)&&(board[i+1][y]==0);i++)
							{
								board[i+1][y]=board[i][y];
								board[i][y]=0;
								move = 1;
							}
					}
				}
				break;
			case 'Q':
			case 'q':
				game_over();
				break;
			default:
				continue;
				break;
		}
		if(empty<=0)
			game_over();
		if((empty != old_empty) || (move == 1))
		{
			do{
				new_x = rand() % 4;
				new_y = rand() % 4;
			}
			while(board[new_x][new_y] != 0);
			
			cnt_value(&new_x,&new_y);
			
			do{
				temp = rand() %4;
			}
			while(temp == 0||temp == 2);
			board[new_x][new_y] = temp+1;
			empty--;
		}
		draw_grid();
	}
}

int cnt_one(int x,int y)
{
	int value = 0;
	if(x - 1 >=0)
		board[x-1][y]?0:value++;
	if(x + 1 <4)
		board[x+1][y]?0:value++;
	if(y - 1 >=0)
		board[x][y-1]?0:value++;
	if(y + 1 < 4)
		board[x][y+1]?0:value++;
	
	if(x - 1 >=0 && y - 1 >= 0)
		board[x-1][y-1]?0:value++;
	if(x - 1 >=0 && y + 1 <4)
		board[x-1][y+1]?0:value++;
	if(x + 1 <4 && y - 1 >= 0)
		board[x+1][y-1]?0:value++;
	if(x + 1 <4 && y + 1 < 4)
		board[x+1][y+1]?0:value++;
	return value;
}

void cnt_value(int* new_x,int* new_y)
{
	int max_x,max_y,x,y,value;
	int max = 0;
	max = cnt_one(*new_x,*new_y);
	for(x = 0;x < 4;x++)
	{
		for(y = 0;y<4;y++)
		{
			if(!board[x][y])
			{
				value = cnt_one(x,y);
				if(value > max && old_x != x && old_y !=y)
				{
					*new_x = x;
					*new_y = y;
					old_x = x;
					old_y = y;
				}
			}
		}
	}
}

int game_over(void)
{
	move(10,5);
	addstr("game over!");
	refresh();
	sleep(3);
	endwin();
	exit(0);
}

	
int main()
{
	init();
	paly();
	endwin();
	
	return 0;
	
	
}