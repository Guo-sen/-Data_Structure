#include<stdio.h>
//ջ��stack����ֻ������һ�˽��в����ɾ�������Ա�

//��Ҫ����
//ջ������������ɾ����һ��
//ջ�ף�����������ɾ����һ��
//��ջ��ջ��û�д��κ����ݣ���Ӧ���Ա�Ŀձ�


//�ص㣺����ȳ�
// Last In Frist Out (LIFO)

//ջ�Ĳ����ɾ��ֻ����ջ��������ջ��һ�ֲ������޵����Ա�

//˳��ջ����˳��洢�ķ�ʽʵ�ֵ�ջ
//#define MaxSize 10		//����ջ�е�Ԫ�ص�������
//typedef struct {
//	int data[MaxSize];	//��̬������ջ�е�Ԫ��
//	int top;			//ջ��ָ�� 
//}SqStack;
//
////��ʼ������
//void InitStack(SqStack* s)
//{
//	(*s).top = -1;  //��ʼ��ջ��ָ��
//}
////�ж�һ��ջ�ǲ���NULL��ֻ��Ҫ��ջ��ָ���ǲ���-1
//
////��Ԫ����ջ
//int Push(SqStack* s, int x)
//{
//	if ((*s).top == MaxSize - 1) //ջ�� ����
//	{
//		return -999;
//	}
//	(*s).top = (*s).top + 1;	//ָ����+1
//	(*s).data[(*s).top] = x;	//��Ԫ����ջ
//	return 1;
//}
//
////��ջ����  ������ɾ 
//int Pop(SqStack* s, int* e)
//{
//	if (s->top == -1)
//	{
//		return -1; //ջ�� ����
//	}
//	*e = (*s).data[s->top]; //ջ��Ԫ�س�ջ
//	s->top -= 1;			//ָ��-1   
//	return 1;
//}
////���ݲ�û�������ı�ɾ���������ڴ��д�����ֻ���߼���ɾ����
//
////��ȡջ��Ԫ�صĲ���
//int GetTop(SqStack s, int* ret)
//{
//	if (s.top == -1)
//	{
//		return -9999;
//	}
//	*ret = s.data[s.top];
//	ret = 1;
//}
////
//
//
//int main()
//{
//	SqStack s; //����һ��˳��ջ
//	InitStack(&s);
//
//	Push(&s, 5);
//	//printf("%d\n", s.data[0]);
//
//	int ret = 0;
//
//	GetTop(s, &ret);
//	printf("��ȡջ������ȡ������%d\n", ret);
//
//	Pop(&s, &ret);
//	printf("��ջ����ȡ������%d\n", ret);
//
//	return 0;
//}
//˳��ջ��ȱ�㣺 ջ�Ŀռ� ��С���ɸı�

//����ջ
//#define MaxSize 10		//����ջ�е�Ԫ�ص�������
//typedef struct {
//	int data[MaxSize];	//��̬������ջ�е�Ԫ��
//	int top0;			//0��ջ��ָ�� 
//	int top1;			//1��ջ��ָ��
//}SqStack;
//
//void InitStack(SqStack* s)
//{
//	(*s).top0 = -1;  //��ʼ��ջ��ָ��
//	(*s).top1 = MaxSize;
//}
//���Ϸ����Ϳ���ʹ����ջ����ͬһƬ�ڴ�ռ�
//�жϿռ��Ƿ��������ݣ�top0+1=top1


//ջ����ʽ�洢ʵ��----��ջ

typedef struct Linknode {
	int data;				//������
	struct Linknode* next;	//ָ����
}*Listack;

//����ʵ�ַ�ʽ��1.��ͷ��� 2.����ͷ���
//����������������ʼ������������ջ����ɾ����ջ�����飨��ȡջ��Ԫ�أ����пպ�����






