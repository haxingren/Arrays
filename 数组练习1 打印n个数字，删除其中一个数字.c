#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int m = 0;
	scanf("%d", &m);
	int arr[] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &arr[i]);
	}

	int del = 0;
	scanf("%d", &del);
	for (i = 0, j = 0; i < m; i++)
	{
		if (arr[i] != del)
		{
			arr[j++] = arr[i];
			printf("%d ", arr[j]);

		}
	}
	
	return 0;
}