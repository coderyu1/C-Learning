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
	//����ͨѶ¼����ϵ����Ϣ+ͨѶ¼����
	contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case ADD://��Ӽ���ϵ��
			Add(&con);
			break;
		case DEL://ɾ����ϵ��
			Del(&con);
			break;
		case MOD://�޸���ϵ����Ϣ
			Mod(&con);
			break;
		case SEARCH://������ϵ��
			Search(&con);
			break;
		case SORT://����ϵ������
			//Sort(&con);
			break;
		case DISPLAY://��ʾ��ϵ����Ϣ
			Display(&con);
			break; 
		case EXIT://�˳�
			SaveContact(&con);
			Destroy(&con);
			printf("�˳�");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}