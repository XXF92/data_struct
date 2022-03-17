#include <stdio.h>
#include <stdlib.h>

//汉诺塔问题 number是移动个数  将number个从 star 借助 mid 移到 end
void hanoiTower(int number, char star, char mid, char end);

char star = 'A';//开始柱子
char mid = 'B';//中间柱子
char end = 'C';//目的柱子

int main(void)
{
	int n;
	printf("please input number:");
	scanf("%d", &n);
	hanoiTower(n, star, mid, end);
	system("pause");
	return 0;
}

//有三根柱子 A B C ，A柱子上有4个盘子，将4个盘子通过B柱子移到C柱子
//将A柱子设置为star B为mid C为end

void hanoiTower(int number, char star, char mid, char end)
{
	if(number == 1)
	{
		printf("No.%d:%c->%c\n",number, star, end);
		return;
	}	
	else
	{
		/*
			先将前n-1个盘子从A借助C移到B
			再将第n个盘子从A移到C
			最后将前n-1个盘子从B借助A移到C
		*/
		hanoiTower(number - 1, star, end, mid);
		printf("No.%d:%c->%c\n",number, star, end);
		hanoiTower(number - 1, mid, star, end);

	}
	
}