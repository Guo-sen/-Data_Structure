#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//����ʽ�洢�ṹʵ�ֵ����Ա������
//��˳����У�ÿ�����ֻ�������Ԫ��
//�ڵ������У�ÿ�������˴������Ԫ���� ��Ҫ�洢ָ����һ������ָ��
//�ŵ㣺1.����Ҫ��Ƭ�����ռ� 2.�ı���������
//ȱ�㣺1.���������ȡ		 2.��Ҫ�ķ�һ���Ŀռ�洢ָ��

//����һ��������
//struct LNode {
//	ElemType data; //ÿ�������һ������Ԫ��
//	struct LNode* next; //ָ��ָ����һ�����
//};
//struct LNode* p = (struct LNode*)malloc(sizeof(struct LNode))


//Ϊ�˸������ʹ�ã����Կ���ʹ������д��
//typedef struct LNode {
//	ElemType data; //ÿ�������һ������Ԫ��
//	struct LNode* next; //ָ��ָ����һ�����
//}LNode,*LNode;
////����д���ȼ����ڵ�һ��д�����������
//typedef struct LNode LNode;
//typedef struct LNode* LinkList;

//Ҫ��ʾһ��������ʱ��ֻ������һ��ͷָ��L��ָ������ĵ�һ�����
//LNode* L   //����һ��ָ�������һ������ָ��
//LinkList L //����һ��ָ�������һ������ָ��
//�ڶ���д������ɶ��Ը�ǿһ��


typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��һ��������---����ͷ���ĵ�����
//void InitList(LinkList* L)
//{
//	*L = NULL; //�ձ� ��ʱû���κν��,
//}
//�Բ���ͷ���ĵ���������пղ������ǣ���ָ��ͷ������ָ���ǲ���NULL

//���׵�д��
void InitList(LinkList* L)
{
	*L = NULL; 
}


//��λ����루����ͷ��㣩,�ڱ�ĵ�i��λ�ò���Ԫ��e
int ListInsert(LinkList* L, int i, int e) //����ɹ�������1������ʧ�ܷ���-1
{
	if (i < 1)
	{
		return -1;
	}
	LNode* p = *L;
	int j = 1;

	for (j = 1; j < i - 1; j++) //ѭ���ҵ���i-1�����
	{
		p = p->next;
	}

	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	if (j == 1)
	{
		s->next = p;
		*L = s;
	}

	else if(j!=1)
	{
		s->next = p->next;
		(*p).next = s;	
	}
	return 1;
}

int main()
{
	LinkList L; //����ָ��һ���������ָ��
	InitList(&L);//����ʼ������Ϊ��ֹLָ��Ŀռ��������ݣ�Ҫ�޸�L������Ҫ��L�ĵ�ַ����ȥ
	//���׵�д��
	//LinkList L;
	//InitList(&L);

	ListInsert(&L, 1, 5);
	printf("%d\n", L->data);
	ListInsert(&L, 2, 5);
	printf("%d\n", (L->next)->data);

	
	return 0;
}