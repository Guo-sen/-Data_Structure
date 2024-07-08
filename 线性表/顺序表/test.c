#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>




//˳����ʵ�ַ�ʽ	------��̬����

//#define MaxSize 10	//������󳤶�
//typedef struct {
//	ElemType data[MaxSize]; //�þ�̬�ġ����顱�������Ԫ��
//	int length;				//˳���ĵ�ǰ����
//}Sqlist;


//#define MaxSize 10	//������󳤶�
//typedef struct {
//	int data[MaxSize]; //�þ�̬�ġ����顱�������Ԫ��
//	int length;				//˳���ĵ�ǰ����
//}Sqlist;
//
//void InitList(Sqlist* L)
//{
//	int i = 0;
//	for (i = 0; i < MaxSize; i++)
//	{
//		L->data[i] = 0;			//��������ÿһ��Ԫ�س�ʼ��Ϊ0
//								//������ʼ������Υ��ʹ�ã�ֱ�Ӵ�ӡ�ڼ���Ԫ�أ�Խ��length���ƣ�˳���ʱ��
//								//�ڴ��п��ܻ��������ݴ���
//	}
//	L->length = 0;
//}
//
//int main()
//{
//	Sqlist L;	  //����һ��˳���
//	InitList(&L); //��ʼ��˳���
//
//	return 0;
//}
//��̬�洢��˳�����һ��ȷ�����޷�����






//˳����ʵ�ַ�ʽ	------��̬���䣨malloc free��
//#define InitSize 10	//˳���ĳ�ʼ����
//typedef struct {
//	ElemType* data; //ָʾ��̬���������ָ��
//	int MaxSize;	//˳�����������
//	int length;		//˳���ĵ�ǰ����
//}Sqlist;
//L.data=��ElemType*��malloc��sizeof��ElemType��*InitSize����

#define InitSize 10	//˳���ĳ�ʼ����
typedef struct {
	int* data; //ָʾ��̬���������ָ��
	int MaxSize;	//˳�����������
	int length;		//˳���ĵ�ǰ����
}Sqlist;

//˳���Ļ�������---��ʼ������
void InitList(Sqlist* L)
{
	L->data = (int*)malloc(sizeof(int) * InitSize);
	L->length = 0;
	L->MaxSize = InitSize;
}

//����
void IncreaseSize(Sqlist* L, int len)
{
	int i = 0;
	int* p = L->data;
	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int)); 
	for (i = 0; i < L->length; i++)
	{
		L->data[i] = p[i];	//���ɵ����ݸ��Ƶ��µ�����
	}
	L->MaxSize = L->MaxSize + len; //��˳������󳤶�����len
	free(p);
}

//˳���Ļ�������---����,����i��λ�ò���Ԫ��e
int ListInsert(Sqlist* L, int i, int e) //����ɹ�����1��ʧ�ܷ���-1
{
	int j = 0;
	if (i<1 || i>L->length + 1)	//�ж�i�ķ�Χ�Ƿ�Ϸ���ע�ⲻ�ܵ������ݲ������洢
	{
		return -1;
	}
	if (L->length >= L->MaxSize) //�ж��ڴ��Ƿ�����
	{
		return -1;
	}
	for (j = L->length; j >=i ; j--)
	{								          
		L->data[j] = L->data[j - 1];
	}
	L->data[i-1] = e;
	L->length++;
	return 1;
}

//˳���Ļ�������---ɾ����ɾ����i��Ԫ�أ�����e��ɾ����Ԫ�ش�����
int ListDelete(Sqlist* L, int i, int* e) //ɾ���ɹ�����1��ʧ�ܷ���-1
{
	int j = 0;
	if (i<1 || i>L->length)
	{
		return -1;
	}
	*e = L->data[i - 1];
	for (j = i; j <L->length ; j++)
	{
		L->data[i - 1] = L->data[i];
	}
	L->length--;
	return 1;
}


//˳���Ļ�������-----���ң�1.��λ���� 2.��ֵ���ң�
int GetElem(Sqlist L, int i) //��λ���ң�����λ��Ϊ1��Ԫ��
{
	if (i<1 || i>L.length)
	{
		return -9999;			//����ʧ�ܣ�����-9999
	}
	return L.data[i - 1];
}


int LocateElem(Sqlist L, int e) //��ֵ���ң�����λ��
{
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		if (e == L.data[i])
		{
			return (i + 1);
		}
	}
	return 0;//����0������ʧ�ܣ������޴�Ԫ��
}

int main()
{
	int ret = 0;
	Sqlist L;	  //����һ��˳���
	InitList(&L); //��ʼ��˳���

	//printf("%d\n", L.MaxSize);
	IncreaseSize(&L, 5);	//(���ӳ��ȣ�ͨ���Աȵ���ǰ���ȷ���Ƿ����ݳɹ�)
	//printf("%d\n", L.MaxSize);

	ListInsert(&L, 1, 5);
	//printf("%d\n", L.data[0]); //�ж��Ƿ����ɹ��Ͳ���

	ListInsert(&L, 1, 2);
	ListDelete(&L, 1, &ret);
	printf("Ҫɾ����Ԫ��Ϊ%d\n",ret);
	printf("ɾ�����λ�õ�Ԫ��Ϊ%d\n",L.data[0]);

	printf("��λ���ң���1λ��Ԫ����%d\n", GetElem(L,1));
	printf("��λ���ң�5�ڱ��еĵ�%dλ\n", LocateElem(L,5));

	return 0;
}
//reallocҲ����ʵ�ֶ�̬���䴴��˳���
//˳�����ص�
//1.�������			����O��1��ʱ�临�Ӷ����ҵ���i��Ԫ��
//2.�洢�ܶȸ�
//3.��չ����������
//4.����ɾ��������



//int main()
//{
//
//	return 0;
//}
