#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu ()
{
	printf("*************************\n");
	printf("***** 1.play 0.exit *****\n");
	printf("*************************\n");
}

//游戏的整个算法实现
void game()
{
	char ret = 0;
	//数组 - 存放走出的棋盘信息
	char board [ROW][COL] = {0}; //全部空格
	//初始化
	Initboard(board, ROW, COL);
	//打印
	Displayboard(board, ROW, COL);
	//下棋
	while(1)
	{

	//玩家
	PlayerMove(board, ROW, COL);
	Displayboard(board, ROW, COL);
	//判断玩家是否胜利
	ret = Is_Winner(board, ROW, COL);
	if(ret != 'C') //不会显示继续，若为继续，则程序继续执行
	{
		break;
	}
	//电脑
	ComputerMove(board, ROW, COL);
	Displayboard(board, ROW, COL);
	//判断电脑是否失败
	ret = Is_Winner(board, ROW, COL);
	if(ret != 'C')
	{
		break;
	}
	}
	//下面根据输出内容，判断结果。
	 if(ret == '*')
	{
		printf("WINNER : player!\n");
	}
	else if(ret == '#')
	{
		printf("WINNER : computer!\n");
	}
	else
	{
		printf("dogfall!\n");
	}

}

int main()
{
	int choice = 0;
	srand((unsigned int )time(NULL)); //电脑随机下棋
	do
	{
	menu();
	printf("请选择:>\n");
	scanf("%d", &choice);

	switch(choice)
	{
	case 1:
		game();
		break;
	case 0:
		printf("退出程序\n");
		break;
	default:
		printf("输入错误，请重新输入\n");
		break;
	}
	}while(choice);

	return 0;
}
