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


//����һ�����
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��һ��������-----��ͷ���ĵ�����
int InitList(LinkList* L) //ͷ��㲻�洢����
{
	*L = (LNode*)malloc(sizeof(LNode));
	if (*L == NULL)
	{
		return -1;
	}
	(*L)->next = NULL;
	return 1;
}
//�Դ�ͷ���ĵ���������пղ��������ǿ���ͷ����nextָ���Ƿ�Ϊ�ա�
//���Ϊ�գ���ô���������û�д洢����
//����ͷ����Ժ�д����Ƚ��鷳

//�������-----��ͷ���
// LinkList(&L,i,e):����������ڱ��еĵ�i��λ���ϲ���Ԫ��e
// ͷ��㲻�洢���ݣ�����ĵ�i��λ�ò��룬��Ҫ�ҵ���i-1����㣬���½�����ý��֮��
//�������Ƽ�ʹ�ô�ͷ���ķ�ʽ 

//����ָ��Ԫ��
int ListInsert(LinkList* L, int i, int e)
{
	int j = 0;
	if (i < 1) //�ж�i��λ���Ƿ�Ϸ���������Ϸ�����û��Ҫִ����ȥ��
	{
		return -1;
	}
	LNode* p = *L;
	for (j = 0; p != NULL && j < i-1; j++)
	{
		p = (*p).next;
	}
	//if (p == NULL) //i��ֵ���Ϸ�
	//{
	//	return -1;
	//}
	//LNode* s = (LNode*)malloc(sizeof(LNode));
	//s->data = e;
	//s->next = p->next;
	//(*p).next = s;
	//return 1;
	return InsertNextNode(&p, e); //������
}

//ָ������壺��p���֮�����e
int InsertNextNode(LNode** p, int e)
{
	if (p == NULL)
	{
		return -1;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) //����ڴ�����ʧ��
	{
		return -1;
	}

	s->data = e;
	s->next = (*p)->next;
	(*p)->next = s;
	return 1;
}

//��ָ�����֮ǰ����Ԫ��e
int InsertPriorNode(LNode* p, int e)
{
	if (p == NULL)
	{
		return -1;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
	{
		return -1;
	}
	s->next = p->next;
	s->data = p->data;
	p->data = e;
	p->next = s;
	return 1;
}

//��λ��ɾ����ɾ����L�еĵ�i��λ�õ�Ԫ�أ�������e����ɾ��Ԫ�ص�ֵ
int ListDelete(LinkList* L, int i, int* e)
{
	if (i < 1)
	{
		return 9999; //����Ƿ�������9999
	}
	LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0;
	p = *L;
	for (j = 0; j < i - 1 && p != NULL; j++)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		return 9999; //i��ֵ���Ϸ�
	}
	if (p->next == NULL)
	{
		return 9999;  //��i-1�����֮���Ѿ�û���������
	}
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return 1;
}

//ɾ��ָ�����p
int DeleteLNode(LNode* p)
{
	if (p == NULL)
	{
		return 9999;
	}
	LNode* q = p->next;
	p->data = q->data;  //������bug�����Ҫɾ�����һ����� ��ʱp��NULL����NULL��ȡdataȡ������
	p->next = q->next;
	free(q);
}

//������Ĳ���  ��ֵ����  ��λ����

//��ֵ���ң��ҵ�����Ϊe�Ľ�㣬���ظý��ĵ�ַ
LNode* LocateElem(LinkList L, int e)
{
	LNode* p = L;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

//��λ����  ���ص�i��Ԫ��
LNode* GetElem(LinkList L, int i)
{
	if (i < 1 || L == NULL)
	{
		return NULL;
	}
	LNode* p;
	int j = 0;
	p = L;
	for (j = 0; p!=NULL&&j < i; j++)
	{
		p = p->next;
	}
	return p;
}

//���ĳ���
int Length(LinkList L)
{
	int len = 0;
	LNode* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		len += 1;
	}
	return len;
}

//β�巨����������
LinkList List_TailInsert()
{
	int x; //����ÿ�������Ԫ��������int
	LinkList L = (LinkList)malloc(sizeof(LNode)); //����ͷ���
	LNode* s, *end=L;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		end->next = s;
		end = s;
		scanf("%x", &x);
	}
	end->next = NULL;
	return L;
}

//ͷ�巨����������
LinkList List_HeadInsert()
{
	LNode* s;
	int x;
	LinkList L = (LinkList)malloc(sizeof(LNode)); //����ͷ���
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L; 
}


int main()
{
	LinkList L;
	//LNode* L 
	InitList(&L);

	ListInsert(&L,1,5);
	//printf("���е�1��Ԫ��Ϊ%d\n",(L->next)->data); //ͷ��㲻�洢����

	InsertPriorNode(L->next, 6);
	//printf("���е�1��Ԫ��Ϊ%d\n", (L->next)->data); 
	//printf("���е�2��Ԫ��Ϊ%d\n", (L->next)->next->data);



	/*int ret = ListDelete(&L, 1, &ret);
	printf("Ҫɾ����Ԫ��Ϊ%d\n", ret);*/
	printf("%d\n",Length(L));

	return 0;
}