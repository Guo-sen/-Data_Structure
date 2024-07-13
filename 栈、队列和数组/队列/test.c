#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>

//队列（queue）的基本概念
//队列是只允许在一端进行插入，在另一端进行删除的线性表

//插入操作：入队(只能在队尾)
//删除操作：出队（只能在对头）

//队列的特点：先进先出（FIFO）
//First In First Out

//重要术语：队头、队尾、空队列
// 



//队列的顺序实现
//#define MaxSize 10
//typedef struct {
//	int data[MaxSize]; //用静态数组存放队列元素
//	int front,rear;	   //队头指针和队尾指针
//}SqQueue;             //Sq：squence----顺序
//
////初始化队列
//void InitQueue(SqQueue* q)
//{
//	//对 队头指针 和 队尾指针 进行初始化
//	q->front = 0;
//	q->rear = 0;
//}
////判断队列是否为空可以看队列的队头指针和队尾指针是否相等
//
////入队
//int EnQueue(SqQueue* q, int x)
//{
//	if ((q->rear+1)% MaxSize==q->front)
//	{
//		return -9999;
//	}
//	q->data[q->rear] = x;
//	q->rear=((q->rear)+1)%MaxSize;  //把线性的结构在逻辑上变成了环状
//									//这种队列叫做循环队列
//	return 1;
//}
////队列已满的条件是	：队尾指针的下一个位置是队头，即：
////(q.rear+1)%MaxSize==q.front
//
////出队
//int DeQueue(SqQueue* q, int* x)
//{
//	if (q->front == q->rear)	//判断队列是否为空
//	{
//		return -9999;
//	}
//
//	*x = q->data[q->front];
//	q->front = (q->front + 1) % MaxSize; //让队头指针后移动
//}
//
//int main()
//{
//	SqQueue Q;
//	InitQueue(&Q);
//
//	EnQueue(&Q, 5);
//	printf("入队操作%d\n", Q.data[Q.front]);
//
//	int x;
//	DeQueue(&Q, &x);
//	printf("出队操作%d\n", x);
//
//	return 0;
//}
//查找通常只需要返回队头元素

//队列元素个数
//（reat+MaxSize-front）%MaxSize

//还可以采用另一种方案定义队列 ，判断队列是否满了直接看size
//typedef struct {
//	int data[MaxSize]; //用静态数组存放队列元素
//	int front, rear;	   //队头指针和队尾指针
//	int size;         //记录队列长度
//}SqQueue;

//还可以采用另一种方案定义队列
//typedef struct {
//	int data[MaxSize]; //用静态数组存放队列元素
//	int front, rear;	   //队头指针和队尾指针
//	int tag          //记录最近一次对队列的操作是出队还是入队
//}SqQueue;

//只有删除操作才可能队空，只有插入才可能队满
//队满条件：rear==front&&tag==1
//队空条件：front==rear&&tag==0




//队列的链式实现
//typedef struct LinkNode {	//链式队列的结点
//	int data;
//	struct LinkNode* next;
//}LinkNode;
//
//typedef struct {	//链式队列
//	LinkNode* front;
//	LinkNode* rear; //队头指针和队尾指针
//}LinkQueue;
//
////初始化（带头结点）
//void InitQueue(LinkQueue* q)
//{
//	//初始化时，头指针和尾指针都指向同一个结点
//	q->front=q->rear = (LinkNode*)malloc(sizeof(LinkNode));
//	(q->front)->next = NULL;
//}
////对带头结点的链式队列，判断是否为NULL，可以判断头指针和尾指针是否指向同一个结点
////										也可以看头结点的next指针是否为空
//
////不带头结点
////void InitQueue(LinkQueue* q)
////{
////	q->front = NULL;
////	q->rear = NULL;
////}
////判断不带头结点的链式队列是否是空表，可以对头指针进行判断看看是否为空表
//
////入队（带头结点）
////void EnQueue(LinkQueue* q, int x)
////{
////	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
////	s->data = x;
////	s->next = NULL;
////	(q->rear)->next = s; //新结点插入到rear之后
////	q->rear = s;		//修改表尾指针
////
////}
//
////入队 不带头结点
//void EnQueue(LinkQueue* q, int x)
//{
//	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
//	s->data = x;
//	s->next = NULL;
//	if (q->front == NULL)
//	{
//		q->front = s;	//在结点的空队列中插入第一个元素
//		q->rear = s;	//修改队头队尾指针
//	}					//不带头结点的链式队列入队时候，第一个元素入队时需要特别处理
//	else
//	{
//		(q->rear)->next = s;
//		 q->rear = s;
//	}
//
//}
//
////出队操作(带头结点)
//int DeQueue(LinkQueue* q, int* x)
//{
//	if (q->front == q->rear)
//	{
//		return -999;
//	}
//	LinkNode* p = (q->front)->next;
//	*x = q->rear->data;
//	q->front->next = p->next; //修改头结点的next指针
//	if (q->rear == p) //此次是最后一个结点出队
//	{
//		q->rear = q->front;
//	}
//	free(p);
//	return 1; 
//}
//
////出队操作(不带头结点)
////int DeQueue(LinkQueue* q, int* x)
////{
////	if (q->front == NULL)
////	{
////		return -999;
////	}
////	LinkNode* p = q->front;
////	*x = q->rear->data;
////	q->front = p->next; //修改头结点的next指针
////	if (q->rear==p) //此次是最后一个结点出队
////	{
////		q->rear = NULL;
////		q->front = NULL;
////	}
////	free(p);
////	return 1;
////}
//
////链式队列一般不会满，除非内存不足
//
//
//int main()
//{
//	LinkQueue Q;
//	InitQueue(&Q);
//
//	return 0;
//}


//双端队列：允许从两端插入，也允许从两端删除
//输入受限的双端队列：只允许从一端插入，两端删除的队列
//输出受限的双端队列：只允许从两端插入，一端删除的队列
//考点：判断输出序列的双端队列

