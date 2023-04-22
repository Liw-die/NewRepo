#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3  //三子棋的行
#define COL 3  //三子棋的列

#include <stdio.h>
#include <stdlib.h>//srand()的头文件
#include <time.h>//time()的头文件
//#include <Windows.h>//Sleep(1000)的头文件 单位是毫秒-->windows
//#include <unistd.h>////sleep(1)的头文件 单位是毫秒-->linux

void IntBoard(char board[ROW][COL], int row, int col);//初始化函数,将二位数组的每一个元素赋值空格
void DisplayBoard(char board[ROW][COL], int row, int col);//显示棋盘
void PlayerMove(char board[ROW][COL], int row, int col);//玩家下棋
void ComputerMove(char board[ROW][COL], int row, int col);//机器下棋

//判断对弈情况
//玩家赢"*"
//电脑赢"#"
//平局"Q"
//继续"C"
char LsWin(char board[ROW][COL], int row, int col);//判断三子棋输赢
int IsFuli(char board[ROW][COL], int row, int col);//判断棋盘状态

