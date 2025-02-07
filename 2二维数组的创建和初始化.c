﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	//当存在多组整数，如
	//1234
	//2345
	//3456
	//时，我们可以使用二维数组来储存这些数据
	//二维数组的创建需要确定数组有几行 几列
	int arr[3][4];
	//这个意思就是三行 四列
	//其中代表列 的第二个[]必须指定
	//而代表行 的第一个[]则可以不指定，由编译器自行根据数据指定
	int arr0[][4] = { 1,2,3,4,5,6 };
	//1234
	//5600

	int arr1[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };//这是完全初始化数组的情况
	//根据已确定的行数 列数，编译器会将数据根据输入顺序排好成
	//1234
	//2345
	//3456
	
	int arr2[3][4] = { 1,2,3,4,5,6 };//这是不完全初始化的数组，最终会排成
	//1234
	//5600
	//0000
	//多余的空间都会默认初始化为0；

	//如果想指定不完全初始化的内数据的排序
	//可以将每组数据用{}包起来
	int arr3[3][4] = { {1,2},{3,4},{5,6} };
	//1200
	//3400
	//5600

	
	//二维数组的使用
	//也是使用下标，不过需要包含行和列的下标
	//printf("%d\n", arr3[1][1]);
	//int i = 0;
	//int j = 0;
	//for (i = 0; i < 3; i++)//每次进入循环i变成下一行的下标
	//{
	//	for (j = 0; j < 4; j++)//每次循环j变成下一列的下标
	//		printf("%d ", arr3[i][j]);
	//	printf("\n");//每进入下一行，换行
	//}

	int qrr1[4] = { 1,2,3,4 };
	int qrr2[4] = { 2,3,4,5 };
	int qrr3[4] = { 3,4,5,6 };
	int qrr[3][4] = { {qrr1},{qrr2},{qrr3} };
	int x = 0;
	int y = 0;
	for (x = 1; x < 3; x++)
	{
		for (y = 1; y < 4; y++)
		{
			printf("%d ", qrr[x][y]);
		}
		printf("\n");
	}
	return 0;
}