#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu ()
{
	printf("*************************\n");
	printf("***** 1.play 0.exit *****\n");
	printf("*************************\n");
}

//��Ϸ�������㷨ʵ��
void game()
{
	char ret = 0;
	//���� - ����߳���������Ϣ
	char board [ROW][COL] = {0}; //ȫ���ո�
	//��ʼ��
	Initboard(board, ROW, COL);
	//��ӡ
	Displayboard(board, ROW, COL);
	//����
	while(1)
	{

	//���
	PlayerMove(board, ROW, COL);
	Displayboard(board, ROW, COL);
	//�ж�����Ƿ�ʤ��
	ret = Is_Winner(board, ROW, COL);
	if(ret != 'C') //������ʾ��������Ϊ��������������ִ��
	{
		break;
	}
	//����
	ComputerMove(board, ROW, COL);
	Displayboard(board, ROW, COL);
	//�жϵ����Ƿ�ʧ��
	ret = Is_Winner(board, ROW, COL);
	if(ret != 'C')
	{
		break;
	}
	}
	//�������������ݣ��жϽ����
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
	srand((unsigned int )time(NULL)); //�����������
	do
	{
	menu();
	printf("��ѡ��:>\n");
	scanf("%d", &choice);

	switch(choice)
	{
	case 1:
		game();
		break;
	case 0:
		printf("�˳�����\n");
		break;
	default:
		printf("�����������������\n");
		break;
	}
	}while(choice);

	return 0;
}
