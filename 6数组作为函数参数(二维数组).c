#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int arr[3][4] = { 0 };
	//arr是二维数组的数组名，即整个数组的地址
	//arr[0]是二维数组第一行数组的数组名，即第一行的数组的地址
	//arr[0][0]是二维数组的首元素地址

	//如果arr+1，则直接跳过整个二维数组
	
	//由此，我们可以计算元素有几行几列

	//行数
	printf("%d\n", sizeof(arr) / sizeof(arr[0]));
	//            整个数组的大小   第一行数组的大小

	//列数
	printf("%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));
	//             第一行数组的大小    首元素大小
	return 0;
}