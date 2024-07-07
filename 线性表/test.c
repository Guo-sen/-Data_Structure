#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


//顺序表的实现    静态分配
//#define MaxSize  10 //定义最大长度
//typedef struct {
//	ElemType data[MaxSize];  //用静态的数组存放数据元素
//	int length;				//顺序表的当前长度
//}Sqlist;

//#define MaxSize  10 //定义最大长度
//typedef struct {
//	int data[MaxSize];  //用静态的数组存放数据元素
//	int length;				//顺序表的当前长度
//}Sqlist;
//
////基本操作------初始化一个顺序表
//void InitList(Sqlist* L) 
//{
//	int i = 0;
//	for (i = 0; i < MaxSize; i++)
//	{
//		L->data[i] = 0;			//将所有元素初始化为0
//	}
//	L->length = 0;				//顺序表初始长度为0，不能省略
//}
////如果初始化的时候不把数组中每个元素初始化为0，在违规直接使用数组（例如不加判断表长，直接打印 L->data[x]）的时候，
////内存中可能会有遗留的脏数据


//顺序表的实现   动态分配
//#define InitSize 10 //顺序表的初始长度
//typedef struct 
//{
//	ElemType* data;  //指示动态分配数组的指针
//	int MaxSize;     //顺序表的最大容量
//	int length;		 //顺序表的当前长度
//}Sqlist;

//    malloc  和  free 可以实现动态的申请和释放内存空间
//    L->data=ElemType*) malloc (sizeof(ElemType)*InitSize)
//	  malloc开辟的是一块连续的空间，返回值是这块连续空间的起始地址
//	  realloc函数也行，也能实现

//顺序表的特点
//1.随机访问    即可以在O（1）时间复杂度内找到第i个元素
//2.存储密度高  每个节点只存储数据元素
//3.扩展容量不方便（即使采用动态分配，在扩展容量时，时间复杂度也较高）
//4.插入、删除操作不方便，需要移动大量的元素

#define InitSize 10 //顺序表的初始长度
typedef struct 
{
	int* data;  //指示动态分配数组的指针
	int MaxSize;     //顺序表的最大容量
	int length;		 //顺序表的当前长度
}Sqlist;

void InitList(Sqlist* L)
{
	//用malloc申请一块连续的内存空间
	L->data = (int*)malloc(sizeof(int) * InitSize);
	L->length = 0;
	L->MaxSize = InitSize;
}
//动态增加数组的长度
void IncreaseSize(Sqlist* L,int len)
{
	int i = 0;
	int* p = L->data;
	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
	for (i = 0; i < L->length; i++)
	{
		L->data[i] = p[i];   //将数据复制到新的区域
	}
	L->MaxSize = L->MaxSize + len;
	free(p);
}

//顺序表的基本操作---插入
//ListInsert（&L，i,e）:插入操作。在表中的第i个位置插入指定的元素e

int ListInsert(Sqlist* L, int i, int e) //插入失败返回-1 成功返回 1 
{
	int j = 0;
	//判断i的范围是否合法和表是否已经满了
	// i > L->length + 1 说明插入的位置不合法，中间会有空位置（线性表是连续存放的）
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


//顺序表的基本操作---删除
//ListDelete（&L，i,&e）:删除操作。删除顺序表中第i个位置的元素，用引用变量e返回被删除的元素

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

//线性表的基本操作   按位查找
//GetElem（L,i）：按位查找 获取表L中第i个位置的元素的值

int GetElem(Sqlist L, int i)
{
	//判断i的范围是否合法
	if (i<1 || i>L.length)
	{
		return -1;
	}
	return L.data[i - 1];
}

//线性表的基本操作   按值查找
//LocateElem（L，e）：按值查找，在表中查找指定数字 返回位序
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
	Sqlist L;			 //声明一个顺序表
	InitList(&L);		//初始化顺序表


	//IncreaseSize(&L, 5);
	//printf("%d\n",L.MaxSize); //验证是否增加成功
	int ret = ListInsert(&L, 1, 5);
	//int e = 0;
	//ret = ListDelete(&L, 1, &e);
	//printf("要查找的值为%d\n", GetElem(L,1));
	//printf("位序=%d\n",LocateElem(L,5));
	return 0;
}

//单链表的建立   
// 1. 初始化一个单链表
// 2. 每次取一个数据元素，插入到表头或者表尾（头插法或尾插法） 



//int main()
//{
//
//	return 0;
//}