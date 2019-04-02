#include "game.h"
void printboard(char board[ROW][COL], int row, int col)
{
	int i,j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col-1;j++)
			printf(" %c |", board[i][j]); 
		    printf(" %c \n",board[i][j]);
		/*printf(" %c | %c | %c  \n", board[i][0], board[i][1], board[i][2]);*/
		for (j = 0; j < col; j++)
		{
			if (j < row - 1)
				printf("---|");
			if (j == row - 1)
				printf("---");
		}
		printf("\n");
	}
}
void initboard(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', row * col * sizeof(board[0][0]));
}
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：\n");
	while (1)
	{
		printf("请输入坐标: ");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col && board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = 'X';
			break;
		}
		else
			printf("坐标不合法，请重新输入\n");
	}
}
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}
int isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char checkwin(char board[ROW][COL], int row, int col)
{
	int i = 0; 
	for (i = 0; i < row; i++)
	{ 
		for(int j=0;j<col-1;j++)
		{
			if (board[i][j]!=board[i][j+1])
				break;
			if(j==col-2)
				return board[i][j];
		}
	}
	for (int j = 0; j < col ; j++)
	{
		for (int i = 0; i < row - 1; i++)
		{
			if (board[i][j] != board[i + 1][j])
				break;
			if (i== col - 2)
				return board[i][j];
		}
		
	}
	/*for (i = 0; i < row; i++) 
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];
	}
	for (i = 0; i < col; i++) 
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}*/
	for (int i = 0; i < col - 1; i++)//对角线
	{
		if (board[i][i] != board[i+1][i+1])
			break;
		if (i == col - 2)
			return board[i][i];
	}
	for (int i = 0; i < col - 1; i++)
	{
		if (board[i][col-i-1] != board[i+1][col-(i+1)-1])
			break;
		if (i == col - 2)
			return board[i][col-i-1];
	}
	//if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
	//	return board[0][0];
	/*if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[1][1];*/
	if (isfull(board, ROW, COL))
		return 'Q';
	else
		return ' ';
}