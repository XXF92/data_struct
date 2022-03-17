#include <stdio.h>
#include <stdlib.h>

//跨函数 动态内存分配 (相对于普通变量定义时静态分配)


struct student{
	int sid;
	int age;
};
void createStudent(struct student **p);
void show(struct student *p);



int main()
{
	struct student *st;
	createStudent(&st);
	show(st);

	return 0;
}


void createStudent(struct student **p)
{
	*p = (struct student *)malloc(sizeof(struct student));
	(*p)->sid = 100;
	(*p)->age = 20;
	
	
}
void show(struct student *p)
{
	printf("%d %d", p->sid, p->age);
}






















