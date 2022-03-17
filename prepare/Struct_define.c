#include <stdio.h>

struct student{
	char name;
	int age;
	int number;
};

int main()
{
	struct student st = {'c',20,230};
	printf("st.age=%d\n", st.age);
	struct student *p = &st;
	printf("p->age=%d\n", p->age);
	printf("(*p).age=%d\n", (*p).age);
	return 0;
}