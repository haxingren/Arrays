#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


//用冒泡排序的算法
//通过对比两个相邻元素，如果不满足需求就重新排列这两个元素
//例子
//4 3 2 1
//3 4 2 1
//3 2 4 1
//3 2 1 4
//这样就是一趟冒泡排序
//每一趟确认一个元素的最终位置
//所以趟数即元素个数减一
 

//数组传参时，形参有两种2写法
//1数组
//2指针

//形参是数组的形式
void BubbleSort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int n = 0;
		for (n = 0; n < sz - 1 - i; n++)
		{
			if (arr[n] > arr[n + 1])
			{
				int tmp = arr[n + 1];
				arr[n + 1] = arr[n];
				arr[n] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = { 9,1,5,8,3,2,6,9,2,46 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);//写一个函数将数组里的数字变为升序
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}