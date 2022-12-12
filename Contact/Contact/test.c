#include "contact.h"

void menu()
{
	printf("******************************\n");
	printf("******  1.add  2.del  ********\n");
	printf("******  3.mod  4.search  *****\n");
	printf("******  5.sort 6.display *****\n");
	printf("***********  0.exit  *********\n");
}

int main()
{
	int input = 0;
	//创建通讯录：联系人信息+通讯录容量
	contact con;
	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD://添加加联系人
			Add(&con);
			break;
		case DEL://删除联系人
			Del(&con);
			break;
		case MOD://修改联系人信息
			Mod(&con);
			break;
		case SEARCH://查找联系人
			Search(&con);
			break;
		case SORT://将联系人排序
			//Sort(&con);
			break;
		case DISPLAY://显示联系人信息
			Display(&con);
			break; 
		case EXIT://退出
			SaveContact(&con);
			Destroy(&con);
			printf("退出");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);

	return 0;
}