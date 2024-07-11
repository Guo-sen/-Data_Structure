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


//定义一个结点
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化一个单链表-----带头结点的单链表
int InitList(LinkList* L) //头结点不存储数据
{
	*L = (LNode*)malloc(sizeof(LNode));
	if (*L == NULL)
	{
		return -1;
	}
	(*L)->next = NULL;
	return 1;
}
//对带头结点的单链表进行判空操作，就是看看头结点的next指针是否为空。
//如果为空，那么这个单链表没有存储数据
//不带头结点以后写代码比较麻烦

//插入操作-----带头结点
// LinkList(&L,i,e):插入操作，在表中的第i个位置上插入元素e
// 头结点不存储数据，往表的第i个位置插入，需要找到第i-1个结点，将新结点插入该结点之后
//考试中推荐使用带头结点的方式 

//插入指定元素
int ListInsert(LinkList* L, int i, int e)
{
	int j = 0;
	if (i < 1) //判断i的位置是否合法，如果不合法，就没必要执行下去了
	{
		return -1;
	}
	LNode* p = *L;
	for (j = 0; p != NULL && j < i-1; j++)
	{
		p = (*p).next;
	}
	//if (p == NULL) //i的值不合法
	//{
	//	return -1;
	//}
	//LNode* s = (LNode*)malloc(sizeof(LNode));
	//s->data = e;
	//s->next = p->next;
	//(*p).next = s;
	//return 1;
	return InsertNextNode(&p, e); //后插操作
}

//指定结点后插：在p结点之后插入e
int InsertNextNode(LNode** p, int e)
{
	if (p == NULL)
	{
		return -1;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) //如果内存申请失败
	{
		return -1;
	}

	s->data = e;
	s->next = (*p)->next;
	(*p)->next = s;
	return 1;
}

//在指定结点之前插入元素e
int InsertPriorNode(LNode* p, int e)
{
	if (p == NULL)
	{
		return -1;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
	{
		return -1;
	}
	s->next = p->next;
	s->data = p->data;
	p->data = e;
	p->next = s;
	return 1;
}

//按位序删除。删除表L中的第i个位置的元素，并且用e返回删除元素的值
int ListDelete(LinkList* L, int i, int* e)
{
	if (i < 1)
	{
		return 9999; //输入非法，返回9999
	}
	LNode* p;//指针p指向当前扫描到的结点
	int j = 0;
	p = *L;
	for (j = 0; j < i - 1 && p != NULL; j++)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		return 9999; //i的值不合法
	}
	if (p->next == NULL)
	{
		return 9999;  //第i-1个结点之后已经没有其他结点
	}
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return 1;
}

//删除指定结点p
int DeleteLNode(LNode* p)
{
	if (p == NULL)
	{
		return 9999;
	}
	LNode* q = p->next;
	p->data = q->data;  //代码有bug，如果要删除最后一个结点 此时p是NULL，从NULL中取data取不出来
	p->next = q->next;
	free(q);
}

//单链表的查找  按值查找  按位查找

//按值查找，找到数据为e的结点，返回该结点的地址
LNode* LocateElem(LinkList L, int e)
{
	LNode* p = L;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

//按位查找  返回第i个元素
LNode* GetElem(LinkList L, int i)
{
	if (i < 1 || L == NULL)
	{
		return NULL;
	}
	LNode* p;
	int j = 0;
	p = L;
	for (j = 0; p!=NULL&&j < i; j++)
	{
		p = p->next;
	}
	return p;
}

//求表的长度
int Length(LinkList L)
{
	int len = 0;
	LNode* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		len += 1;
	}
	return len;
}

//尾插法建立单链表
LinkList List_TailInsert()
{
	int x; //假设每个插入的元素类型是int
	LinkList L = (LinkList)malloc(sizeof(LNode)); //建立头结点
	LNode* s, *end=L;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		end->next = s;
		end = s;
		scanf("%x", &x);
	}
	end->next = NULL;
	return L;
}

//头插法建立单链表
LinkList List_HeadInsert()
{
	LNode* s;
	int x;
	LinkList L = (LinkList)malloc(sizeof(LNode)); //建立头结点
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L; 
}


int main()
{
	LinkList L;
	//LNode* L 
	InitList(&L);

	ListInsert(&L,1,5);
	//printf("表中第1个元素为%d\n",(L->next)->data); //头结点不存储数据

	InsertPriorNode(L->next, 6);
	//printf("表中第1个元素为%d\n", (L->next)->data); 
	//printf("表中第2个元素为%d\n", (L->next)->next->data);



	/*int ret = ListDelete(&L, 1, &ret);
	printf("要删除的元素为%d\n", ret);*/
	printf("%d\n",Length(L));

	return 0;
}