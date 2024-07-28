#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


//二叉树的遍历（先序、中序、后序）
//遍历：按照某种次序，把所有结点都访问一遍

//树呈现出了分层的特性
//层次遍历：基于树的层次特性确定的次序规则
//先/中/后序遍历：基于树的递归特性确定的次序规则

//二叉树的递归特性
//1.要么是空二叉树
//2.要么就是由根节点+左子树+右子树组成的二叉树
//先序遍历：根左右（NLR）		又叫先根遍历
//中序遍历：左根右（LNR）
//后序遍历：左右根（LRN）


//typedef struct BiTNode {
//	ElemType data;
//	struct BiTNode* lchild, * rchild;
//}BiTNode,*BiTree;
////先序遍历:若二叉树为空，则什么也不做
////			若非空，1.访问根结点  2.访问左子树  3.访问右子树
//void PreOrder(BiTree T)
//{
//	if (T != NULL)
//	{
//		visit(T);			//访问根节点
//		PreOrder(T->lchild);//递归访问左子树
//		PreOrder(T->rchild);//递归访问右子树
//	}
//}
//
////中序遍历
//void PreOrder(BiTree T)
//{
//	if (T != NULL)
//	{
//		PreOrder(T->lchild);//递归访问左子树
//		visit(T);			//访问根节点
//		PreOrder(T->rchild);//递归访问右子树
//	}
//}
//
////后序遍历
//void PreOrder(BiTree T)
//{
//	if (T != NULL)
//	{
//		PreOrder(T->lchild);//递归访问左子树
//		PreOrder(T->rchild);//递归访问右子树
//		visit(T);			//访问根节点
//	}
//}
////空间复杂发O（h）
//
//
////应用：求树的深度
//int treeDepth(BiTree T) 
//{
//	if (T == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		int l = treeDepth(T->lchild);
//		int r = treeDepth(T->rchild);
//		return l > r ? l + 1 : r + 1;   //返回较大的那个
//
//	}
//}


//二叉树的层序遍历
//初始化一个辅助队列
//根结点入队
//若队列非空，则对头结点出队，访问该节点，并将其左右孩子插入队尾（如果有的话）

//层序遍历
//void LevelOrder(BiTree T)
//{
//	LinkQueue Q;
//	InitQueue(&Q);//初始化辅助队列
//	BiTree p;
//	EnQueue(Q, T);// 根结点入队
//	while (IsEmpty(Q))  //若队列非空
//	{
//		DeQueue(Q, p); //队头元素出队
//		visit(p);//访问对头元素
//		if (p->lchild != NULL)
//		{
//			EnQueue(Q,p->lchild); //左孩子入队
//		}
//
//		if (p->rchild != NULL)
//		{
//			EnQueue(Q, p->rchild); //右孩子入队
//		}
//	}
//}


//线索二叉树的存储结构
//typedef struct ThreadNode {
//	ElemType data;
//	struct ThreadNode* lchild, * rchild;
//	int ltag, rtag;		//左右线索标记
//}ThreadNode,*ThreadNode;
//tag==0，指针指向的是孩子，tag==1，指针指向的是线索

//二叉树的中序线索化(就是中序遍历的过程，只不过是一遍遍历，一边处理	)
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;		//左右线索标记
}ThreadNode,*ThreadNode;


ThreadNode* pre = NULL;

void visit(ThreadNode* q)
{
	if (q->lchild == NULL)
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = q; //建立前驱节点的后继线索
		pre->rtag = 1;
	}
	pre = q;
}

void InThread(ThreadTree T) 
{
	if (T != NULL)
	{
		InThread(T->lchild); //中序遍历左子树
		visit(T);
		InThread(T->rchild); //中序遍历右子树
	}
}


//先序或后序线索化思路类似，但是注意先序线索化中的转圈圈问题


//线索二叉树找前驱（或者后继）


//中序线索二叉树找中序后继
//中序遍历：左 根 右
//若某结点已经被线索化，即rtag==1，那么，这个结点的右孩子指针就是它的后继
//若某结点没被线索化，即rtag==0，那么这个结点肯定有右孩子，若它的右孩子是叶子结点，那它的右孩子就是它的后继
//若它的右孩子还有孩子，那么这个结点的后继就是，它的右子树中最左下的结点
//既然能找到后继，那么就能对中序线索二叉树进行中序遍历（不用递归的方法）

//中序线索二叉树找中序前驱
//若该结点已经被线索化，那么该结点的左孩子指向的就是前驱；
//若没有被线索化，即ltag==0，那么该结点必有左孩子。若该结点的左孩子是叶子结点，那么这个左孩子就是他的前驱
//若该结点的左孩子不是叶子结点，那么它的前驱是左孩子结点的右子树中最右下的结点
//可以对中序线索二叉树进行逆向的中序遍历



//先序线索二叉树找先序后继
//若右指针被线索化，那么它的右孩子就是它的后继
//若没有被线索化，那么它的右节点必定有右孩子（有没有左孩子不知道），若有左孩子，那么它的后继是左孩子结点
// 若没有左孩子，那么它的后继就是右孩子
//先序遍历：根 左 右
//
//先序线索二叉树找先前驱
// 若左指针没有被线索化，那么它必定有左孩子，但是先序：根 左 右 ，它的前驱必定不可能在它的左右子树中
// 所以这种情况找不到p的先序前驱，除非用土办法从头遍历
// 或者把二叉链表改造成三叉链表，当找到当前结点的父结点。根据先序遍历：根 左 右 就能找出当前结点的前驱
// 
// 

//后序线索二叉树找后序前驱
//若当前结点的ltag没有被线索化，那么它必有左孩（有没有右孩子不知道）
//若有右孩子，当前结点的后序前驱就是按后序遍历访问它的右子树最后访问到的元素
//若没有右孩子，后序遍历：左 根，该结点的前驱就是左子树中按后序遍历最后访问到的元素

//后序线索二叉树找后序后继
//若右孩子指针没有被线索化，那么它必有右孩子，假设有左孩子（没有也一样），左子树和右子树中都不可能有当前结点的前驱
//只能利用土办法，重新遍历
//或者改造成三叉链表，找到父结点
















