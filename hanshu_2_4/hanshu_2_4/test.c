#include <stdio.h>

void exchange(char arrA[], char arrB[], int n)
{
	int i = 0;
	char tmp = 0;
	for (i = 0; i < n; i++)
	{
		tmp = arrA[i];
		arrA[i] = arrB[i];
		arrB[i] = tmp;
	}
}

void print(char arr[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%c", arr[i]);
	}
	printf("\n");
}
int main()
{
	char arrA[10] = "QWERTYUIOP";
	char arrB[10] = "asdfghjkl9";
	int sz = sizeof(arrA) / sizeof(arrA[0]);

	exchange(arrA, arrB, sz);
	print(arrA, sz);
	print(arrB, sz);

	return 0;
}