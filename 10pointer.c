#include <stdio.h>

int main(int argc,const char* argv[])
{
	printf("%s\n",argv[0]);
	printf("%s\n",argv[1]);
	int num = 10;
	int* const p = &num;
	*p = 188;
//	p = NULL;
}
