#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void menu()//显示界面
{
	printf("******************************\n");
	printf("********1.play  0.eixt********\n");
	printf("******************************\n");
}



void game()
{
	char res =0;//状态变量
	char board[ROW][COL] = { 0 };

	//初始化函数
	IntBoard(board, ROW, COL);

	//打印棋盘
	DisplayBoard(board, ROW, COL);

	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		printf("\n");
		//判断电脑是否赢

		res=LsWin(board, ROW, COL);
		if (res != 'C')
		{
			break;
		}

		//电脑下棋
		ComputerMove(board, ROW, COL);
		//Sleep(500);//windows 
		//sleep(1)//linux 下单位是秒
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		printf("\n");
		//判断电脑是否赢

		res = LsWin(board, ROW, COL);
		if (res != 'C')
		{
			break;
		}
	}

	if (res == '*')
	{
		printf("恭喜您获得胜利！\n");
	}
	else if (res == '#')
	{
		printf("电脑赢！\n");
	}
	else
	{
		printf("平局！\n");
	}
}

void test()//游戏进行程序
{
	int input=0;
	srand((unsigned int)time(NULL));//获取当前时间作为时间戳.srand()-->初始化随机数发生器在标头 <stdlib.h> 定义使用rand()来获取随机值
	do
	{
		menu();//打印游戏界面
		scanf(" %d", & input);//获取用户选择
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("********   退出游戏   ********\n");
			break;
		default:
		;
		}

	} while (input);


}

int main()
{
	test();
	return 0;
}
