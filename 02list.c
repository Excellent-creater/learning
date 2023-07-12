#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TYPE int

//	设计链表的节点结构
typedef struct Node
{
	TYPE data;			//	节点的数据域
	struct Node* next;	//	节点的指针域
}Node;

//	创建节点
Node* create_node(TYPE data)
{
	//	申请节点的内存
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//	头添加
void add_head_list(Node** head,TYPE data)
{
	//	创建待添加的节点
	Node* node = create_node(data);
	node->next = *head;
	*head = node;
}

//	按值删除
bool del_value_list(Node** head,TYPE data)
{
	if((*head)->data == data)
	{
		Node* temp = *head;
		*head = (*head)->next;
		free(temp);
		return true;
	}
	//	遍历找到待删除节点的前一个节点
	for(Node* n=*head; n->next; n=n->next)
	{
		if(n->next->data == data)
		{
			Node* temp = n->next;
			n->next = n->next->next;
			free(temp);
			return true;
		}
	}
	return false;
}

//	遍历链表
void show_list(Node* head)
{
	for(Node* n=head; n; n=n->next)
	{
		printf("%d ",n->data);	
	}
	printf("\n");
}

//	访问
bool access_list(Node* head,size_t index,TYPE* data)
{
	int i = 0;
	for(Node* n = head; n; n=n->next,i++)
	{
		if(i == index) 
		{
			*data = n->data;
			return true;
		}
	}
	return false;
}

//	排序
void sort_list(Node* head)
{
	for(Node* i=head; i->next; i=i->next)
	{
		for(Node* j=i->next; j; j=j->next)
		{
			if(j->data < i->data)
			{
				TYPE temp = j->data;
				j->data = i->data;
				i->data = temp;
			}
		}
	}
}

//	按位置删除
bool del_index_list(Node** head,size_t index)
{
	if(0 == index)
	{
		Node* temp = *head;
		*head = temp->next;
		free(temp);
		return true;
	}

	Node* n = *head;
	for(int i=1; n->next; n=n->next,i++)
	{
		if(i == index)
		{
			Node* temp = n->next;
			n->next = temp->next;
			free(temp);
			return true;
		}
	}
	return false;
	/*
	while(--index)
	{
		n = n->next;
		if(NULL == n) return false;
	}

	if(NULL == n->next) return false;
	Node* temp = n->next;
	n->next = temp->next;
	free(temp);
	*/
	return true;
}


int main(int argc,const char* argv[])
{
	Node* head = create_node(10);

	for(int i=0; i<5; i++)
	{
		add_head_list(&head,i+1);	
	}
	show_list(head);
	del_value_list(&head,100);
	show_list(head);
	int num = 0;
	access_list(head,20,&num);
	printf("num=%d\n",num);
	sort_list(head);
	show_list(head);
	del_index_list(&head,2);
	show_list(head);

	/*	理解链表的本质
	Node* n1 = create_node(10);
	Node* n2 = create_node(20);
	Node* n3 = create_node(30);
	Node* n4 = create_node(40);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	for(Node* n=n1; n; n = n->next)
	{
		printf("%d ",n->data);	
	}
	*/
}



