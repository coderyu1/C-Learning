#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//方法1（我的代码）
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
//	do//进入猜数字游戏
//	{   
//		menu();//打印菜单
//		printf("请选择：");
//		scanf("%d", &input);
// 
//		if (input == 1)//游戏的实现
//		{
//			int ret = rand() % 100 + 1;//1到100随机数的产生
//			printf("%d\n", ret);
//
//		    while (1)
//			{
//				printf("请猜数字：");
//				int guess = 0;
//				scanf("%d", &guess);
//				if (guess == ret)//猜对了，游戏结束
//				{
//						printf("恭喜你，猜对了\n");
//						break;
//				}
//				if (guess > ret)//猜错了，提示猜大还是猜小了，游戏继续
//				{
//						printf("猜大了\n");
//				}
//				if (guess < ret)
//				{
//						printf("猜小了\n");
//				}
//			}
//		}
//	    else if (input == 0)
//		{
//			printf("退出游戏\n");
//			break;
//		}
//		else
//		{
//			printf("选择错误，请重新选择\n");
//		}
//	} while (input);
//
//	return 0;
//}

//方法2（鹏哥的代码）
void menu()
{
	printf("******************************\n");
	printf("**********1.play**************\n");
	printf("**********0.exit**************\n");
	printf("******************************\n");
}

void game()//游戏的实现
{
	int ret = rand() % 100 + 1;//1到100随机数的产生
	
	while (1)
	{
		printf("猜数字：");
		int guess = 0;
		scanf("%d", &guess);
		if (guess == ret)
		{
			printf("恭喜你，猜对了");
			break;
		}
		else if (guess > ret)
		{
			printf("猜大了，请继续\n");
		}
		else
		{
			printf("猜小了\n");
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
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，重新选择");
			break;
		}
	} while (input);
	return 0;
}