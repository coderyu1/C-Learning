#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//����1���ҵĴ��룩
//void menu()
//{
//	printf("******************************\n");
//	printf("**********1.paly**************\n");
//	printf("**********0.exit**************\n");
//	printf("******************************\n");
//}
//int main()
//{   
//    int input = 0;
//	srand((unsigned int)time(NULL));//
//	
//	do//�����������Ϸ
//	{   
//		menu();//��ӡ�˵�
//		printf("��ѡ��");
//		scanf("%d", &input);
// 
//		if (input == 1)//��Ϸ��ʵ��
//		{
//			int ret = rand() % 100 + 1;//1��100������Ĳ���
//			printf("%d\n", ret);
//
//		    while (1)
//			{
//				printf("������֣�");
//				int guess = 0;
//				scanf("%d", &guess);
//				if (guess == ret)//�¶��ˣ���Ϸ����
//				{
//						printf("��ϲ�㣬�¶���\n");
//						break;
//				}
//				if (guess > ret)//�´��ˣ���ʾ�´��ǲ�С�ˣ���Ϸ����
//				{
//						printf("�´���\n");
//				}
//				if (guess < ret)
//				{
//						printf("��С��\n");
//				}
//			}
//		}
//	    else if (input == 0)
//		{
//			printf("�˳���Ϸ\n");
//			break;
//		}
//		else
//		{
//			printf("ѡ�����������ѡ��\n");
//		}
//	} while (input);
//
//	return 0;
//}

//����2������Ĵ��룩
void menu()
{
	printf("******************************\n");
	printf("**********1.play**************\n");
	printf("**********0.exit**************\n");
	printf("******************************\n");
}

void game()//��Ϸ��ʵ��
{
	int ret = rand() % 100 + 1;//1��100������Ĳ���
	
	while (1)
	{
		printf("�����֣�");
		int guess = 0;
		scanf("%d", &guess);
		if (guess == ret)
		{
			printf("��ϲ�㣬�¶���");
			break;
		}
		else if (guess > ret)
		{
			printf("�´��ˣ������\n");
		}
		else
		{
			printf("��С��\n");
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{

		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ���������ѡ��");
			break;
		}
	} while (input);
	return 0;
}