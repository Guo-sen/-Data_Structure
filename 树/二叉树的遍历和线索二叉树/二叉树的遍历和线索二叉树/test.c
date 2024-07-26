#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


//�������ı������������򡢺���
//����������ĳ�ִ��򣬰����н�㶼����һ��

//�����ֳ��˷ֲ������
//��α������������Ĳ������ȷ���Ĵ������
//��/��/����������������ĵݹ�����ȷ���Ĵ������

//�������ĵݹ�����
//1.Ҫô�ǿն�����
//2.Ҫô�����ɸ��ڵ�+������+��������ɵĶ�����
//��������������ң�NLR��		�ֽ��ȸ�����
//�������������ң�LNR��
//������������Ҹ���LRN��


typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
//�������:��������Ϊ�գ���ʲôҲ����
//			���ǿգ�1.���ʸ����  2.����������  3.����������
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		visit(T);			//���ʸ��ڵ�
		PreOrder(T->lchild);//�ݹ����������
		PreOrder(T->rchild);//�ݹ����������
	}
}

//�������
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		PreOrder(T->lchild);//�ݹ����������
		visit(T);			//���ʸ��ڵ�
		PreOrder(T->rchild);//�ݹ����������
	}
}

//�������
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		PreOrder(T->lchild);//�ݹ����������
		PreOrder(T->rchild);//�ݹ����������
		visit(T);			//���ʸ��ڵ�
	}
}
//�ռ临�ӷ�O��h��


//Ӧ�ã����������
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
		return l > r ? l + 1 : r + 1;   //���ؽϴ���Ǹ�

	}
}


//�������Ĳ������
//��ʼ��һ����������
//��������
//�����зǿգ����ͷ�����ӣ����ʸýڵ㣬���������Һ��Ӳ����β������еĻ���

//�������
void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(&Q);//��ʼ����������
	BiTree p;
	EnQueue(Q, T);// ��������
	while (IsEmpty(Q))  //�����зǿ�
	{
		DeQueue(Q, p); //��ͷԪ�س���
		visit(p);//���ʶ�ͷԪ��
		if (p->lchild != NULL)
		{
			EnQueue(Q,p->lchild); //�������
		}

		if (p->rchild != NULL)
		{
			EnQueue(Q, p->rchild); //�Һ������
		}


	}

}


