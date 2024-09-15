#include <stdio.h>

auto int num = 0;

void func(void)
{
	int n = 10;
	printf("func:%d\n",num);	
}
int main(int argc,const char* argv[])
{
	int num = 10;
	printf("%d\n",num);
	if(1)
	{
		int num = 1;
		printf("if=%d\n",num);
	}
	scanf("%d",&num);
	if(num%2)
	{
		func();
	}
	printf("%d\n",num);
}
