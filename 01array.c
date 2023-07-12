#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define TYPE int
#define PH "%d "

//	设计顺序表结构
typedef struct Array
{
	TYPE* ptr;		//	存储元素的内存首地址
	size_t cal;		//	表的容量
	size_t cnt;		//	元素的数量
}Array;

//	创建
Array* create_array(size_t cal)
{
	//	给顺序表结构分配内存
	Array* arr = malloc(sizeof(Array));
	//	给数据元素分配内存
	arr->ptr = malloc(sizeof(TYPE)*cal);
	//	记录表的容量
	arr->cal = cal;
	//	初始化元素的数量
	arr->cnt = 0;

	return arr;
}

//	销毁
void destroy_array(Array* arr)
{
	free(arr->ptr);
	free(arr);
}
//	清空
void clear_array(Array* arr)
{
	arr->cnt = 0;	
}

//	插入
bool insert_array(Array* arr,size_t index,TYPE data)
{
	//	判断表是否满
	if(arr->cnt >= arr->cal)	return false;
	//	判断下标是否能保持元素的连续性
	if(index > arr->cnt) return false;

/*
	//	数据向后移动
	for(int i=arr->cnt; i>index; i--)
	{
		arr->ptr[i] = arr->ptr[i-1];	
	}
*/
	memmove(arr->ptr+index+1,arr->ptr+index,(arr->cnt-index)*sizeof(TYPE));

	//	插入数据
	arr->ptr[index] = data;
	arr->cnt++;
	return true;
}

//	删除
bool delete_array(Array* arr,size_t index)
{
	if(index >= arr->cnt) return false;
	/*
	for(int i=index; i<arr->cnt-1; i++)
	{
		arr->ptr[i] = arr->ptr[i+1];
	}
	*/
	memmove(arr->ptr+index,arr->ptr+index+1,(arr->cnt-index-1)*sizeof(TYPE));
	arr->cnt--;
	return true;
}

//	访问
bool access_array(Array* arr,size_t index,TYPE* data)
{
	if(index >= arr->cnt) return false;
	*data = arr->ptr[index];
	return true;
}

//	查询
int query_array(Array* arr,TYPE data)
{
	for(int i=0; i<arr->cnt; i++)
		if(arr->ptr[i] == data) return i;
	return -1;
}
//	修改
bool modify_array(Array* arr,size_t index,TYPE data)
{
	if(index >= arr->cnt) return false;
	arr->ptr[index] = data;
	return true;
}

//	排序
void sort_array(Array* arr)
{
	for(int i=0; i<arr->cnt-1; i++)
	{
		for(int j=i+1; j<arr->cnt; j++)	
		{
			if(arr->ptr[j] < arr->ptr[i])
			{
				TYPE temp = arr->ptr[j];
				arr->ptr[j] = arr->ptr[i];
				arr->ptr[i] = temp;
			}
		}
	}
}

//	遍历
void show_array(Array* arr)
{
	for(int i=0; i<arr->cnt; i++)
	{
		printf(PH,arr->ptr[i]);	
	}
	printf("\n");
}

int main(int argc,const char* argv[])
{
	Array* arr = create_array(10);	

	for(int i=0; i<5; i++)
	{
		insert_array(arr,0,i+1);	
	}

	insert_array(arr,1,8);	
	delete_array(arr,5);
	show_array(arr);

	int num = 0;
	if(access_array(arr,5,&num))
		printf("num=%d\n",num);
	else
		printf("index error\n");
	
	printf("index=%d\n",query_array(arr,80));

	sort_array(arr);
	clear_array(arr);
	show_array(arr);
	destroy_array(arr);

}







