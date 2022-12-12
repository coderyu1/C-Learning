#pragma once

#define _CRT_SECURE_NO_WARNINGS

//1.头文件的引用
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//2.类型定义
#define SIZE_NAME 20//定义常量
#define SIZE_SEX 5
#define SIZE_TEL 12
#define SIZE_ADDR 30
#define CAPACITY_MAX 100//----静态版
#define DEFAULT_SZ 3//----动态版

enum option//创建枚举类型代替选择
{
	EXIT,
	ADD,
	DEL,
	MOD,
	SEARCH,
	SORT,
	DISPLAY
};

 typedef struct PeoInfor//创建结构体-----联系人：姓名+性别+年龄+电话+地址
{
	char name[SIZE_NAME];
	char sex[SIZE_SEX];
	int age;
	char tel[SIZE_TEL];
	char addr[SIZE_ADDR];
}PeoInfor;

//typedef struct contact//创建通讯录----静态版
//{
//	struct PeoInfor data[100];
//	int sz;
//	int capacity;
//}contact;

typedef struct contact//创建通讯录----动态版
{
	struct PeoInfor* data;
	int sz;
	int capacity;
}contact;

//3.函数声明
void InitContact(contact* con);//初始化通讯录

void CheckCapacity(contact* con);//在动态版和文件版下判断是否增容

void LoadContact(contact* con);//文件版下加载通讯录

void SaveContact(contact* con);//文件版下保存通讯录

void Add(contact* con);//添加联系人

void display1(const PeoInfor* p);//显示寻找的联系人的信息
void Display(const contact* con);//显示所有联系人的信息

int find_by_name(const contact* con, int option);//按名字寻找联系人
void Search(const contact* con);//查找联系人

void Del(contact* con);//删除联系人

void Mod(contact* con);//修改联系人信息

void Destroy(contact* con);//释放动态内存

//完善：如何将联系人排序



//void Sort(const contact* con);//将联系人排序
//int cmp(const void* p1, const void* p2);

