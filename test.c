#include "game.h"
void game()
{
	char ret = 0;
	char board[ROW][COL] = { '0' };
	initboard(board, ROW, COL);
	printboard(board, ROW, COL);
	while (1)
	{
		playermove(board, ROW, COL);
		printboard(board, ROW, COL);
		ret = checkwin(board, ROW, COL);
		if (ret == 'X')
		{
			printf("��ϲ��Ӯ�ˣ�\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("ƽ��\n");
			break;
		}
		computermove(board, ROW, COL);
		printboard(board, ROW, COL);
		ret = checkwin(board, ROW, COL);
		if (ret == '0')
		{
			printf("����Ӯ��\n");
			break;
		}
	}
}


void menu()
{
	printf("--------------------��ӭ������������Ϸ--------------------\n");
	printf(" *****************************************\n");
	printf(" ** 1.play 0.exit **\n");
	printf(" *****************************************\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)(time(NULL)));
	do
	{
		menu();
		printf("���������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�������������ѡ��\n");
		}
	} while (input);
	system("pause\n");
	return 0;
}