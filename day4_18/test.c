#include <curses.h>
#include <signal.h>
char week[7][4]={{"SUN"},{"MON"},{"TUE"},{"WED"},{"THU"},{"FRI"},{"SAT"}};//星期表头

int year = 2023;
int month= 4;
int day  = 18;

int num[6][7];//显示数组
//平年的每月日期数,从上一年的12月开始计算
int pear_month[13] = {31,31,28,31,30,31,30,30,31,30,31,30,31};
//润年的每月日期数,从上一年的12月开始计算
int run_month[13] = {31,31,29,31,30,31,30,30,31,30,31,30,31};

//int ret_week(int);

//计算当前的 year年和 month月的dd号是星期几
int calc_calander_weak(int yy,int mm,int dd)
{
	int w,c,y,m,d;
	
	c = yy/100;//世纪数
	y = yy%100;//年份的末2位
	
	//蔡勒公式中，月份是 3~14
	if(mm <=2)
		m = mm+12;
	else
		m = mm;
	
	d = dd;
	
	w = y+(y/4)+(c/4)-2*c+(26*(m+1)/10)+d-1;
	
	return w%7;
}


void show(int pear,int week_day)
{
	int i=0;//行
	int j=0;//列
	int k=1;//日号
	
	if(0==week_day)//判断该月1是否是周日
	{
		attron(COLOR_PAIR(3));//打开颜色索引3
		for(int j=0;j<7;j++)
		{
			if(pear)//闰年
				num[i][j]=pear_month[month-1]-7+1+j;
			else
				num[i][j]=run_month[month-1]-7+1+j;
			
			mvprintw(3, 6+j*4,"%02d",num[i][j]);
		}
		attroff(COLOR_PAIR(3));	
		
	}
	
	
	else
	{
		attron(COLOR_PAIR(3));
		for(int j=0;j<7;j++)
		{
			if(pear)//闰年
				num[i][j]=pear_month[month-1]-week_day+1+j;
			else
				num[i][j]=run_month[month-1]-week_day+1+j;
			mvprintw(3+i, 6+j*4,"%02d",num[i][j]);
		}
		attroff(COLOR_PAIR(3));	
		
		attron(COLOR_PAIR(4));
		for(j=week_day;j<7;j++)
		{
			num[i][j] = k;
			//显示数字
			mvprintw(3+i,6+j*4,"%02d",num[i][j]);
			//日期数+1
			k++;
		}
		attroff(COLOR_PAIR(4));//关闭颜色索引4
		
	}
	
	attron(COLOR_PAIR(4));
	for(i=1;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			if(pear&&k>pear_month[month])
			{
				attroff(COLOR_PAIR(4));
				attron(COLOR_PAIR(3));
				k=1;
			}
			else if(!pear&&k>pear_month[month])
			{
				attroff(COLOR_PAIR(4));
				attron(COLOR_PAIR(3));
				k=1;
			}
			num[i][j]=k;
			mvprintw(3+i,6+j*4,"%02d",num[i][j]);
			
			k++;
		}
	}
	attroff(COLOR_PAIR(3));		
	
}

int main()
{
	int flag;//1闰年 0 平年
	int week_day;//计算星期几
	
	//计算平年或闰年
	if( (year%4==0&&year%100!=0) || year%400==0 )
		flag = 1;//闰年
	else
		flag = 0;//平年
	week_day = calc_calander_weak(year,month,1);
	
	
	initscr();
	start_color();//开启颜色配置
	
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);//设置颜色索引1,黄,黑
	init_pair(2, COLOR_CYAN , COLOR_BLACK);//设置颜色索引2,青色,黑
	init_pair(3, COLOR_GREEN  , COLOR_BLACK);//设置颜色索引3,绿色,黑
	init_pair(4, COLOR_MAGENTA   , COLOR_BLACK);//设置颜色索引3,粉色,黑
	
	move(0, 0);
	hline('-', 40);

	move(1, 0);
	vline('|', 10);

	move(11, 0);
	hline('-', 40);

	move(1, 39);
	vline('|', 10);
	
	//显示星期表头
	attron(COLOR_PAIR(1));//开启颜色索引1
	attron(A_BOLD);//开启加粗
	for(int i=0;i<7;i++)//打印星期表头
	{
		mvprintw(2, 6+i*4,"%s",week[i]);
	}
	attroff(COLOR_PAIR(1));//关闭颜色索引1
	attroff(A_BOLD);//关闭加粗
	
	//显示年/月
	attron(COLOR_PAIR(2));
	mvprintw(1, 16,"%d",year);
	mvprintw(1, 20,"%s","/");
	mvprintw(1, 21,"%02d",month);
	attroff(COLOR_PAIR(2));
	
	//显示日期
	show(flag,week_day);
	//开启键盘
	keypad(stdscr,TRUE);
	noecho();
	raw();
	int key;
	int q = 1;
	while(q)
	{
		key = getch();
		
		switch(key)
		{
			case KEY_UP:
				year++;
				break;
			case KEY_DOWN:
				year--;
				break;
			case KEY_RIGHT:
				month += 1;
				if(month>12)
				{
					year += 1;
					month = 1;
				}
				break;
			case KEY_LEFT:
				month -= 1;
				if(month<1)
				{
					year -= 1;
					month = 12;
				}
				break;
			case 'q':
				clear();
				q = 0;
				break;
		}
		
		week_day = calc_calander_weak(year,month,1);
		show(flag,week_day);
		
		mvprintw(1, 16,"%d",year);
		mvprintw(1, 20,"%s","/");
		mvprintw(1, 21,"%02d",month);
		
		refresh();
	}
	
	
	refresh();

	//while(1);
	return 0;

}

