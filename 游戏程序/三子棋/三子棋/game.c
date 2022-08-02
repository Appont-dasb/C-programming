#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//初始化定义
void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for(i=0 ; i<row ; i++)
	{
		for(j=0 ; j<col; j++)
		{
			board[i][j] = ' ';
		}
	}

}

//打印定义
//void Displayboard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i=0; i< row; i++)
//	{
//	//1.打印一行数据
//	printf(" %c | %c |%c \n",board[i][0],board[i][1],board[i][2]);
//	//2.打印分割行
//	if(i < row -1)
//	printf("---|---|---\n");
//	}
//}

void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i=0; i< row; i++)
	{
		//1.打印一行数据
		for(j=0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if(j < col-1)
			{
				printf("|");
			}
	    }
		printf("\n");

		//2.打印分割行
		if(i < row-1)
		{
			for(j = 0; j < col; j++)
			{
				printf("---");
				if(j < col-1)
				printf("|");
			}
			printf("\n");
		}
	}
}


void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while(1)
	{
		printf("请输入要下的坐标:>");
		scanf("%d%d",&x, &y);
		//判断是否合法
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if(board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break; //break不能忘！
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
}


void ComputerMove(char board[ROW][COL], int row,int col)
{
	
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while(1)
	{
	x = rand() % row;
	y = rand() % col;
	if(board[x][y] == ' ')
	{
		board[x][y] = '#';
		break;
	}
	}
}


//返回1棋盘满了，返回0棋盘没满
int Is_Full(char board[ROW][COL], int row, int col)
{
	int i = 0 ;
    int j = 0 ;
	for(i = 0; i <row; i++)
	{
		for(j = 0; j <col; j++)
		{
			if(board[i][j] == ' ')
				return 0; //没满输出0
		}
	}
	return 1;//满了输出1
}

char Is_Winner(char board[ROW][COL], int row, int col)
{
	int i = 0 ;
	//横行
	for(i = 0; i< row; i++)
	{
		if(board[i][0] == board[i][1]&& board[i][1] == board[i][2]&&board[i][1] != ' ') //三个连续相等，但不是空格
		{
			return board[i][1]; //return 后不是一个字符，这适用于玩家胜利和电脑胜利两种情况
		}
	}

	//竖行
	for(i = 0; i< col; i++)
	{
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//对角线
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];

	//判断是否平局
	if(1 == Is_Full(board,row,col))
		return 'D';
	//否则继续
	return 'C';
}
