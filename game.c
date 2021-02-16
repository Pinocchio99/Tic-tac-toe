#include"game.h"

void displayboard(char arr[COW][COL],int col,int cow)
{
	for (int i = 0; i < col; i++)//��ÿ������Ϊһ�飬�з����ѭ��
	{
		for (int j = 0; j < cow; j++)//�Կո��е��е�������Ϊһ�飬�з��ȵ�ѭ��
		{
			printf(" %c ",arr[i][j]);
			if (j < cow- 1)
				printf("|");
		}
		printf("\n");
		if (i < col - 1)
		{
			for (int k = 0; k < cow; k++)//�Լ���е��е�������Ϊһ�飬�з��ȵ�ѭ��
			{
				printf("---");
				if (k < cow - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
int player(char arr[COL][COW])
{
	int x, y;
	printf("��������壺 ����������x,y��");
	do
	{
		scanf("%d%d", &x, &y);
		if (1 <= x && 1 <= y && x <= COW && y <= COL)
		{
			if (arr[x-1][y-1] != ' ')
				printf("�˸��ѱ����ӣ�");
			else
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
		}
		else
			printf("���뷶Χ�����ϣ��������룺");
	} while (1);
}
void ComptureMove(char arr[COL][COW],int col,int cow)
{
	printf("�������壺\n");
	int x, y;
	do
	{
		x = rand() % col;//ȡģ�õ�����0 1 2�����������1 2 3��ͬ
		y = rand() % cow;
		if (arr[x][y] != ' ')
			;
		else
		{
			arr[x][y] = '#';
			break;
		}
	} while (1);
}
//'*'
//'#'
//Q ƽ��
//C ����
int IsFull(char arr[COL][COW], int col, int cow)
{
	for(int i=0;i<col;i++)
		for (int j = 0; j < cow; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
				break;
			}
		}
	return 1;
}
char IsWin(char arr[COL][COW],int col,int cow)
{
	for (int i = 0; i < COL; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] != ' ')
			return arr[i][0];
	}
	for (int i = 0; i < COW; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[0][i] != ' ')
			return arr[0][i];
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
		return arr[1][1];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
		return arr[1][1];
	if(IsFull(arr,col,cow))
		return 'Q';
		return 'C';
}

void game(char arr[COL][COW],int col,int cow)
{
	char ret;
	//��ӡ��Ϸ���
	//   |   |   
	//---|---|---
	//   |   | 
	//---|---|---
	//   |   |  
	displayboard(arr,col,cow);
	//�˻�����
	do
	{
		//�������
		player(arr);
		//չʾ����������
		displayboard(arr, col, cow);
		//�ж�����Ƿ�Ӯ��
		ret=IsWin(arr,col,cow);
		if (ret == '*')//�˴����Թ��Ϊret!='C',֮����Һ͵��Ե��жϿ��Թ��Ϊһ�������
		{
			printf("���Ӯ");
			break;
		}
		if (ret == 'Q')
		{
			printf("ƽ��");
			break;
		}

		//��������
		srand((unsigned)time(NULL));
		ComptureMove(arr,col,cow);
		//չʾ�����������
		displayboard(arr, col, cow);
		ret = IsWin(arr, col, cow);
		if (ret == '#')
		{
			printf("����Ӯ");
			break;
		}
		if (ret == 'Q')
		{
			printf("ƽ��");
			break;
		}
	} while (1);
}