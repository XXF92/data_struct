#include <stdio.h>

// 二叉树遍历

struct BT{
	int a;
};

int main(void)
{
	struct BT bt = {11};
	printf("%d\n", bt.a);
	return 0;
}