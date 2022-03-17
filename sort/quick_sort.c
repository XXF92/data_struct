#include <stdio.h>

void QuickSort(int * a, int low, int high);
int FindPost(int * a, int low, int high);

int main(void)
{
	// int a[15] = {2,1,0,5,4,3,-1,5,89,63,55,4,8,0,-9};
	int a[8] = {2,1,0,5,4,3,8,3};

	QuickSort(a,0,8);//第二个参数表示第一个元素下标 第三个参数表示最后一个元素的下标
	
	for (int i=0; i<7; i++)
		printf("%d , ", a[i]);
	printf("\n");

	return 0;
}

//排序 升序
void QuickSort(int * a, int low, int high)
{
	if (low < high){
		int val = a[low];
		//1.找到某个元素位置
		int pos = FindPost(a, low, high);
		//2.根据位置分成左右两边，再递归的对两边排序
		QuickSort(a, low, pos-1);
		QuickSort(a, pos+1, high);
	}
}

//找位置 升序
int FindPost(int * a, int low, int high)
{
	//如果位置high的值比val小，把high位置的值赋值给low，否则向左移动一位
	//如果位置low的值比val大，把low位置的值赋值给high，否则向右移动一位
	//当high==low 返回位置
	int val = a[low];
	while(low < high)
	{
		while (low < high && a[high] >= val)
			high--;
		a[low] = a[high];

		
		while (low < high && a[low] <= val)
			low++;
		a[high] = a[low];
		printf("%d\n", a[low]);
	}
	a[low] = val;//把找到的值放到确切的位置
	return high;
}