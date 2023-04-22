#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void IntBoard(char board[ROW][COL], int row, int col)//初始化函数,将二位数组的每一个元素赋值空格
{
	int i = 0, j = 0;
	for (i; i < row; i++)
	{
		for (j=0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//   |   |   
//---|---|---
//   |   |
//---|---|---
//   |   |
//void DisplayBoard(char board[ROW][COL], int row, int col)//显示棋盘
//{
//	int i = 0;
//	for (i; i < row; i++)
//	{
//		//打印这一行的数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		//打印分隔符
//		if (i < row - 1)
//		{
//			printf("---|---|---\n");
//		}
//
//	}
//
//}

//显示棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i; i < row; i++)//
	{

		int j;
		for (j=0; j < col; j++)//打印第一行
		{
			printf(" %c ", board[i][j]);//   |   |   
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");//在打印完成后换行

		if (i < row - 1)
		{
			for (j=0; j < col; j++)//打印---|---|---
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");//在打印完成后换行
		}

	}

}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("玩家下棋：\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断用户的输入范围
		{
			if (board[x - 1][y - 1] == ' ')//判断输入的坐标是否为空（空格）
			{
				board[x - 1][y - 1] = '*';
				break;//下完后跳出当前循环
			}
			else
			{
				printf("该坐标被占用！\n");
			}
		}
		else
		{
			printf("非法坐标，请重新输入！\n");
		}
	}
}

//机器下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("机器下棋->\n");

	while (1)
	{
		x = rand() % row;//产生0-2之间的值
		y = rand() % col;//产生0-2之间的值
		if (board[x][y] == ' ')//判断输入的坐标是否为空（空格）
		{
			board[x][y] = '#';
			break;
		}
	}
}


//判断棋盘状态
//1表示满了，0表示没满
int IsFuli(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			if (board[x][y] == ' ')//找到空格
			{
				return 0;
			}
		}
	}
	return 1;//没有找到空格返回1

}

char LsWin(char board[ROW][COL], int row, int col)//判断三子棋输赢
{
	int i = 0;
	for (i = 0; i < row; i++)//判断横三行
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')//三个元素相等，且其中的元素不为空格
		{
			return board[i][1];//则输出里面的元素
		}
	}

	for (i = 0; i < col; i++)//判断竖三列
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')//三个元素相等，且其中的元素不为空格
		{
			return board[1][i];//则输出里面的元素
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')//判断一个对角线相等，且其中的元素不为空格
	{
		return board[1][1];//则输出里面的元素
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')//判断一个对角线相等，且其中的元素不为空格
	{
		return board[1][1];//则输出里面的元素
	}

	//判断平局
	if (1 == IsFuli(board, ROW, COL))
	{
		return 'Q';
	}
	else
		return 'C';
}
