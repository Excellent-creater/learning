#include <stdio.h>

int main(int argc,const char* argv[])
{
	double arr[4] = {10,20,30,40};
	double* p = &arr[0];
	double* p1 = &arr[2];
	printf("%lf\n",*(p+1));
	printf("%lf\n",*p);
	printf("%d\n",p1-p);
}
