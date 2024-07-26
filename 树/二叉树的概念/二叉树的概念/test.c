

//二叉树的顺序存储
#define MaxSize 100
//struct TreeNode {
//	ElemType value;  //结点中的数据元素
//	bool isEmpty;   //结点是否为空
//};
//TreeNode t[MaxSize]; //定义一个数组t，按照从上至下，从左至右的顺序依次存储完全二叉树中的各个结点
//for (int i < 0; i < MaxSize; i++)
//{
//	t[i].isEmpty = true; //初始化时，所有结点	标记为空
//}

//几个重要的基本操作
//i的左孩子，i的右孩子，i的父节点，i的层次

//二叉树的顺序存储中，一定要把二叉树的结点编号与完全二叉树对应起来（会导致存储空间的浪费）
//二叉树的顺序存储，只适合存储完全二叉树




//二叉树的链式存储(也可以叫做二叉链表)
// n个结点的二汊链表共有n+1个空链域
//typedef struct BiTNode {
//	ElemType data; //数据域
//	struct BiTNode* lchild, * rchild;
//}BiTNode,*BiTree;


//初始化
struct ElemType {
	int value;
};

typedef struct BiTNode {
	struct ElemType data; //数据域
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

BiTree root = NULL; //定义一棵空树

//插入根节点
root = (BiTree)malloc(sizeof(BiTNode));
root->data = { 1 };
root->lchild = NULL;
root->rchild = NULL;

//插入新节点
BiTNode *p = NULL;
p = (BiTNode*)malloc(sizeof(BiTNode));
p->data = { 2 };
p->lchild = NULL;
p->rchild = NULL;
root->lchild = p; //作为根节点的左孩子

//以上代码，对于查找指定节点的父节点不太方便，只能从根开始遍历寻找
//必要时可以在BiTNode结构体中，再定义一个指针用来指向他的父结点（三叉链表）
