#include <stdio.h>

int main(int argc,const char* argv[])
{
	int arr[5] = {10,20,30,40,50};
	int arr2[3][3] = {1,2,3,4,5,6,8,9,10};
	printf("%d %d\n",arr2[2][1],*(*(arr2+2)+1));
	printf("%p %p %p\n",&arr,&arr[0],arr);
//	arr = NULL;
	int* p = (int*)(&arr+1);
	printf("%d\n",*(p-1));


	int (*arrp)[5] = &arr;
	int* p1 = arr;
	for(int i=0; i<5; i++)
	{
		printf("%d ",(*arrp)[i]);	
		printf("%d %d\n",*(p1+i),*(arr+i));
	}
}
