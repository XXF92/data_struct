#include <stdio.h>

int main()
{
	int a[5] = {4,5,6,7,8};
	int *p;
	p = a;
	p = p+4;
	printf("p=%d", p);
	return 0;
}