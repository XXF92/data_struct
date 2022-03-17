#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*
链式队列的数据结构和算法操作
*/

//
typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, *PNODE;

typedef struct Queue
{
	NODE * front;
	struct Node * rear;
}QUEUE, *PQUEUE;

//操作
PQUEUE initQueue();	//初始化链式队列
void push(PQUEUE p, int val); //入队
void pop(PQUEUE p, int * val); //出队
bool emptyQueue(PQUEUE p); //判断链式队列是否为空
void reverseQueue(PQUEUE p);//遍历链式队列


int main(void)
{
	int a;
	//初始化 
	PQUEUE p = initQueue();
	
	//入队
	push(p, 1);
	push(p, 2);
	push(p, 3);
	push(p, 4);
	push(p, 5);
	reverseQueue(p);

	//出队
	pop(p, &a);
	printf("%d\n", a);
	reverseQueue(p);
	pop(p, &a);
	printf("%d\n", a);
	reverseQueue(p);
	pop(p, &a);
	printf("%d\n", a);
	reverseQueue(p);



	system("pause");
	return 0;
}



bool emptyQueue(PQUEUE p)
{
	if (p->rear == p->front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void pop(PQUEUE p, int * val)
{
	if (p == NULL || emptyQueue(p))
	{
		printf("queue is empty, pop error!\n");
		exit(-1);
	}
	*val = p->front->pNext->data;
	PNODE q = p->front->pNext;
	p->front->pNext = q->pNext;
	free(q);
	q = NULL;
	return;
}

void push(PQUEUE p, int val)
{
	if (p == NULL)
	{
		printf("push error!\n");
		exit(-1);
	}

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		printf("push error!\n");
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = NULL;
	p->rear->pNext = pNew;
	p->rear = pNew;
	return;
	
}

void reverseQueue(PQUEUE p)
{
	if (NULL == p || p->front == p->rear)
		exit(-1);
	PNODE q = p->front; 
	while(q->pNext != NULL)
	{
		printf("%d ", q->pNext->data);
		q = q->pNext;
	}
	printf("\n");
	return;
}

PQUEUE initQueue()
{
	PQUEUE p = (PQUEUE)malloc(sizeof(QUEUE));
	if (NULL == p)
	{
		printf("initQueue error!\n");
		exit(-1);
	}

	PNODE q = (PNODE)malloc(sizeof(NODE));
	if (NULL == q)
	{
		printf("initQueue error!\n");
		exit(-1);
	}

	q->pNext = NULL;
	p->front = q;
	p->rear = q;
	return p;
}

