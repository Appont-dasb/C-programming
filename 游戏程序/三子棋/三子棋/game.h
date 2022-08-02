#define ROW 3
#define COL 3 //定义ROW COL的原因：如要改动row col时，在这里改动即可，否则需要改动的太多 

#include<stdio.h>

#include<stdlib.h>

#include<time.h>
//声明
void Initboard(char board[ROW][COL], int row, int col);

void Displayboard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board[ROW][COL], int row,int col);

char Is_Winner(char board[ROW][COL], int row, int col);
//四种结果：
//玩家胜利 - '*'
//电脑胜利 - '#'
//平局 - 'D'//draw平局
//继续 - 'C'