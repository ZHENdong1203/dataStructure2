#include <stdio.h>  
#include <stdlib.h>  
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode;
LNode *CreatList()
{
	int val, i, n;
	LNode *head, *p, *q;
	head = NULL;
	printf("请输入要建立的链表长度:\n");
	scanf("%d", &n);
	printf("请输入数据:\n");
	for (i = 0; i<n; ++i)
	{
		scanf("%d", &val);
		p = (LNode *)malloc(sizeof(LNode));
		p->data = val;
		if (NULL == head)
			q = head = p;
		else
			q->next = p;
		q = p;
	}
	p->next = NULL;
	return head;
}//链表的创建
LNode *ReverseList(LNode *head)
{
	LNode *p, *q, *r;
	p = head;
	q = r = NULL;
	while (p)
	{
		q = p->next;
		p->next = r;
		r = p;
		p = q;
	}
	return r;
}//链表的逆置
void OutList(LNode *head)
{
	LNode *p;
	p = head;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}//输出链表
int main()
{
	LNode *head;
	head = CreatList();
	printf("链表逆置前的数据:\n");
	OutList(head);
	head = ReverseList(head);
	printf("链表逆置后的数据:\n");
	OutList(head);
	system("pause");
	return 0;
}