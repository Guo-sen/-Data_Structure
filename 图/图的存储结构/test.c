#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

//图的存储：


//邻接矩阵法
#define MaxVertexNUm 100	//顶点数目的最大值
typedef struct {
	char Vex[MaxVertexNUm];	//顶点表 注意顶点的下标和二维数组中的下标
	int Edge[MaxVertexNUm][MaxVertexNUm]; //邻接矩阵，边表 由于只存储1和0，也可以用bool类型
	int vexnum, arcnum; //图的当前顶点数和边数 /弧数
}MGraph;

//如果 Edge[i][j]==1,表示那条边是存在的
//如果 Edge[i][j]==0,表示那条边是不存在的

//思考：如何求某个结点的度、入度、出度
//对于无向图：查看矩阵中某个结点那一行（或那一列）非0个数
//对于有向图：出度：查看矩阵中这个结点的那一行非0个数
//			  入度：查看矩阵中这个结点的那一列非0个数
//		        度：入度+出度			  


//假设存储带权图：在矩阵中对应位置写上权值
//若那条边不存在可以定义int的最大值来表示无穷 #define INFINITY INT_MAX


//邻接矩阵法的性能分析
//n个结点：存储结点的空间复杂度：o（n）
//		   存储边o（n²）
//		   空间复杂的o（n）+o（n²）=o（n²） 只和顶点数有关，和实际的边数无关
//假设顶点数很多，边数很少，许多空间会被浪费。邻接矩阵法只适合存储稠密图
//无向图的邻接矩阵是对称矩阵，可以压缩存储（只存储上三角或者下三角）

//邻阶矩阵法的性质
//假设讨论不带权的图
//设图G的邻接矩阵A（矩阵元素为0/1），则A^n的元素A^n[i][j]等于由顶点i到顶点j的长度为n的路径的数目