#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//ʲô���ַ�����ģʽƥ��
//�ַ�����ģʽƥ�䣺���������ҵ���ģʽ����ͬ���Ӵ��������������ڵ�λ��
//ע��ģʽ���������������Ӵ�һ�������������У���ģʽ����һ��

//����ģʽƥ���㷨������ƥ�䣩

//������������Ϊn��ģʽ������Ϊm������n-m+1���Ӵ�

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






//KMP�㷨
//��������ģʽ��֮��ƥ�䵽��ͬʱ�����Ǹ���ͬԪ��֮ǰ��������ģʽ������ͬ��
//�Ż���ʵ���˲���������ָ�����

//�ڽ���kmp�㷨ʱ��Ӧ�ȸ���ģʽ�������next���飬Ȼ��������next�������ƥ��
//next������Ҫ����ģʽ��ָ��Ļ��ݣ�����ָ�벻����





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
//			j = next[j]; //ģʽ�������ƶ�
//		}
//	}
//	if (j > T.length)
//	{
//		return i - T.length;
//	}
//	return -1;
//}

//��next���飨���㣩
//�κ�ģʽ����һ������һ���ַ���ƥ��ʱ��ֻ��ƥ����һ���Ӵ���
//��ˣ�next��1��=0�����

//next��2��=1�����
//
//����next���飬�ڲ�ƥ���λ�õ�ǰ�߻�һ���ֽ��ߣ�ģʽ��һ��һ�������ˣ�ֱ���ֽ���֮ǰ�ܶ��ϣ�
//����ģʽ����ȫ����ֽ���Ϊֹ����ʱjָ�����next�����ֵ���Ƕ���



//��next�����㷨���Ż�
//��nextval���� ���next[j]��ָ����ַ���Ŀǰj��ָ����ַ������
//�Ǿ���nextval[j]��ֵ��next[j]

//���next[j]��ָ����ַ���Ŀǰj��ָ����ַ������