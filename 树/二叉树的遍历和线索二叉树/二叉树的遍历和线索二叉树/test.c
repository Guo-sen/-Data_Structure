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


typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
//先序遍历:若二叉树为空，则什么也不做
//			若非空，1.访问根结点  2.访问左子树  3.访问右子树
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		visit(T);			//访问根节点
		PreOrder(T->lchild);//递归访问左子树
		PreOrder(T->rchild);//递归访问右子树
	}
}

//中序遍历
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		PreOrder(T->lchild);//递归访问左子树
		visit(T);			//访问根节点
		PreOrder(T->rchild);//递归访问右子树
	}
}

//后序遍历
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		PreOrder(T->lchild);//递归访问左子树
		PreOrder(T->rchild);//递归访问右子树
		visit(T);			//访问根节点
	}
}
//空间复杂发O（h）


//应用：求树的深度
int treeDepth(BiTree T) 
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		int l = treeDepth(T->lchild);
		int r = treeDepth(T->rchild);
		return l > r ? l + 1 : r + 1;   //返回较大的那个

	}
}


//二叉树的层序遍历
//初始化一个辅助队列
//根结点入队
//若队列非空，则对头结点出队，访问该节点，并将其左右孩子插入队尾（如果有的话）

//层序遍历
void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(&Q);//初始化辅助队列
	BiTree p;
	EnQueue(Q, T);// 根结点入队
	while (IsEmpty(Q))  //若队列非空
	{
		DeQueue(Q, p); //队头元素出队
		visit(p);//访问对头元素
		if (p->lchild != NULL)
		{
			EnQueue(Q,p->lchild); //左孩子入队
		}

		if (p->rchild != NULL)
		{
			EnQueue(Q, p->rchild); //右孩子入队
		}


	}

}


