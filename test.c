#include"game.h"

//��ʼ������
void initial(char arr[COL][COW], int col, int cow)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < cow; j++)
		{
			arr[i][j] = ' ';
		}
	}
	return 0;
}
void meun()
{
	printf("***********************\n");
	printf("***** play:1 no:0 *****\n");
	printf("***********************\n");
	return 0;
}
int makesure()
{
	int ret;
	scanf("%d", &ret);
	if (ret == 1)
		return 1;
	else
		if (ret == 0)
			return 0;
		else
		{
			printf("����������������룺");
			return 2;
		}
}


int main()
{
	//�������飬���ڼ�¼���
	char arr[COL][COW];
	initial(arr,COL,COW);
	//��ʾ�˵�,����ѡ��
	meun();
	//�Ƿ������Ϸ,�����������Ĺ�ϵ����Ҫ�����ظ�ȷ��
	do
	{
		int ret;
		ret=makesure();
		if (ret == 1)
		{
			game(arr,COL,COW);
			break;
		}
		else
		{
			if (ret == 0)
				break;
		} 
	} while (1);
	return 0;
}