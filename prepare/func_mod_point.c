#include <stdio.h>


void mod(int ** p);

//通过外部函数改变指针变量的值，把指针变量当成一般的变量传入，
//注意类型是 int**
int main()
{
	int a = 10;
	int *p = &a;
	printf("%p\n", p);
	mod(&p);
	printf("%p\n", p);
	return 0;
}

void mod(int ** p)
{
	*p = (int*)0x0028ff30;
}