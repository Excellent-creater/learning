#include <stdio.h>

int* func(void)
{
	static int num = 100;
	int* p = &num;
	return p;
}
int main(int argc,const char* argv[])
{
	int* p = func();
	printf("%d\n",*p);
	printf("hehe\n");
	printf("%d\n",*p);
}
