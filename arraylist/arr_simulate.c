#include <stdio.h>
#include <stdlib.h>

struct arr{
	int *pBase;//第一个元素地址
	int len;//能容纳的最大元素个数
	int cnt;//有效元素个数
};


void arr_init(struct arr *a, int len);//初始化数组结构体
bool arr_append(struct arr *a, int ad);//追加
bool arr_insert(struct arr *a, int pos, int val);//插入 pos从1开始
bool arr_delete(struct arr *a, int pos, int *val);//删除数组某个位置的值 pos从1开始
int get();
bool is_empty(struct arr *a);//数组是否为空
bool is_full(struct arr *a);//数组是否装满
bool arr_sort(struct arr *a);//数组排序 
void arr_show(struct arr *a);//遍历打印数组
bool arr_inversion(struct arr *a);//反转数组
bool exchange(int *a, int *b);//交换两个变量的值


int main()
{
	struct arr *a;
	arr_init(a, 8);
	
	arr_append(a, 4);
	arr_append(a, 5);
	arr_append(a, 4);
	arr_append(a, 8);
	arr_append(a, 1);
	arr_append(a, 6);
	arr_append(a, 1);
	arr_append(a, 1);
	arr_show(a);

	// printf("cnt=%d\n", a->cnt);
	// arr_insert(a, 2, 666);
	// printf("------------\n");
	// arr_show(a);

	//删除
	// int v;
	// arr_delete(a, 2,&v);
	// printf("v=%d\n", v);
	// arr_show(a);
	// printf("------------\n");

	//倒转数组
	// arr_inversion(a);
	// arr_show(a);
	printf("------------\n");

	//排序
	arr_sort(a);
	arr_show(a);


	return 0;

}

bool arr_sort(struct arr *a)
{
	if (is_empty(a))
		return false;

	for (int i = 0; i < a->cnt-1; ++i)
	{

		for (int j = i; j < a->cnt-1; ++j)
		{
			if (*(a->pBase+i) > *(a->pBase+j+1))
			{
				exchange(a->pBase+i, a->pBase+j+1);
			}
		}
	}
	return true;
}

bool arr_inversion(struct arr *a)
{
	if (is_empty(a))
		return false;
	int i = 0;
	int j = a->cnt-1;
	int ch;
	while(i<j)
	{
		exchange(a->pBase+i, a->pBase+j);
		i++;
		j--;
	}

	return true;
}




bool exchange(int *a, int *b)
{
	if (a == b)
		return false;
	int ex;
	ex = *a;
	*a = *b;
	*b = ex;
	return true;
}

//int *val 用于取出被删除的值
bool arr_delete(struct arr *a, int pos, int *val)
{
	if (is_empty(a))
		return false;
	if(pos < 1 || pos > a->cnt)
		return false;
	*val = *(a->pBase+pos-1);

	for (int i = pos-1; i < a->cnt-1; ++i)
	{
		*(a->pBase+i) = *(a->pBase+i+1);	
	}

	a->cnt--;
	return true;

}

//int pos 插入的位置从1开始
bool arr_insert(struct arr *a, int pos, int val)
{
	if (is_full(a))
		return false;
	if(pos < 1 || pos > a->len || pos > a->cnt+1)
		return false;
	
	for (int i = a->cnt; i >= pos ; --i)
	{
		*(a->pBase + i)= *(a->pBase + i - 1);
	}
	*(a->pBase + pos - 1) = val;
	
	a->cnt++;
	return true;

}

bool arr_append(struct arr *a, int ad)
{
	if (is_full(a))
		return false;
	*(a->pBase + a->cnt) = ad;
	a->cnt++;
		return true;
}

bool is_full(struct arr *a)
{
	if (a->cnt == a->len)
		return true;
	else 
		return false;
}

void arr_init(struct arr *a, int len)
{
	a->pBase = (int *)malloc(sizeof(int) * len);
	if(NULL == a->pBase){
		printf("malloc error!\n");
		exit(-1);
	}
	a->len = len;
	a->cnt = 0;
	
}



void arr_show(struct arr *a)
{
	if (!is_empty(a))
	{
		for (int i = 0; i < a->cnt; ++i)
		{
			printf("%d\n", *(a->pBase + i));
		}
	} 
	else 
	{
		printf("array is empty!\n");
		return;
	}
}

bool is_empty(struct arr *a)
{
	if (0 == a->cnt)
		return true;
	else 
		return false;	
}


