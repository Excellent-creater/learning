#include <stdio.h>

const int Num = 10;

int main(int argc,const char* argv[])
{
	int* p1 =(int*)&Num;
	*p1 = 1100;
	const int num = 10;
	//num = 100;
	int* p =(int*)&num;
	*p = 88;
	printf("%d %d %p %p\n",num,*p,&num,p);
}
