
#include <stdio.h>
#include <stdlib.h>


//节点结构体
typedef struct node
{
	int data;
	struct node * pNext;

}NODE, *PNODE;

PNODE create_list(int len);//创建一个有len个节点的链表
bool is_empty(PNODE pHead);//判断链表是否为空
void reverse_list(PNODE pHead);//链表遍历
int list_len(PNODE pHead);//链表长度
bool list_sort(PNODE pHead);//链表排序
bool list_insert(PNODE pHead, int pos, int val);//在链表的第pos个节点的前面插入一个节点 pos值从1开始
bool list_insert_example(PNODE pHead, int pos, int val);//插入一个节点(官方写法)
bool list_delete(PNODE pHead, int pos, int* val);//删除第pos个节点 val存放被删除的节点的值
PNODE getPosition(PNODE pHead, int pos);//获取



int main()
{
	PNODE pHead = NULL;
	PNODE pTail = NULL;

	pHead = create_list(3);
	printf("pHead->pNext=%p\n", pHead->pNext);

	return false;
	
	reverse_list(pHead);
	printf("len=%d\n", list_len(pHead));
	
	printf("after sort:\n");
	list_sort(pHead);
	reverse_list(pHead);

	// printf("insert_test:\n");
	// int a;
	// scanf("%d", &a);
	// list_insert_example(pHead,1,a);
	// reverse_list(pHead);

	printf("delete_test:\n");
	int b;
	list_delete(pHead,3,&b);
	reverse_list(pHead);

	system("pause");
	
	
	return 0;
}

bool list_delete(PNODE pHead, int pos, int* val)
{
	int i = 0;
	PNODE p = pHead;

	while(p->pNext != NULL && i < pos-1)
	{
		p =  p->pNext;
		i++;
	}
	if (p->pNext == NULL || i > pos-1)
	{
		return false;
	}

	PNODE q = p->pNext;
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;

}


bool list_insert_example(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	//下面的while循环和if判断注意写法
	//我们需要在第pos个节点的前面插入，所以i的值要累计到pos-1（假设pos值是合法的小于len）。 
	//当链表的len不为0，循环到i时, 此时p的地址是第i个节点的地址，而p->pNext是第i+1个节点的地址，执行p=p->pNext,把p 的地址改为i+1个节点的地址,然后i++  .
	//当链表len为0 ，此时i<pos-1 不成立 p的地址为pHead地址

	while(NULL != p && i < pos-1)
	{
		p = p->pNext;
		i++;
	}
	//当i>pos-1 表示pos 的值不合法，而pos的输入值可能是任意的,由于上面的循环判断NULL!=p使得i的值不会超过len+1,如果pos不合法则i必然大于len+1 ,而此时p为NULL，return false
	if (i > pos-1 || NULL == p)
	{
		return false;
	}

	

	PNODE q = (PNODE)malloc(sizeof(NODE));
	if (NULL == q)
	{
		exit(-1);
	}
	q->data = val;
	PNODE r = p->pNext;
	p->pNext = q;
	q->pNext = r;
	return true;

}

bool list_insert(PNODE pHead, int pos, int val)
{
	
	if (is_empty(pHead) ||  (list_len(pHead) + 1) < pos)
	{
		return false;
	}

	PNODE p,q;
	p = pHead;

	for (int i = 1; i < pos; ++i)
	{
		p = p->pNext;
	}

	q = (PNODE)malloc(sizeof(NODE));
	q->data = val;
	//判断是否插入后为最后一个元素
	if (p->pNext != NULL)
	{
		q->pNext = p->pNext;
		
	}
	else
	{
		q->pNext = NULL;
	}
	p->pNext = q;
	

	return true;

}


bool list_sort(PNODE pHead)
{
	if (is_empty(pHead))
	{
		return false;
	}
	int len = list_len(pHead);
	int i,j,k;
	PNODE p,q;	
	for (i = 1, p = pHead->pNext; i < len; i++,p = p->pNext)
	{		
		for (j = i, q = p->pNext; j < len; j++,q = q->pNext)
		{
			//从大到小排序
			if (p->data < q->data)
			{
				k = p->data;
				p->data = q->data;
				q->data = k;
			}
			
		}
	}

	return true;

}

PNODE getPosition(PNODE pHead, int pos)
{
	int len = list_len(pHead);
	if (is_empty(pHead) || pos <= 0 || pos > len)
	{
		printf("error\n");
		exit(-1);
	}

	int i = 0;
	PNODE pCurrent = pHead;
	while(i < pos - 1)
	{
		pCurrent = pCurrent->pNext;
	}
	return pCurrent;
}

//获取链表的有效长度
int list_len(PNODE pHead)
{
	int len =  0;

	PNODE pCurrent =  pHead->pNext;
	
	while(NULL != pCurrent)
	{
		pCurrent = pCurrent->pNext;
		len++;
		
	}

	return len;
}

//遍历链表
void reverse_list(PNODE pHead)
{
	if (is_empty(pHead))
	{
		printf("list is empty!\n");
	}
	PNODE pCurrent =  pHead->pNext;
	
	
	while(NULL != pCurrent)
	{
		
		printf("%d ", pCurrent->data);
		pCurrent = pCurrent->pNext;
		
	}

}


//创建一个链表
PNODE create_list(int len)
{	
	//分配内存空间获得头节点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
  	{
  		printf("pNew failed!");
  		exit(-1);
  	}
  	//初始化链表，设置尾节点
	int val;
	PNODE pTail = pHead; 
	pTail->pNext = NULL;

	//创建新节点 这里新节点不能挂到pHead->pNext里 否则每次循环建立新节点都是挂到pHead->pNext里了，所以需要一个指针pTail 来挂
	PNODE pNew = NULL;
	for (int i = 0; i < len; ++i)
	{
		printf("input:\n");
		scanf("%d", &val);

	  	pNew = (PNODE)malloc(sizeof(NODE));

	  	if (NULL == pNew)
	  	{
	  		printf("pNew failed!");
	  		exit(-1);
	  	}

	  	// 新节点添加到链表 
	  	pNew->data = val;
	  	pNew->pNext = NULL;
		printf("pNew=%p\n", &pNew);

	  	//改变尾节点及其指向
	  	pTail->pNext = pNew;//第一个有效元素添加前是pHead=pTail的 所以第一次添加后pHead->pNext也指向了pNew
	  	pTail = pNew;
		
	}
	return pHead;
}


//寻找链表最后一个节点的地址
PNODE find_last_address(PNODE p)
{
	if (!is_empty(p))
	{
		PNODE q = p->pNext;
		while(NULL != q)
		{
			q = q->pNext;
		}
		return q;
	}
	
		
}

//添加节点
bool appendNode(PNODE p, int val, PNODE pTail)
{
	PNODE q = p;
	PNODE r = (PNODE)malloc(sizeof(NODE));
	if (NULL != r)
	{
		pTail = r;
		r->data = val;
		r->pNext = NULL;
		q->pNext = r;
		return true;
	}
	else
	{
		return false;
	}
	

}


//判断链表是否为空
bool is_empty(PNODE p)
{
	if (NULL == p->pNext)
	{
		return true;
	}
	else
	{
		return false;
	}
}

