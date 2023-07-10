#include <stdio.h>

void swap(int** p1,int** p2)
{
	int* p = *p1;
	*p1 = *p2;
	*p2 = p;
}

int main(int argc,const char* argv[])
{
	int num1 = 10, num2 = 20;
	int *p1 = &num1,*p2 = &num2;
	printf("p1 %d %p  p2 %d %p\n",*p1,p1,*p2,p2);
	swap(&p1,&p2);
	printf("p1 %d %p  p2 %d %p\n",*p1,p1,*p2,p2);
}
