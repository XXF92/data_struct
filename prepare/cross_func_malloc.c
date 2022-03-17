#include <stdio.h>
#include <stdlib.h>

//跨函数动态内存分配

struct student{
	int sid;
	int age;
};
struct student * createStudent(void);
void show(struct student *p);



int main()
{
	struct student *st;
	st = createStudent();
	show(st);

	return 0;
}


struct student * createStudent(void)
{
	struct student *p = (struct student *)malloc(sizeof(struct student));
	p->sid = 100;
	p->age = 20;
	return p;

}
void show(struct student *p)
{
	printf("%d %d", p->sid, p->age);
}






















