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
}LNode,*LinkList;



//��ʼ��һ��������---����ͷ���ĵ�����
void InitList(LNode** L)
{
	*L = NULL; //�ձ� ��ʱû���κν��,
}
//�Բ���ͷ���ĵ���������пղ������ǣ���ָ��ͷ������ָ���ǲ���NULL

//���׵�д��
//void InitList(LinkList* L)
//{
//	*L = NULL; 
//}


//��ʼ��һ��������-----��ͷ���ĵ�����
//int InitList(LNode** L) //ͷ��㲻�洢����
//{
//	*L = (LNode*)malloc(sizeof(LNode));
//	if (L == NULL)
//	{
//		return -1;
//	}
//	(*L)->next = NULL;
//	return 1;
//}
//�Դ�ͷ���ĵ���������пղ��������ǿ���ͷ����nextָ���Ƿ�Ϊ�ա�
//���Ϊ�գ���ô���������û�д洢����
//����ͷ����Ժ�д����Ƚ��鷳

//��λ����루����ͷ��㣩,�ڱ�ĵ�i��λ�ò���Ԫ��e

int ListInsert(LNode** L, int i, int e) //����ɹ�������1������ʧ�ܷ���-1
{
	if (i < 1)
	{
		return -1;
	}
	if (i == 1) //�������һ��λ�ò壬ֱ�� �½���㣬���½���nextָ��ԭ���ĵ�һ������λ��
	{			
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = *L;
		*L = s;
		return 1;
	}

	LNode* p=*L;
	int j = 1;
	for (j = 1; j < i - 1; j++) //ѭ���ҵ���i-1�����
	{
		p = p->next;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	*L = s;




}


//��λ����루��ͷ��㣩,�ڱ�ĵ�i��λ�ò���Ԫ��e
//int ListInsert(LNode** L,int i,int e) //����ɹ�������1������ʧ�ܷ���-1
//{
//	if (i < 1)
//	{
//		return -1;
//	}
//
//	LNode* p=*L;
//	int j = 0; // ָ��ǰָ����ǵڼ������
//
//	for (j = 0; p != NULL && j < i - 1; j++) //ѭ�������ҵ���i-1�����
//	{
//		p = p->next;
//	}
//	if (p == NULL)//���Ϸ�
//	{
//		return -1;
//	}
//
//	LNode* s = (LNode*)malloc(sizeof(LNode)); //�½�һ�����
//	s->data = e;
//	s->next = p->next;
//	p->next = s;		//��������ӵ�p֮��
//	return 1;
//}

int main()
{
	LNode* L; //����ָ��һ���������ָ��
	InitList(&L);//����ʼ������Ϊ��ֹLָ��Ŀռ��������ݣ�Ҫ�޸�L������Ҫ��L�ĵ�ַ����ȥ

	ListInsert(&L,1,5);

	int i = (*L).data;
	printf("%d\n",i);

	//���׵�д��
	//LinkList L;
	//InitList(&L);

	return 0;
}