#include <stdio.h>
#include <stdlib.h>


//1到n的和
int sumNumber(int n);

int main(void)
{	
	int n;
	printf("please input int:");
	scanf("%d", &n);
	printf("sum=%d\n", sumNumber(n));
	
	system("pause");
	
	return 0;
}


int sumNumber(int n)
{
	if (1 == n)
		return 1;
	else
		return sumNumber(n-1) + n;
}


