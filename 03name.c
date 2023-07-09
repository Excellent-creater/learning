#include <stdio.h>

int main(int argc,const char* argv[])
{
	int num = 10;
	printf("------\n");
	//printf("%d\n",(num+1)++);
	printf("%d\n",num/0);
	printf("------\n");
	int a = 0,b = 0,c = 0;
	int ret = 0;
	while(3 != (ret = scanf("%d%d%d",&a,&b,&c)))
	{
		printf("输入有误请继续..");
		stdin->_IO_read_ptr = stdin->_IO_read_end;
	}
	printf("%d %d %d\n",a,b,c);
}
