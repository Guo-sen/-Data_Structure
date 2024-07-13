#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

////双链表（带头结点）
//typedef struct DNode {
//	int data;
//	struct DNode* prior, * next;
//}DNode,*DLinkList;
//
//int InitDLinkList(DLinkList* L)  //初始化
//{
//	*L = (DNode*)malloc(sizeof(DNode));
//	if (*L == NULL)
//	{
//		return -1;
//	}
//	(*L)->next = NULL;		//暂时还没有下一个结点
//	(*L)->prior = NULL;		//头结点的prior永远指向NULL
//	return 1;
//}
////如果要判断该链表是否为空，直接判断头结点的next指针
//
////在p结点之后插入s
//int InsertNextDNode(DNode* s, DNode* p)
//{
//	s->next = p->next;
//	if (p->next != NULL) //如果不是最后一个结点
//	{
//		(p->next)->prior = s; //不要忘记
//	}
//	p->next = s;
//	s->prior = p;
//}
//
////双链表的删除
////删除p结点的后继结点q
//int DeleteNextDNode(DNode* p)
//{
//	if (p == NULL)
//	{
//		return -1;
//	}
//	DNode* q = p->next; //找到p的后继节点q
//	if (q == NULL)
//	{
//		return -1;
//	}
//	p->next = q->next;
//	if (q->next != NULL) //q不是最后一个结点
//	{
//		(q->next)->prior = p;
//	}
//	free(q); //把q指向的那块空间释放掉
//	return 1;
//}
//
////销毁操作
//void DestoryList(DLinkList* L)
//{
//	while ((*L)->next != NULL)
//	{
//		DeleteNextDNode((*L)); //每一次都删除头节点的后继结点
//	}
//	free(L); //释放头结点
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
//双链表不可随机存取，按位查找，按值查找都只能通过遍历的方法。时间复杂度O（n）



//循环链表 
//1.循环单链表 单链表的最后一个指针指向头结点
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node,*LinkList;
//
//int InitList(LinkList* L)
//{
//	(*L) = (Node*)malloc(sizeof(Node));//分配一个头结点
//	if (L == NULL)
//	{
//		return -1;
//	}
//	(*L)->next = (*L);
//	return 1;
//}
// 判断p结点是否为表L的最后一个结点，只需要判断p的next指针是否指向头结点
// 循环单链表可以从一个结点出发，找到其他任意一个结点

//2.循环双链表
//表头结点的prior指向表尾
//表尾结点的next指向头结点

//typedef struct DNode {
//	int data;
//	struct DNode* prior, * next;
//}DNode,*DLinkList;
//
//int InitDLinkList(DLinkList* L)  //初始化
//{
//	*L = (DNode*)malloc(sizeof(DNode));
//	if (*L == NULL)
//	{
//		return -1;
//	}
//	(*L)->next = (*L);		//暂时还没有下一个结点
//	(*L)->prior = (*L);		//头结点的prior永远指向NULL
//	return 1;
//}
//判断p结点是否为最后一个结点，只需要看该结点的next指针是不是头指针

//静态链表
//单链表：各个结点在内存中星罗棋布，散落天涯
//静态链表：分配一整片连续的空间，各个结点集中安置
//struct Node {
//	int data;	//存放数据元素
//	int next	//下一个元素的数组下标
//};
//优点：增删操作不需要移动大量元素
//缺点：不能随机存取，只能从头结点开始依次往后查找；容量固定不变
//使用场景：不支持指针的低级语言；数据元素数量固定不变的场景（如操作系统的文件分配表FAT）



