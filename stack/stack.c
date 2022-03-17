#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//节点
typedef struct node
{
	int data;
	struct node * pNext;
}NODE, *PNODE;

//栈
typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, *PSTACK;


//栈的操作 压栈和出栈
PSTACK init(void);
void push(PSTACK p, int val);//压栈
void pop(PSTACK p, int* val);//出栈
void showStack(PSTACK s);//输出栈
void clear(PSTACK s);//清空栈
void reverseStack(PSTACK s);//遍历栈
bool emptyStack(PSTACK s);//判断栈是否为空

int main(void)
{
	int a;

	PSTACK s = init();
	printf("%p\n", s);

	//push操作
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	push(s, 5);
	reverseStack(s);

	//pop操作
	pop(s, &a);
	printf("pop val:%d\n", a);
	reverseStack(s);
	pop(s, &a);
	printf("pop val:%d\n", a);
	reverseStack(s);

	push(s, 5);
	reverseStack(s);

	//清空
	clear(s);
	reverseStack(s);


	system("pause");
	return 0;
}

void clear(PSTACK s)
{
	if (NULL == s || NULL == s->pBottom  || NULL == s->pTop)
	{
		printf("clear error, stack point is NULL!\n");
		exit(-1);
	}

	PNODE p;
	int a;

	while(s->pTop != s->pBottom)
	{
		p = s->pTop;
		s->pTop = p->pNext;
		free(p);
	}

	//使用 emptyStack 和 pop函数
	// while(!emptyStack(s))
	// {
	// 	pop(s, &a);
	// }
	// return;

}

void pop(PSTACK s, int * val)
{
	if (NULL == s || NULL == s->pBottom  || NULL == s->pTop)
	{
		printf("pop error, stack point is NULL!\n");
		exit(-1);
	}
	if (emptyStack(s))
	{
		printf("stack is empty!\n");
		exit(-1);
	}
	//临时存放出栈的节点的地址
	PNODE p = s->pTop;

	s->pTop = p->pNext;
	*val = p->data;

	free(p);
	p = NULL;

	return; 
}

void push(PSTACK s, int val)
{
	if (NULL == s || NULL == s->pBottom  || NULL == s->pTop)
	{
		printf("push error, stack point is NULL!\n");
		exit(-1);
	}

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("pNew is NULL, error!\n");
		exit(-1);
	}

	pNew->data = val;
	pNew->pNext = s->pTop;
	s->pTop = pNew;

	return;
}

bool emptyStack(PSTACK s)
{
	if (s->pTop == s->pBottom)
		return true;
	else
		return false;
}

void reverseStack(PSTACK s)
{
	if (emptyStack(s))
	{
		printf("stack is empty!\n");
		return;
	}

	PNODE p = s->pTop; 

	while(p != s->pBottom)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

PSTACK init(void)
{
	PNODE p = (PNODE)malloc(sizeof(NODE));
	if (NULL == p)
	{
		printf("init error!\n");
		exit(-1);
	}
	p->pNext = NULL;

	PSTACK s;
	s->pBottom = p;
	s->pTop = p;

	return s;
}

