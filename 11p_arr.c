#include <stdio.h>

int main(int argc,const char* argv[])
{
	int arr[5] = {10,20,30,40,50};
	int* p_arr[5] = {};
	for(int i=0; i<5; i++)
	{
		p_arr[i] = &arr[i];
		printf("%d %d %p %p\n",arr[i],*p_arr[i],&arr[i],p_arr[i]);
	}
}
