#include <stdio.h>

int main(int argc,const char* argv[])
{
	int arr[10] = {};
	printf("%d\n",sizeof(arr[100000]));
	printf("%d\n",sizeof(1?3:3.14));

	int arr1[][2] = {1,2,3,4,5,6};
	printf("%d\n",arr1[1][1]);
}
