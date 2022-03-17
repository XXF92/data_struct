#include <stdio.h>

//通过被调用函数改变主调函数的变量的值

void f(int * p){
	*p = 100;
}


int main(){
	int a = 10;
	int b = 20;
	
	int * p = &a;
	int *q = &b;
	p =q;
	// f(p);
	// printf("*p=%d", *p);
	printf("p=%pq=%p\n", p,q);

	return 0;
}