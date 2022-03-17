#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


/*
循环队列 数组实现
*/

typedef struct cirQueue
{
	int *pBase;
	int front;
	int rear;
}CQUERU,* PCQUEUE;


//初始化循环队列
PCQUEUE init_cirQueue(int length);
//入队
void in_queue(PCQUEUE p, int val, int len);
//出队
void out_queue(PCQUEUE p, int *val, int len);
//队列是否为空
bool isEmpty(PCQUEUE p);
//队列是否已满
bool isFull(PCQUEUE p, int len);
//遍历队列
void traverseCirQueue(PCQUEUE p);
//求当前队列的数组的长度
int getLength(PCQUEUE p);



int main(void)
{
	int len = 5;
	int a;
	PCQUEUE p = init_cirQueue(len);

	//入队 数组长度为5 可以存放4个数据
	in_queue(p, 1, len);
	in_queue(p, 2, len);
	in_queue(p, 3, len);
	in_queue(p, 4, len);
	traverseCirQueue(p);

	//出队
	out_queue(p, &a, len);
	traverseCirQueue(p);
	printf("a=%d\n", a);

	out_queue(p, &a, len);
	traverseCirQueue(p);
	printf("a=%d\n", a);

	out_queue(p, &a, len);
	traverseCirQueue(p);
	printf("a=%d\n", a);

	traverseCirQueue(p);
	system("pause");
	return 0;
}

void out_queue(PCQUEUE p, int* val, int len)
{
	if (p == NULL || isEmpty(p))
	{
		printf("out_queue error!\n");
		return;
	}
	*val = p->pBase[p->front];
	p->front = (p->front + 1) % len;//p->front 移到下个角标
	return;
}

//p->rear 指向的是最后一个元素的下一位，所以方便添加操作
void in_queue(PCQUEUE p, int val, int len)
{
	if (NULL == p)
		exit(-1);

	if (isFull(p, len))
	{ 
		printf("queue is full!\n");
		return;
	}
	p->pBase[p->rear] = val;
	p->rear = (p->rear + 1) % len;//p->rear 移到下个角标
	return;
}

//front=rear
bool isEmpty(PCQUEUE p)
{
	if (NULL == p)
		exit(-1);
	if (p->front == p->rear)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//rear和front是角标 角标+1%len
bool isFull(PCQUEUE p, int len)
{
	if (NULL == p)
		exit(-1);

	// printf("front=%d rear=%d %d\n", p->front, p->rear, (p->rear + 1) % len);
	if ((p->rear + 1) % len  == p->front)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}




PCQUEUE init_cirQueue(int length)
{
	PCQUEUE p = (PCQUEUE)malloc(sizeof(CQUERU));
	if (NULL == p)
	{
		printf("init cirQueue error!\n");
		exit(-1);
	}
	int *a;
	a =(int*)malloc(sizeof(int)*length);
	if (NULL == a)
	{
		printf("init array error!\n");
		exit(-1);
	}
	p->pBase = a;
	for (int i = 0; i < length; ++i)
	{
		*a = 0;
		a++;
	}
	a = NULL;
	p->front = 0;
	p->rear = 0;
	return p;
}

void traverseCirQueue(PCQUEUE p)
{
	if (NULL == p)
	{
		printf("queue is null!\n");
		exit(-1);
	}
	if (p->front == p->rear)
	{
		printf("Queue is isEmpty!\n");
		return;
	}

	int i = p->front;
	while(i != p->rear)
	{
		printf("%d ", p->pBase[i]);
		i++;
	}
	printf("\n");
	return;

}
