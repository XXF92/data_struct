#include <stdio.h>
#include <stdlib.h>

//自定义一个数组的长度并初始化
int main()
{
	int a;
	printf("length:");
	scanf("%d", &a);
	
	int *pArr = (int*)malloc(sizeof(int) * a);
	for(int i = 0; i < a; i++)
	{
		printf("input:\n");
		scanf("%d", pArr+i);
		
	}
	// printf("%d\n", *pArr);
	for(int j = 0; j < a; j++)
	{
		printf("%d\n", pArr[j]);
		
	}

	free(pArr); 
	return 0;
}