#define ROW 3
#define COL 3 //����ROW COL��ԭ����Ҫ�Ķ�row colʱ��������Ķ����ɣ�������Ҫ�Ķ���̫�� 

#include<stdio.h>

#include<stdlib.h>

#include<time.h>
//����
void Initboard(char board[ROW][COL], int row, int col);

void Displayboard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board[ROW][COL], int row,int col);

char Is_Winner(char board[ROW][COL], int row, int col);
//���ֽ����
//���ʤ�� - '*'
//����ʤ�� - '#'
//ƽ�� - 'D'//drawƽ��
//���� - 'C'