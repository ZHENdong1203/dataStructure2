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
	printf("������Ҫ������������:\n");
	scanf("%d", &n);
	printf("����������:\n");
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
}//����Ĵ���
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
}//���������
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
}//�������
int main()
{
	LNode *head;
	head = CreatList();
	printf("��������ǰ������:\n");
	OutList(head);
	head = ReverseList(head);
	printf("�������ú������:\n");
	OutList(head);
	system("pause");
	return 0;
}