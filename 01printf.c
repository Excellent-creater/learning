#include <stdio.h>

#define NUM 10

int main(int argc,const char* argv[])
{
	int num = 10;
	printf("%d %d",NUM,num);
	printf("%d %d %d %d\n",num++,++num,++num,num++);
}
