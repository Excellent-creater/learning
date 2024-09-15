#include <stdio.h>

void func(void)
{
	static int num = 0;
	//num = 0;
	printf("%d\n",num++);
}

void func1(void)
{
	func1();	
}

int main(int argc,const char* argv[])
{
	func1();
	for(int i=0; i<10; i++)
	{
		func();	
	}
}
