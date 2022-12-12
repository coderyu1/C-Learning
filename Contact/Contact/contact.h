#pragma once

#define _CRT_SECURE_NO_WARNINGS

//1.ͷ�ļ�������
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//2.���Ͷ���
#define SIZE_NAME 20//���峣��
#define SIZE_SEX 5
#define SIZE_TEL 12
#define SIZE_ADDR 30
#define CAPACITY_MAX 100//----��̬��
#define DEFAULT_SZ 3//----��̬��

enum option//����ö�����ʹ���ѡ��
{
	EXIT,
	ADD,
	DEL,
	MOD,
	SEARCH,
	SORT,
	DISPLAY
};

 typedef struct PeoInfor//�����ṹ��-----��ϵ�ˣ�����+�Ա�+����+�绰+��ַ
{
	char name[SIZE_NAME];
	char sex[SIZE_SEX];
	int age;
	char tel[SIZE_TEL];
	char addr[SIZE_ADDR];
}PeoInfor;

//typedef struct contact//����ͨѶ¼----��̬��
//{
//	struct PeoInfor data[100];
//	int sz;
//	int capacity;
//}contact;

typedef struct contact//����ͨѶ¼----��̬��
{
	struct PeoInfor* data;
	int sz;
	int capacity;
}contact;

//3.��������
void InitContact(contact* con);//��ʼ��ͨѶ¼

void CheckCapacity(contact* con);//�ڶ�̬����ļ������ж��Ƿ�����

void LoadContact(contact* con);//�ļ����¼���ͨѶ¼

void SaveContact(contact* con);//�ļ����±���ͨѶ¼

void Add(contact* con);//�����ϵ��

void display1(const PeoInfor* p);//��ʾѰ�ҵ���ϵ�˵���Ϣ
void Display(const contact* con);//��ʾ������ϵ�˵���Ϣ

int find_by_name(const contact* con, int option);//������Ѱ����ϵ��
void Search(const contact* con);//������ϵ��

void Del(contact* con);//ɾ����ϵ��

void Mod(contact* con);//�޸���ϵ����Ϣ

void Destroy(contact* con);//�ͷŶ�̬�ڴ�

//���ƣ���ν���ϵ������



//void Sort(const contact* con);//����ϵ������
//int cmp(const void* p1, const void* p2);

