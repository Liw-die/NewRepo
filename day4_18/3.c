#include <curses.h>
#include <stdio.h>

char week[7][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};

int year = 2023;
int month= 4;
int day  = 18;

int num[6][7];

//平年的每月日期数,从上一年的12月开始计算
int pear_month[13]={31,31,28,31,30,31,30,31,31,30,31,30,31};
//润年的每月日期数,从上一年的12月开始计算
int run_month[13]={31,31,29,31,30,31,30,31,31,30,31,30,31};


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




//显示日期----显示6行，7列的图像
void show(int pear,int week_day)
{
	//===============显示第0行========================
	int i=0;//表示行数
	int j=0;//表示列数
	int k=1;//表示几号,初始为1号
	
	//判断1号是否为周日
	if(week_day == 0)
	{
		attron(COLOR_PAIR(2));//开启颜色索引2
		//第一行全部显示上一月的日期
		for(j=0;j<7;j++)
		{
			if(pear)
				num[i][j] = pear_month[month-1]-7+1+j;
			else
				num[i][j] = run_month[month-1]-7+1+j;
			
			//显示数字
			mvprintw(4+i,2+5*j,"%d",num[i][j]);
		}
		attroff(COLOR_PAIR(2));//关闭颜色索引2
	}
	else
	{
		attron(COLOR_PAIR(2));//开启颜色索引2
		//先显示上一月的日期
		for(j=0;j<week_day;j++)
		{
			if(pear)
				num[i][j] = pear_month[month-1]-week_day+1+j;
			else
				num[i][j] = run_month[month-1]-week_day+1+j;
			
			//显示数字
			mvprintw(4+i,2+5*j,"%02d",num[i][j]);
		}
		attroff(COLOR_PAIR(2));//关闭颜色索引2
		
		attron(COLOR_PAIR(3));//开始打印当前月，开启颜色索引3
		//再显示当月而定日期
		for(j=week_day;j<7;j++)
		{
			num[i][j] = k;
			//显示数字
			mvprintw(4+i,2+5*j,"%02d",num[i][j]);
			//日期数+1
			k++;
		}
		attroff(COLOR_PAIR(3));//关闭颜色索引3
	}
	
	attron(COLOR_PAIR(3));//开始打印当前月，开启颜色索引3
	
	//显示剩下的行数,第1行~第6行
	for(i=1;i<6;i++)
		for(j=0;j<7;j++)
		{
			//如果是平年，并k已经跳月，再从1号开始打印
			if(pear && k > pear_month[month])
			{
				//准备打印下个月的时候，
				attroff(COLOR_PAIR(3));//关闭颜色索引3
				attron(COLOR_PAIR(2));//开启颜色索引2
				k=1;
			}
			else if(!pear && k > run_month[month])
			{
				//准备打印下个月的时候，
				attroff(COLOR_PAIR(3));//关闭颜色索引3
				attron(COLOR_PAIR(2));//开启颜色索引2
				k=1;
			}
			num[i][j] = k;
			mvprintw(4+i,2+5*j,"%02d",num[i][j]);
			
			k++;
		}
	attroff(COLOR_PAIR(2));	
}




int main()
{
	int flag;//判断平年或者闰年
	int week_day;//计算星期几
	
	//初始化curses库
	initscr();
	
	//开启颜色索引
	start_color();
	//设置索引的目标
	init_pair(1 ,COLOR_YELLOW ,COLOR_BLACK );//设置索引1： 文字黄色，背景黑色
	init_pair(2 ,COLOR_CYAN ,COLOR_BLACK );//设置索引2:文字青色，背景黑色
	init_pair(3 ,COLOR_GREEN ,COLOR_BLACK );//设置索引3：文字绿色，背景黑色
	
	//把光标移动到(0,0)的位置   ---- 坐标(行数,列数)
	move(0,0);
	//从左上角(0,0)的位置去绘制 40个 '-' 字符
	hline('-',40);
	
	//把光标移动到(1,0)的位置
	move(1,0);
	//从左上角(1,0)的位置去绘制 10个 '|' 字符
	vline('|',10);
	
	
	//---------------------显示星期几的表头--------------//
	//设置显示时候的属性
	//开启颜色索引1
	attron(COLOR_PAIR(1));
	//开启加粗模式
	attron(A_BOLD);
	
	//显示文字
	for(int i=0;i<7;i++)
		mvprintw(3,2+5*i,"%s",week[i]);
	
	//关闭颜色索引1
	attroff(COLOR_PAIR(1));
	//关闭加粗
	attroff(A_BOLD);
	
	//-----------显示年份和月份--------------
	mvprintw(1,20,"%d",year);
	mvprintw(1,24,"%s","/");
	mvprintw(1,25,"%02d",month);
	
	
	//计算日历----蔡勒公式
	// 如果当前月份的1号是周日，那么第一行全部显示上一个月的日期
	// 如果当前月份的1号不是周日，那么第一行先显示上一月的日期，再显示当前月份的日期
	week_day = calc_calander_weak(year,month,1);
	//mvprintw(8,0,"%d",week_day);
	
	//计算平年或闰年
	if( (year%4==0&&year%100!=0) || year%400==0 )
		flag = 1;//闰年
	else
		flag = 0;//平年
	
	//显示日期
	show(flag,week_day);
	
	//开启键盘
	keypad(stdscr,TRUE);
	int key;
	
	while(1)
	{
		key = getch();
		
		switch(key){
			case KEY_RIGHT:
				month +=1;
				if(month > 12)
				{
					year +=1;
					month=1;
				}
				break;
			case KEY_LEFT:
				month -=1;
				if(month < 1)
				{
					year -=1;
					month = 12;
				}
				break;
			case KEY_UP:
				year++;
				break;
			case KEY_DOWN:
				year--;
				break;
		}
		//重新计算year年的month月的1号是周几
		week_day = calc_calander_weak(year,month,1);
		
		//重新显示日期
		show(flag,week_day);
		
		//修改表头
		mvprintw(1,20,"%d",year);
		mvprintw(1,24,"%s","/");
		mvprintw(1,25,"%02d",month);
		
		//刷新界面
		refresh();
	
	}

	
	return 0;
}
