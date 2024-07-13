#include<stdio.h>
//栈（stack）是只允许在一端进行插入或删除的线性表

//重要术语
//栈顶：允许插入和删除的一端
//栈底：不允许插入和删除的一端
//空栈：栈里没有存任何数据，对应线性表的空表


//特点：后进先出
// Last In Frist Out (LIFO)

//栈的插入和删除只能在栈顶操作，栈是一种操作受限的线性表

//顺序栈：用顺序存储的方式实现的栈
//#define MaxSize 10		//定义栈中的元素的最大个数
//typedef struct {
//	int data[MaxSize];	//静态数组存放栈中的元素
//	int top;			//栈顶指针 
//}SqStack;
//
////初始化操作
//void InitStack(SqStack* s)
//{
//	(*s).top = -1;  //初始化栈顶指针
//}
////判断一个栈是不是NULL，只需要看栈顶指针是不是-1
//
////新元素入栈
//int Push(SqStack* s, int x)
//{
//	if ((*s).top == MaxSize - 1) //栈满 报错
//	{
//		return -999;
//	}
//	(*s).top = (*s).top + 1;	//指针先+1
//	(*s).data[(*s).top] = x;	//新元素入栈
//	return 1;
//}
//
////出栈操作  类似于删 
//int Pop(SqStack* s, int* e)
//{
//	if (s->top == -1)
//	{
//		return -1; //栈空 报错
//	}
//	*e = (*s).data[s->top]; //栈顶元素出栈
//	s->top -= 1;			//指针-1   
//	return 1;
//}
////数据并没有真正的被删除，还在内存中存留，只是逻辑上删除了
//
////读取栈顶元素的操作
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
//	SqStack s; //声明一个顺序栈
//	InitStack(&s);
//
//	Push(&s, 5);
//	//printf("%d\n", s.data[0]);
//
//	int ret = 0;
//
//	GetTop(s, &ret);
//	printf("读取栈顶操作取得数据%d\n", ret);
//
//	Pop(&s, &ret);
//	printf("出栈操作取得数据%d\n", ret);
//
//	return 0;
//}
//顺序栈的缺点： 栈的空间 大小不可改变

//共享栈
//#define MaxSize 10		//定义栈中的元素的最大个数
//typedef struct {
//	int data[MaxSize];	//静态数组存放栈中的元素
//	int top0;			//0号栈顶指针 
//	int top1;			//1号栈顶指针
//}SqStack;
//
//void InitStack(SqStack* s)
//{
//	(*s).top0 = -1;  //初始化栈顶指针
//	(*s).top1 = MaxSize;
//}
//以上方法就可以使两个栈共享同一片内存空间
//判断空间是否满的依据：top0+1=top1


//栈的链式存储实现----链栈

typedef struct Linknode {
	int data;				//数据域
	struct Linknode* next;	//指针域
}*Listack;

//两种实现方式：1.带头结点 2.不带头结点
//基本操作：创（初始化）、增（进栈）、删（出栈）、查（获取栈顶元素）、判空和判满






