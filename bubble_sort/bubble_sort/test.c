#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void bubble_sort(int arr[], int n)
{
	/*int i = 0;
	int tmp = 0;*/
	//while (n > 0)//��������
	//{
	//	for (i = 0; i < n - 1; i++)//һ������
	//	{
	//		if (arr[i] > arr[i + 1])
	//		{
	//			tmp = arr[i];
	//			arr[i] = arr[i + 1];
	//			arr[i + 1] = tmp;
	//		}
	//	}
	//	n--;
	//}
	int i, j, min;
	//���ѭ������������
	for (i = 0; i < n - 1; i++)
	{
		//�ڲ�ѭ�����Ƚϴ���
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 1, 9, 2, 8, 3, 10, 7, 4, 6, 5 };
	int i = 0;

	int len = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr, len);

	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}