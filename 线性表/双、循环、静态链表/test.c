#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

////˫������ͷ��㣩
//typedef struct DNode {
//	int data;
//	struct DNode* prior, * next;
//}DNode,*DLinkList;
//
//int InitDLinkList(DLinkList* L)  //��ʼ��
//{
//	*L = (DNode*)malloc(sizeof(DNode));
//	if (*L == NULL)
//	{
//		return -1;
//	}
//	(*L)->next = NULL;		//��ʱ��û����һ�����
//	(*L)->prior = NULL;		//ͷ����prior��Զָ��NULL
//	return 1;
//}
////���Ҫ�жϸ������Ƿ�Ϊ�գ�ֱ���ж�ͷ����nextָ��
//
////��p���֮�����s
//int InsertNextDNode(DNode* s, DNode* p)
//{
//	s->next = p->next;
//	if (p->next != NULL) //����������һ�����
//	{
//		(p->next)->prior = s; //��Ҫ����
//	}
//	p->next = s;
//	s->prior = p;
//}
//
////˫�����ɾ��
////ɾ��p���ĺ�̽��q
//int DeleteNextDNode(DNode* p)
//{
//	if (p == NULL)
//	{
//		return -1;
//	}
//	DNode* q = p->next; //�ҵ�p�ĺ�̽ڵ�q
//	if (q == NULL)
//	{
//		return -1;
//	}
//	p->next = q->next;
//	if (q->next != NULL) //q�������һ�����
//	{
//		(q->next)->prior = p;
//	}
//	free(q); //��qָ����ǿ�ռ��ͷŵ�
//	return 1;
//}
//
////���ٲ���
//void DestoryList(DLinkList* L)
//{
//	while ((*L)->next != NULL)
//	{
//		DeleteNextDNode((*L)); //ÿһ�ζ�ɾ��ͷ�ڵ�ĺ�̽��
//	}
//	free(L); //�ͷ�ͷ���
//}
//
//
//
//int main()
//{
//	DLinkList L;
//	InitDLinkList(&L);
//	return 0;
//}
//˫�����������ȡ����λ���ң���ֵ���Ҷ�ֻ��ͨ�������ķ�����ʱ�临�Ӷ�O��n��



//ѭ������ 
//1.ѭ�������� ����������һ��ָ��ָ��ͷ���
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node,*LinkList;
//
//int InitList(LinkList* L)
//{
//	(*L) = (Node*)malloc(sizeof(Node));//����һ��ͷ���
//	if (L == NULL)
//	{
//		return -1;
//	}
//	(*L)->next = (*L);
//	return 1;
//}
// �ж�p����Ƿ�Ϊ��L�����һ����㣬ֻ��Ҫ�ж�p��nextָ���Ƿ�ָ��ͷ���
// ѭ����������Դ�һ�����������ҵ���������һ�����

//2.ѭ��˫����
//��ͷ����priorָ���β
//��β����nextָ��ͷ���

//typedef struct DNode {
//	int data;
//	struct DNode* prior, * next;
//}DNode,*DLinkList;
//
//int InitDLinkList(DLinkList* L)  //��ʼ��
//{
//	*L = (DNode*)malloc(sizeof(DNode));
//	if (*L == NULL)
//	{
//		return -1;
//	}
//	(*L)->next = (*L);		//��ʱ��û����һ�����
//	(*L)->prior = (*L);		//ͷ����prior��Զָ��NULL
//	return 1;
//}
//�ж�p����Ƿ�Ϊ���һ����㣬ֻ��Ҫ���ý���nextָ���ǲ���ͷָ��

//��̬����
//����������������ڴ��������岼��ɢ������
//��̬��������һ��Ƭ�����Ŀռ䣬������㼯�а���
//struct Node {
//	int data;	//�������Ԫ��
//	int next	//��һ��Ԫ�ص������±�
//};
//�ŵ㣺��ɾ��������Ҫ�ƶ�����Ԫ��
//ȱ�㣺���������ȡ��ֻ�ܴ�ͷ��㿪ʼ����������ң������̶�����
//ʹ�ó�������֧��ָ��ĵͼ����ԣ�����Ԫ�������̶�����ĳ����������ϵͳ���ļ������FAT��



