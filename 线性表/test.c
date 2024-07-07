#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


//˳����ʵ��    ��̬����
//#define MaxSize  10 //������󳤶�
//typedef struct {
//	ElemType data[MaxSize];  //�þ�̬������������Ԫ��
//	int length;				//˳���ĵ�ǰ����
//}Sqlist;

//#define MaxSize  10 //������󳤶�
//typedef struct {
//	int data[MaxSize];  //�þ�̬������������Ԫ��
//	int length;				//˳���ĵ�ǰ����
//}Sqlist;
//
////��������------��ʼ��һ��˳���
//void InitList(Sqlist* L) 
//{
//	int i = 0;
//	for (i = 0; i < MaxSize; i++)
//	{
//		L->data[i] = 0;			//������Ԫ�س�ʼ��Ϊ0
//	}
//	L->length = 0;				//˳����ʼ����Ϊ0������ʡ��
//}
////�����ʼ����ʱ�򲻰�������ÿ��Ԫ�س�ʼ��Ϊ0����Υ��ֱ��ʹ�����飨���粻���жϱ���ֱ�Ӵ�ӡ L->data[x]����ʱ��
////�ڴ��п��ܻ���������������


//˳����ʵ��   ��̬����
//#define InitSize 10 //˳���ĳ�ʼ����
//typedef struct 
//{
//	ElemType* data;  //ָʾ��̬���������ָ��
//	int MaxSize;     //˳�����������
//	int length;		 //˳���ĵ�ǰ����
//}Sqlist;

//    malloc  ��  free ����ʵ�ֶ�̬��������ͷ��ڴ�ռ�
//    L->data=ElemType*) malloc (sizeof(ElemType)*InitSize)
//	  malloc���ٵ���һ�������Ŀռ䣬����ֵ����������ռ����ʼ��ַ
//	  realloc����Ҳ�У�Ҳ��ʵ��

//˳�����ص�
//1.�������    ��������O��1��ʱ�临�Ӷ����ҵ���i��Ԫ��
//2.�洢�ܶȸ�  ÿ���ڵ�ֻ�洢����Ԫ��
//3.��չ���������㣨��ʹ���ö�̬���䣬����չ����ʱ��ʱ�临�Ӷ�Ҳ�ϸߣ�
//4.���롢ɾ�����������㣬��Ҫ�ƶ�������Ԫ��

#define InitSize 10 //˳���ĳ�ʼ����
typedef struct 
{
	int* data;  //ָʾ��̬���������ָ��
	int MaxSize;     //˳�����������
	int length;		 //˳���ĵ�ǰ����
}Sqlist;

void InitList(Sqlist* L)
{
	//��malloc����һ���������ڴ�ռ�
	L->data = (int*)malloc(sizeof(int) * InitSize);
	L->length = 0;
	L->MaxSize = InitSize;
}
//��̬��������ĳ���
void IncreaseSize(Sqlist* L,int len)
{
	int i = 0;
	int* p = L->data;
	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
	for (i = 0; i < L->length; i++)
	{
		L->data[i] = p[i];   //�����ݸ��Ƶ��µ�����
	}
	L->MaxSize = L->MaxSize + len;
	free(p);
}

//˳���Ļ�������---����
//ListInsert��&L��i,e��:����������ڱ��еĵ�i��λ�ò���ָ����Ԫ��e

int ListInsert(Sqlist* L, int i, int e) //����ʧ�ܷ���-1 �ɹ����� 1 
{
	int j = 0;
	//�ж�i�ķ�Χ�Ƿ�Ϸ��ͱ��Ƿ��Ѿ�����
	// i > L->length + 1 ˵�������λ�ò��Ϸ����м���п�λ�ã����Ա���������ŵģ�
	if (i<1 || i>L->length+1 || L->length>=L->MaxSize)
	{
		return -1;
	}
	//1 2 3 4 5 6 7 8
	for (j = L->length; j >= i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return 1;

} 


//˳���Ļ�������---ɾ��
//ListDelete��&L��i,&e��:ɾ��������ɾ��˳����е�i��λ�õ�Ԫ�أ������ñ���e���ر�ɾ����Ԫ��

int ListDelete(Sqlist* L, int i, int* e)
{
	int j = 0;
	if (i<1 || i>L->length)
	{
		return -1;
	}
	*e = L->data[i - 1];
	for (j = i; j < L->length; j++)
	{
		L->data[j - i] = L->data[j];
	}
	L->length = L->length - 1;
	return 1;
}

//���Ա�Ļ�������   ��λ����
//GetElem��L,i������λ���� ��ȡ��L�е�i��λ�õ�Ԫ�ص�ֵ

int GetElem(Sqlist L, int i)
{
	//�ж�i�ķ�Χ�Ƿ�Ϸ�
	if (i<1 || i>L.length)
	{
		return -1;
	}
	return L.data[i - 1];
}

//���Ա�Ļ�������   ��ֵ����
//LocateElem��L��e������ֵ���ң��ڱ��в���ָ������ ����λ��
int LocateElem(Sqlist L, int e)
{
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			return i+1;
		}
	}
	return -1;
}

int main()
{
	Sqlist L;			 //����һ��˳���
	InitList(&L);		//��ʼ��˳���


	//IncreaseSize(&L, 5);
	//printf("%d\n",L.MaxSize); //��֤�Ƿ����ӳɹ�
	int ret = ListInsert(&L, 1, 5);
	//int e = 0;
	//ret = ListDelete(&L, 1, &e);
	//printf("Ҫ���ҵ�ֵΪ%d\n", GetElem(L,1));
	//printf("λ��=%d\n",LocateElem(L,5));
	return 0;
}

//������Ľ���   
// 1. ��ʼ��һ��������
// 2. ÿ��ȡһ������Ԫ�أ����뵽��ͷ���߱�β��ͷ�巨��β�巨�� 



//int main()
//{
//
//	return 0;
//}