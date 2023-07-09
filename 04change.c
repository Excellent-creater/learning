#include <stdio.h>

int main(int argc,const char* argv[])
{
	char ch = -100;
	unsigned short sh = 50;
	printf("%d %d\n",sizeof(ch+sh),sizeof((char)sh));
	if(ch + sh > 0)
	{
		printf(">0\n");	
	}
	else
	{
		printf("<0\n");	
	}

	unsigned char* p = &ch;
	printf("%p %u\n",p,(unsigned int)p);
}
