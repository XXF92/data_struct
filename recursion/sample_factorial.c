#include <stdio.h>
#include <stdlib.h>

//求阶乘 注意数值过大时整型溢出结果为0

//用递归求n的阶乘 n不小于0
int get_factorial(int n);

int main(void)
{
	int n;
	printf("please input int:");
	scanf("%d", &n);

	printf("n!=%d\n", get_factorial(n));
	system("pause");
	return 0;
}

int get_factorial(int n)
{
	if (1 == n)
		return 1;
	else
		return get_factorial(n-1) * n;
}