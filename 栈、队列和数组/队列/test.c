#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>

//���У�queue���Ļ�������
//������ֻ������һ�˽��в��룬����һ�˽���ɾ�������Ա�

//������������(ֻ���ڶ�β)
//ɾ�����������ӣ�ֻ���ڶ�ͷ��

//���е��ص㣺�Ƚ��ȳ���FIFO��
//First In First Out

//��Ҫ�����ͷ����β���ն���
// 



//���е�˳��ʵ��
//#define MaxSize 10
//typedef struct {
//	int data[MaxSize]; //�þ�̬�����Ŷ���Ԫ��
//	int front,rear;	   //��ͷָ��Ͷ�βָ��
//}SqQueue;             //Sq��squence----˳��
//
////��ʼ������
//void InitQueue(SqQueue* q)
//{
//	//�� ��ͷָ�� �� ��βָ�� ���г�ʼ��
//	q->front = 0;
//	q->rear = 0;
//}
////�ж϶����Ƿ�Ϊ�տ��Կ����еĶ�ͷָ��Ͷ�βָ���Ƿ����
//
////���
//int EnQueue(SqQueue* q, int x)
//{
//	if ((q->rear+1)% MaxSize==q->front)
//	{
//		return -9999;
//	}
//	q->data[q->rear] = x;
//	q->rear=((q->rear)+1)%MaxSize;  //�����ԵĽṹ���߼��ϱ���˻�״
//									//���ֶ��н���ѭ������
//	return 1;
//}
////����������������	����βָ�����һ��λ���Ƕ�ͷ������
////(q.rear+1)%MaxSize==q.front
//
////����
//int DeQueue(SqQueue* q, int* x)
//{
//	if (q->front == q->rear)	//�ж϶����Ƿ�Ϊ��
//	{
//		return -9999;
//	}
//
//	*x = q->data[q->front];
//	q->front = (q->front + 1) % MaxSize; //�ö�ͷָ����ƶ�
//}
//
//int main()
//{
//	SqQueue Q;
//	InitQueue(&Q);
//
//	EnQueue(&Q, 5);
//	printf("��Ӳ���%d\n", Q.data[Q.front]);
//
//	int x;
//	DeQueue(&Q, &x);
//	printf("���Ӳ���%d\n", x);
//
//	return 0;
//}
//����ͨ��ֻ��Ҫ���ض�ͷԪ��

//����Ԫ�ظ���
//��reat+MaxSize-front��%MaxSize

//�����Բ�����һ�ַ���������� ���ж϶����Ƿ�����ֱ�ӿ�size
//typedef struct {
//	int data[MaxSize]; //�þ�̬�����Ŷ���Ԫ��
//	int front, rear;	   //��ͷָ��Ͷ�βָ��
//	int size;         //��¼���г���
//}SqQueue;

//�����Բ�����һ�ַ����������
//typedef struct {
//	int data[MaxSize]; //�þ�̬�����Ŷ���Ԫ��
//	int front, rear;	   //��ͷָ��Ͷ�βָ��
//	int tag          //��¼���һ�ζԶ��еĲ����ǳ��ӻ������
//}SqQueue;

//ֻ��ɾ�������ſ��ܶӿգ�ֻ�в���ſ��ܶ���
//����������rear==front&&tag==1
//�ӿ�������front==rear&&tag==0




//���е���ʽʵ��
//typedef struct LinkNode {	//��ʽ���еĽ��
//	int data;
//	struct LinkNode* next;
//}LinkNode;
//
//typedef struct {	//��ʽ����
//	LinkNode* front;
//	LinkNode* rear; //��ͷָ��Ͷ�βָ��
//}LinkQueue;
//
////��ʼ������ͷ��㣩
//void InitQueue(LinkQueue* q)
//{
//	//��ʼ��ʱ��ͷָ���βָ�붼ָ��ͬһ�����
//	q->front=q->rear = (LinkNode*)malloc(sizeof(LinkNode));
//	(q->front)->next = NULL;
//}
////�Դ�ͷ������ʽ���У��ж��Ƿ�ΪNULL�������ж�ͷָ���βָ���Ƿ�ָ��ͬһ�����
////										Ҳ���Կ�ͷ����nextָ���Ƿ�Ϊ��
//
////����ͷ���
////void InitQueue(LinkQueue* q)
////{
////	q->front = NULL;
////	q->rear = NULL;
////}
////�жϲ���ͷ������ʽ�����Ƿ��ǿձ����Զ�ͷָ������жϿ����Ƿ�Ϊ�ձ�
//
////��ӣ���ͷ��㣩
////void EnQueue(LinkQueue* q, int x)
////{
////	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
////	s->data = x;
////	s->next = NULL;
////	(q->rear)->next = s; //�½����뵽rear֮��
////	q->rear = s;		//�޸ı�βָ��
////
////}
//
////��� ����ͷ���
//void EnQueue(LinkQueue* q, int x)
//{
//	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
//	s->data = x;
//	s->next = NULL;
//	if (q->front == NULL)
//	{
//		q->front = s;	//�ڽ��Ŀն����в����һ��Ԫ��
//		q->rear = s;	//�޸Ķ�ͷ��βָ��
//	}					//����ͷ������ʽ�������ʱ�򣬵�һ��Ԫ�����ʱ��Ҫ�ر���
//	else
//	{
//		(q->rear)->next = s;
//		 q->rear = s;
//	}
//
//}
//
////���Ӳ���(��ͷ���)
//int DeQueue(LinkQueue* q, int* x)
//{
//	if (q->front == q->rear)
//	{
//		return -999;
//	}
//	LinkNode* p = (q->front)->next;
//	*x = q->rear->data;
//	q->front->next = p->next; //�޸�ͷ����nextָ��
//	if (q->rear == p) //�˴������һ��������
//	{
//		q->rear = q->front;
//	}
//	free(p);
//	return 1; 
//}
//
////���Ӳ���(����ͷ���)
////int DeQueue(LinkQueue* q, int* x)
////{
////	if (q->front == NULL)
////	{
////		return -999;
////	}
////	LinkNode* p = q->front;
////	*x = q->rear->data;
////	q->front = p->next; //�޸�ͷ����nextָ��
////	if (q->rear==p) //�˴������һ��������
////	{
////		q->rear = NULL;
////		q->front = NULL;
////	}
////	free(p);
////	return 1;
////}
//
////��ʽ����һ�㲻�����������ڴ治��
//
//
//int main()
//{
//	LinkQueue Q;
//	InitQueue(&Q);
//
//	return 0;
//}


//˫�˶��У���������˲��룬Ҳ���������ɾ��
//�������޵�˫�˶��У�ֻ�����һ�˲��룬����ɾ���Ķ���
//������޵�˫�˶��У�ֻ��������˲��룬һ��ɾ���Ķ���
//���㣺�ж�������е�˫�˶���

