#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//串 即字符串，是由0个或多个字符串组成的有限序列
//串中的字符个数n称为串的长度
//
//子串：串中任意个连续的字符组成的子序列
//主串：包含子串的串
//字符在主串中的位置：字符（一般第一次出现）在串中的序号
//子串在主串中的位置：子串的第一个字符在串中的位置

//串是一种特殊的线性表，数据元素之间呈线性关系
//对串的基本操作，如增删改查等通常以子串为操作对象

//串的存储结构：顺序存储、链式存储

//串的顺序存储
#define MAXLEN 255
//typedef struct {
//	char ch[MAXLEN];//静态数组实现定长存储
//	int length;		//串的实际长度
//}SString;

//typedef struct {
//	char* ch;	//动态数组实现堆分配存储
//	int length;  
//}HString;
//
//HString S;
//S.ch = (char*)malloc(MAXLEN * sizeof(char));  //注意用完需要手动free
//S.length = 0;



//串的链式存储
//typedef struct StringNode {
//	char ch; //每个结点存储1个字符
//	struct StringNode* next;
//}StringNode,*String;

//上述实现方法存储密度低：一个字符一个字节，而为了存这一个字节，
//还需要花费4个字节存储它的地址

//typedef struct StringNode {
//	char ch[4]; //每个结点存储4个字符
//	struct StringNode* next;
//}StringNode, * String;
//存储密度提高了


typedef struct {
	char ch[MAXLEN];//静态数组实现定长存储
	int length;		//串的实际长度
}SString;

//基本操作 

//SubString（&Sub,S,pos,len）求子串：用Sub返回串S的第pos个字符起长度为len的子串

int SubString(SString* Sub, SString S, int pos, int len)
{
	if (pos + len - 1 > S.length) //子串越界
	{
		return -9999;
	}
	int i = pos;
	for (; i < pos + len; i++)
	{
		(*Sub).ch[i - pos] = S.ch[i];
	}
	Sub->length = len;
	(*Sub).ch[i - pos] = '\0';

	return 1;
}


//StrCompare(S,T):比较操作。若S>T,则返回>0,若S=T，则返回0，若S<T,则返回<0
int StrCompare(SString S, SString T)
{
	for (int i = 0; i < S.length && i < T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
		{
			return S.ch[i]-T.ch[i];
		}
	}
	//若扫描过的所有字符都相同，则长度长的更大
	return S.length - T.length;
}

//Index（S,T）:定位操作。若主串S中存在与串T值相同的子串，
//则返回它在主串S中第一次出现的位置，否则返回0

int Index(SString S, SString T)
{
	int n = strlen(S.ch);
	int m = strlen(T.ch);
	SString tem; //用于暂时存储子串
	for (int i =0;i+m<n;i++)
	{
		SubString(&tem, S, i, m);
		if (StrCompare(tem, T) == 0)
		{
			return i+1;  //数组下标是从0开始的
		}
	}
	return 0;
}

int main()
{
	SString S = {"wangdaokaoyan",13};
	SString sub;
	SubString(&sub, S, 5, 3);
	printf("%s\n", sub.ch);

	printf("%d\n", StrCompare(S,sub));

	printf("%d\n", Index(S, sub));
	return 0;
}