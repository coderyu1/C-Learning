#include "contact.h"

//void InitContact(contact* con)//��ʼ��ͨѶ¼----��̬��
//{
//	PeoInfor data[100] = { 0 };
//	con->sz = 0;
//	con->capacity = CAPACITY_MAX;
//}

//void InitContact(contact* con)//��ʼ��ͨѶ¼----��̬��
//{
//	PeoInfor* data = (struct PeoInfor*)malloc(3 * sizeof(struct PeoInfor));//����д�����ڵ���void Add(contact * con)���·���Ȩ�޳�ͻ����
//	con->sz = 0;                                                           //ԭ�����ڣ������data�൱�����¿��ٵģ������ڽṹ��con
//	con->capacity = DEFAULT_SZ;                                            //���������ú���ʱ���ְ����ﶨ���data����Ϊ�ṹ��con�ĳ�Ա
//}                                                                        //ʵ�ʵ�data��û�еõ���ʼ���Ͷ�̬�����ڴ�

//void InitContact(contact* con)//��ʼ��ͨѶ¼----��̬��
//{
//	assert(con);
//	con->sz = 0;
//	con->data = (struct PeoInfor*)calloc(DEFAULT_SZ, sizeof(struct PeoInfor));
//	if (con->data == NULL)
//	{
//		printf("%s", strerror(errno));
//		return;
//	}
//	con->capacity = DEFAULT_SZ;
//}

void CheckCapacity(contact* con)//��̬����ļ������ж��Ƿ�����
{
	assert(con);
	if (con->sz == con->capacity)
	{
		PeoInfor* p = (PeoInfor*)realloc(con->data, (con->capacity + 2) * sizeof(PeoInfor));
		if (p == NULL)
		{
			printf("����ʧ��\n");
			return;
		}
		con->data = p;
		(con->capacity) += 2;
		printf("���ݳɹ�\n");
	}
}

void LoadContact(contact* con)//����ͨѶ¼
{
	FILE* pf = fopen("contact.date", "rb");
	if (pf == NULL)
	{
		perror("fopen");
	}

	PeoInfor tmp = { 0 };
	while (fread(&tmp, sizeof(tmp), 1, pf))
	{
		CheckCapacity(con);
		con->data[con->sz] = tmp;
		con->sz++;
	}

	fclose(pf);
	pf = NULL;
}

void  InitContact(contact* con)//��ʼ��ͨѶ¼----�ļ���
{
	assert(con);
	con->sz = 0;
	con->data = (PeoInfor*)calloc(DEFAULT_SZ, sizeof(PeoInfor));
	if (con->data == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	con->capacity = DEFAULT_SZ;
	LoadContact(con);
}

void SaveContact(contact* con)//�ļ����±���ͨѶ¼
{
	assert(con);
	FILE* pf = fopen("contact.date", "wb");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	int i = 0;
	for (i = 0; i < con->sz; i++)
	{
		fwrite(con->data + i, sizeof(struct PeoInfor), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}

//void Add(contact* con)//�����ϵ��----��̬��
//{
//  assert(con);
//	if ((con->sz) == (con->capacity))
//	{
//		printf("ͨѶ¼�������޷����\n");
//		return;
//	}
//	printf("�����ϵ����Ϣ��\n");
//	printf("%-20s\t%-5s\t%-5s\t%-13s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");//����+�Ա�+����+�绰+��ַ
//	printf("������������");
//	scanf("%s", con->data[con->sz].name);
//	printf("�������Ա�");
//	scanf("%s", con->data[con->sz].sex);
//	printf("���������䣺");
//	scanf("%d", &(con->data[con->sz].age));
//	printf("������绰��");
//	scanf("%s", con->data[con->sz].tel);
//	printf("�������ַ��");
//	scanf("%s", con->data[con->sz].addr);
//	con->sz++;
//	printf("��ӳɹ�\n");
//}

void Add(contact* con)//�����ϵ��----��̬����ļ���
{
	assert(con);
	CheckCapacity(con);
	printf("�����ϵ����Ϣ��\n");
	printf("%-20s\t%-5s\t%-5s\t%-13s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");//����+�Ա�+����+�绰+��ַ
	printf("������������");
	scanf("%s", con->data[con->sz].name);
	printf("�������Ա�");
	scanf("%s", con->data[con->sz].sex);
	printf("���������䣺");
	scanf("%d", &(con->data[con->sz].age));
	printf("������绰��");
	scanf("%s", con->data[con->sz].tel);
	printf("�������ַ��");
	scanf("%s", con->data[con->sz].addr);
	con->sz++;
	printf("��ӳɹ�\n");
}


void display1(const PeoInfor* p)//��ʾѰ�ҵ���ϵ�˵���Ϣ
{
	assert(p);
	printf("%-20s\t%-5s\t%-5s\t%-13s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");//����+�Ա�+����+�绰+��ַ
	printf("%-20s\t%-5s\t%-5d\t%-13s\t%-30s\n", p->name, p->sex, p->age, p->tel, p->addr);
}

int find_by_name(const contact* con, int option)
{
	assert(con);
	char name[20] = { 0 };
	int i = 0;
	int j = option;

	switch (j)
	{
	case DEL:
		printf("��������Ҫɾ������ϵ�˵�������");
		break;
	case MOD:
		printf("��������Ҫ�޸ĵ���ϵ�˵�������");
		break;
	case SEARCH:
		printf("��������Ҫ���ҵ���ϵ�˵�������");
		break;
	}

	scanf("%s", &name);
	for (i = 0; i < (con->sz); i++)
	{
		if (strcmp(con->data[i].name, name) == 0)
		{
			display1(&(con->data[i]));//��ʾ�ҵ�����ϵ�˵���Ϣ
			return i;
		}
	}
	printf("����ϵ�˲�����\n");
	return -1;
}

void Del(contact* con)//ɾ����ϵ��
{
	assert(con);
	int i = 0;
	int m = find_by_name(con, DEL);
	if (m < 0)//�ҵ�Ҫɾ������ϵ��
	{
		return;
	}
	for (i = m; i < (con->sz); i++)
	{
		con->data[i] = con->data[i + 1];
	}
	con->sz--;
	printf("ɾ���ɹ�\n");
}

void Mod(contact* con)//�޸���ϵ����Ϣ
{
	assert(con);
	int m = find_by_name(con, MOD);
	if (m < 0)//�ҵ�Ҫ�޸ĵ���ϵ��
	{
		return;
	}
	printf("������������");
	scanf("%s", con->data[m].name);
	printf("�������Ա�");
	scanf("%s", con->data[m].sex);
	printf("���������䣺");
	scanf("%d", &(con->data[m].age));
	printf("������绰��");
	scanf("%s", con->data[m].tel);
	printf("�������ַ��");
	scanf("%s", con->data[m].addr);
	printf("�޸ĳɹ�\n");

}
void Search(const contact* con)//������ϵ��
{
	assert(con);
	find_by_name(con, SEARCH);
}

void Display(const contact* con)//��ʾ������ϵ����Ϣ
{
	assert(con);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-13s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (i = 0; i < (con->sz); i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-13s\t%-30s\n", con->data[i].name
			                                      , con->data[i].sex
			                                      , con->data[i].age
			                                      , con->data[i].tel
			                                      , con->data[i].addr);
	}
}


void Destroy(contact* con)//�ͷŶ�̬�ڴ�
{
	assert(con);
	free(con->data);
	con->data = NULL;
	con->sz = 0;
	con->capacity = 0;
}

//���ƣ���ô����ϵ������