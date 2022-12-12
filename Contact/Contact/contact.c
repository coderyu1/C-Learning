#include "contact.h"

//void InitContact(contact* con)//初始化通讯录----静态版
//{
//	PeoInfor data[100] = { 0 };
//	con->sz = 0;
//	con->capacity = CAPACITY_MAX;
//}

//void InitContact(contact* con)//初始化通讯录----动态版
//{
//	PeoInfor* data = (struct PeoInfor*)malloc(3 * sizeof(struct PeoInfor));//这种写法会在调用void Add(contact * con)导致访问权限冲突错误
//	con->sz = 0;                                                           //原因在于：这里的data相当于重新开辟的，不属于结构体con
//	con->capacity = DEFAULT_SZ;                                            //而后续调用函数时，又把这里定义的data误作为结构体con的成员
//}                                                                        //实际的data并没有得到初始化和动态开辟内存

//void InitContact(contact* con)//初始化通讯录----动态版
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

void CheckCapacity(contact* con)//动态版和文件版下判断是否增容
{
	assert(con);
	if (con->sz == con->capacity)
	{
		PeoInfor* p = (PeoInfor*)realloc(con->data, (con->capacity + 2) * sizeof(PeoInfor));
		if (p == NULL)
		{
			printf("增容失败\n");
			return;
		}
		con->data = p;
		(con->capacity) += 2;
		printf("增容成功\n");
	}
}

void LoadContact(contact* con)//加载通讯录
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

void  InitContact(contact* con)//初始化通讯录----文件版
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

void SaveContact(contact* con)//文件版下保存通讯录
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

//void Add(contact* con)//添加联系人----静态版
//{
//  assert(con);
//	if ((con->sz) == (con->capacity))
//	{
//		printf("通讯录已满，无法添加\n");
//		return;
//	}
//	printf("添加联系人信息：\n");
//	printf("%-20s\t%-5s\t%-5s\t%-13s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");//姓名+性别+年龄+电话+地址
//	printf("请输入姓名：");
//	scanf("%s", con->data[con->sz].name);
//	printf("请输入性别：");
//	scanf("%s", con->data[con->sz].sex);
//	printf("请输入年龄：");
//	scanf("%d", &(con->data[con->sz].age));
//	printf("请输入电话：");
//	scanf("%s", con->data[con->sz].tel);
//	printf("请输入地址：");
//	scanf("%s", con->data[con->sz].addr);
//	con->sz++;
//	printf("添加成功\n");
//}

void Add(contact* con)//添加联系人----动态版和文件版
{
	assert(con);
	CheckCapacity(con);
	printf("添加联系人信息：\n");
	printf("%-20s\t%-5s\t%-5s\t%-13s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");//姓名+性别+年龄+电话+地址
	printf("请输入姓名：");
	scanf("%s", con->data[con->sz].name);
	printf("请输入性别：");
	scanf("%s", con->data[con->sz].sex);
	printf("请输入年龄：");
	scanf("%d", &(con->data[con->sz].age));
	printf("请输入电话：");
	scanf("%s", con->data[con->sz].tel);
	printf("请输入地址：");
	scanf("%s", con->data[con->sz].addr);
	con->sz++;
	printf("添加成功\n");
}


void display1(const PeoInfor* p)//显示寻找的联系人的信息
{
	assert(p);
	printf("%-20s\t%-5s\t%-5s\t%-13s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");//姓名+性别+年龄+电话+地址
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
		printf("请输入需要删除的联系人的姓名：");
		break;
	case MOD:
		printf("请输入需要修改的联系人的姓名：");
		break;
	case SEARCH:
		printf("请输入需要查找的联系人的姓名：");
		break;
	}

	scanf("%s", &name);
	for (i = 0; i < (con->sz); i++)
	{
		if (strcmp(con->data[i].name, name) == 0)
		{
			display1(&(con->data[i]));//显示找到的联系人的信息
			return i;
		}
	}
	printf("该联系人不存在\n");
	return -1;
}

void Del(contact* con)//删除联系人
{
	assert(con);
	int i = 0;
	int m = find_by_name(con, DEL);
	if (m < 0)//找到要删除的联系人
	{
		return;
	}
	for (i = m; i < (con->sz); i++)
	{
		con->data[i] = con->data[i + 1];
	}
	con->sz--;
	printf("删除成功\n");
}

void Mod(contact* con)//修改联系人信息
{
	assert(con);
	int m = find_by_name(con, MOD);
	if (m < 0)//找到要修改的联系人
	{
		return;
	}
	printf("请输入姓名：");
	scanf("%s", con->data[m].name);
	printf("请输入性别：");
	scanf("%s", con->data[m].sex);
	printf("请输入年龄：");
	scanf("%d", &(con->data[m].age));
	printf("请输入电话：");
	scanf("%s", con->data[m].tel);
	printf("请输入地址：");
	scanf("%s", con->data[m].addr);
	printf("修改成功\n");

}
void Search(const contact* con)//查找联系人
{
	assert(con);
	find_by_name(con, SEARCH);
}

void Display(const contact* con)//显示所有联系人信息
{
	assert(con);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-13s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (i = 0; i < (con->sz); i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-13s\t%-30s\n", con->data[i].name
			                                      , con->data[i].sex
			                                      , con->data[i].age
			                                      , con->data[i].tel
			                                      , con->data[i].addr);
	}
}


void Destroy(contact* con)//释放动态内存
{
	assert(con);
	free(con->data);
	con->data = NULL;
	con->sz = 0;
	con->capacity = 0;
}

//完善：怎么将联系人排序