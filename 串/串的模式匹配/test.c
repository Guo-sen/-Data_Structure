#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//什么是字符串的模式匹配
//字符串的模式匹配：在主串中找到与模式串相同的子串，并返回其所在的位置
//注意模式串和主串的区别：子串一定存在于主串中，但模式串不一定

//朴素模式匹配算法（暴力匹配）

//假设主串长度为n，模式串长度为m，最多比n-m+1个子串

//#define MAXLEN 255
//typedef struct {
//	char arr[MAXLEN];
//	int length;
//}SString;
//
//
//int Index(SString SS, SString TT)
//{
//	int i = 1, j = 1;
//	for (; i <= SS.length && j < TT.length;)
//	{
//		if (SS.arr[i-1] == TT.arr[j-1] && TT.arr[j-1] != '\0')
//		{
//			++i; ++j;
//		}
//		else
//		{
//			i = i - j + 2;
//			j = 1;
//		}
//	}
//	if (j >= TT.length)
//	{
//		//apple cat dog
//		
//		return i - TT.length+1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//int main()
//{
//	SString SS = { "apple cat dog",13 };
//	SString TT = { "dog",3 };
//	int ret = Index(SS, TT);
//	printf("%d\n", ret);
//	return 0;
//}






//KMP算法
//当主串和模式串之间匹配到不同时，在那个不同元素之前，主串和模式串是相同的
//优化后实现了不让主串的指针回溯

//在进行kmp算法时，应先根据模式串，求出next数组，然后再利用next数组进行匹配
//next数组主要用来模式串指针的回溯，主串指针不回溯





//#define MAXLEN 255
//typedef struct {
//	char arr[MAXLEN];
//	int length;
//}SString;
//
//int Index_KMP(SString S, SString T, int next[])
//{
//	int i = 1;
//	int j = 1;
//	while (i <= S.length && j < T.length)
//	{
//		if (j == 0 || S.arr[i] == T.arr[j])
//		{
//			++i;
//			++j;
//		}
//		else
//		{
//			j = next[j]; //模式串向右移动
//		}
//	}
//	if (j > T.length)
//	{
//		return i - T.length;
//	}
//	return -1;
//}

//求next数组（手算）
//任何模式串都一样，第一个字符不匹配时，只能匹配下一个子串，
//因此，next【1】=0恒成立

//next【2】=1恒成立
//
//其余next数组，在不匹配的位置的前边画一个分界线，模式串一步一步往后退，直到分界线之前能对上，
//或者模式串完全跨过分界线为止，此时j指向哪里，next数组的值就是多少



//求next数组算法的优化
//求nextval数组 如果next[j]所指向的字符和目前j所指向的字符不相等
//那就让nextval[j]的值＝next[j]

//如果next[j]所指向的字符和目前j所指向的字符不相等