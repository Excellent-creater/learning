#include <stdio.h>

int func1(int num);

void func2(int arr[],int len)
{
//	printf("size=%d\n",sizeof(arr)/sizeof(arr[0]));
	arr[0] = 99;
}

int main(int argc,const char* argv[])
{
	int arr[10] = {};
	func2(arr,10);
	printf("arr[0]=%d\n",arr[0]);

	int num = 88;
	int ret = func1(num);
	printf("main=%d %p ret=%d\n",num,&num,ret);
}

int func1(int num)
{
	printf("num=%d %p\n",num,&num);
	num = 100;
	int ret = printf("num=%d \n",num);
	printf("")
	return ret;
}
