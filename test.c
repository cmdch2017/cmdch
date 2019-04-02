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
			printf("恭喜你赢了！\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
			break;
		}
		computermove(board, ROW, COL);
		printboard(board, ROW, COL);
		ret = checkwin(board, ROW, COL);
		if (ret == '0')
		{
			printf("电脑赢！\n");
			break;
		}
	}
}


void menu()
{
	printf("--------------------欢迎来到三子棋游戏--------------------\n");
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
		printf("请输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新选择！\n");
		}
	} while (input);
	system("pause\n");
	return 0;
}