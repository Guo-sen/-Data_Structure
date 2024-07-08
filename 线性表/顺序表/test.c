#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>




//顺序表的实现方式	------静态分配

//#define MaxSize 10	//定义最大长度
//typedef struct {
//	ElemType data[MaxSize]; //用静态的“数组”存放数据元素
//	int length;				//顺序表的当前长度
//}Sqlist;


//#define MaxSize 10	//定义最大长度
//typedef struct {
//	int data[MaxSize]; //用静态的“数组”存放数据元素
//	int length;				//顺序表的当前长度
//}Sqlist;
//
//void InitList(Sqlist* L)
//{
//	int i = 0;
//	for (i = 0; i < MaxSize; i++)
//	{
//		L->data[i] = 0;			//把数据中每一个元素初始化为0
//								//若不初始化，在违规使用（直接打印第几个元素，越过length限制）顺序表时，
//								//内存中可能会有脏数据存在
//	}
//	L->length = 0;
//}
//
//int main()
//{
//	Sqlist L;	  //声明一个顺序表
//	InitList(&L); //初始化顺序表
//
//	return 0;
//}
//静态存储的顺序表，表长一旦确定就无法更改






//顺序表的实现方式	------动态分配（malloc free）
//#define InitSize 10	//顺序表的初始长度
//typedef struct {
//	ElemType* data; //指示动态分配数组的指针
//	int MaxSize;	//顺序表的最大容量
//	int length;		//顺序表的当前长度
//}Sqlist;
//L.data=（ElemType*）malloc（sizeof（ElemType）*InitSize）；

#define InitSize 10	//顺序表的初始长度
typedef struct {
	int* data; //指示动态分配数组的指针
	int MaxSize;	//顺序表的最大容量
	int length;		//顺序表的当前长度
}Sqlist;

//顺序表的基本操作---初始化操作
void InitList(Sqlist* L)
{
	L->data = (int*)malloc(sizeof(int) * InitSize);
	L->length = 0;
	L->MaxSize = InitSize;
}

//扩容
void IncreaseSize(Sqlist* L, int len)
{
	int i = 0;
	int* p = L->data;
	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int)); 
	for (i = 0; i < L->length; i++)
	{
		L->data[i] = p[i];	//将旧的数据复制到新的区域
	}
	L->MaxSize = L->MaxSize + len; //将顺序表的最大长度增加len
	free(p);
}

//顺序表的基本操作---插入,往表i的位置插入元素e
int ListInsert(Sqlist* L, int i, int e) //插入成功返回1，失败返回-1
{
	int j = 0;
	if (i<1 || i>L->length + 1)	//判断i的范围是否合法，注意不能导致数据不连续存储
	{
		return -1;
	}
	if (L->length >= L->MaxSize) //判断内存是否满了
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

//顺序表的基本操作---删除，删除第i个元素，并用e把删除的元素带回来
int ListDelete(Sqlist* L, int i, int* e) //删除成功返回1，失败返回-1
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


//顺序表的基本操作-----查找（1.按位查找 2.按值查找）
int GetElem(Sqlist L, int i) //按位查找，返回位序为1的元素
{
	if (i<1 || i>L.length)
	{
		return -9999;			//查找失败，返回-9999
	}
	return L.data[i - 1];
}


int LocateElem(Sqlist L, int e) //按值查找，返回位序
{
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		if (e == L.data[i])
		{
			return (i + 1);
		}
	}
	return 0;//返回0，查找失败，表中无此元素
}

int main()
{
	int ret = 0;
	Sqlist L;	  //声明一个顺序表
	InitList(&L); //初始化顺序表

	//printf("%d\n", L.MaxSize);
	IncreaseSize(&L, 5);	//(增加长度，通过对比调用前后表厂确定是否扩容成功)
	//printf("%d\n", L.MaxSize);

	ListInsert(&L, 1, 5);
	//printf("%d\n", L.data[0]); //判断是否插入成功和插入

	ListInsert(&L, 1, 2);
	ListDelete(&L, 1, &ret);
	printf("要删除的元素为%d\n",ret);
	printf("删除后该位置的元素为%d\n",L.data[0]);

	printf("按位查找：第1位的元素是%d\n", GetElem(L,1));
	printf("按位查找：5在表中的第%d位\n", LocateElem(L,5));

	return 0;
}
//realloc也可以实现动态分配创建顺序表
//顺序表的特点
//1.随机访问			能在O（1）时间复杂度内找到第i个元素
//2.存储密度高
//3.扩展容量不方便
//4.插入删除不方便



//int main()
//{
//
//	return 0;
//}
