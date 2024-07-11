#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//用链式存储结构实现的线性表叫链表
//在顺序表中，每个结点只存放数据元素
//在单链表中，每个结点除了存放数据元素外 还要存储指向下一个结点的指针
//优点：1.不需要大片连续空间 2.改变容量方便
//缺点：1.不可随机存取		 2.需要耗费一定的空间存储指针

//定义一个单链表
//struct LNode {
//	ElemType data; //每个结点存放一个数据元素
//	struct LNode* next; //指针指向下一个结点
//};
//struct LNode* p = (struct LNode*)malloc(sizeof(struct LNode))


//为了更方便的使用，可以考虑使用如下写法
//typedef struct LNode {
//	ElemType data; //每个结点存放一个数据元素
//	struct LNode* next; //指针指向下一个结点
//}LNode,*LNode;
////这种写法等价于在第一种写法后加了两句
//typedef struct LNode LNode;
//typedef struct LNode* LinkList;

//要表示一个单链表时，只需声明一个头指针L，指向单链表的第一个结点
//LNode* L   //声明一个指向单链表第一个结点的指针
//LinkList L //声明一个指向单链表第一个结点的指针
//第二种写法代码可读性更强一点


typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化一个单链表---不带头结点的单链表
//void InitList(LinkList* L)
//{
//	*L = NULL; //空表 暂时没有任何结点,
//}
//对不带头结点的单链表进行判空操作就是，看指向头结点这个指针是不是NULL

//进阶的写法
void InitList(LinkList* L)
{
	*L = NULL; 
}


//按位序插入（不带头结点）,在表的第i个位置插入元素e
int ListInsert(LinkList* L, int i, int e) //插入成功，返回1，插入失败返回-1
{
	if (i < 1)
	{
		return -1;
	}
	LNode* p = *L;
	int j = 1;

	for (j = 1; j < i - 1; j++) //循环找到第i-1个结点
	{
		p = p->next;
	}

	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	if (j == 1)
	{
		s->next = p;
		*L = s;
	}

	else if(j!=1)
	{
		s->next = p->next;
		(*p).next = s;	
	}
	return 1;
}

int main()
{
	LinkList L; //声明指向一个单链表的指针
	InitList(&L);//做初始化是因为防止L指向的空间有脏数据，要修改L，所以要把L的地址传过去
	//进阶的写法
	//LinkList L;
	//InitList(&L);

	ListInsert(&L, 1, 5);
	printf("%d\n", L->data);
	ListInsert(&L, 2, 5);
	printf("%d\n", (L->next)->data);

	
	return 0;
}