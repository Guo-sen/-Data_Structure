#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//�� ���ַ���������0�������ַ�����ɵ���������
//���е��ַ�����n��Ϊ���ĳ���
//
//�Ӵ�������������������ַ���ɵ�������
//�����������Ӵ��Ĵ�
//�ַ��������е�λ�ã��ַ���һ���һ�γ��֣��ڴ��е����
//�Ӵ��������е�λ�ã��Ӵ��ĵ�һ���ַ��ڴ��е�λ��

//����һ����������Ա�����Ԫ��֮������Թ�ϵ
//�Դ��Ļ�������������ɾ�Ĳ��ͨ�����Ӵ�Ϊ��������

//���Ĵ洢�ṹ��˳��洢����ʽ�洢

//����˳��洢
#define MAXLEN 255
//typedef struct {
//	char ch[MAXLEN];//��̬����ʵ�ֶ����洢
//	int length;		//����ʵ�ʳ���
//}SString;

//typedef struct {
//	char* ch;	//��̬����ʵ�ֶѷ���洢
//	int length;  
//}HString;
//
//HString S;
//S.ch = (char*)malloc(MAXLEN * sizeof(char));  //ע��������Ҫ�ֶ�free
//S.length = 0;



//������ʽ�洢
//typedef struct StringNode {
//	char ch; //ÿ�����洢1���ַ�
//	struct StringNode* next;
//}StringNode,*String;

//����ʵ�ַ����洢�ܶȵͣ�һ���ַ�һ���ֽڣ���Ϊ�˴���һ���ֽڣ�
//����Ҫ����4���ֽڴ洢���ĵ�ַ

//typedef struct StringNode {
//	char ch[4]; //ÿ�����洢4���ַ�
//	struct StringNode* next;
//}StringNode, * String;
//�洢�ܶ������


typedef struct {
	char ch[MAXLEN];//��̬����ʵ�ֶ����洢
	int length;		//����ʵ�ʳ���
}SString;

//�������� 

//SubString��&Sub,S,pos,len�����Ӵ�����Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�

int SubString(SString* Sub, SString S, int pos, int len)
{
	if (pos + len - 1 > S.length) //�Ӵ�Խ��
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


//StrCompare(S,T):�Ƚϲ�������S>T,�򷵻�>0,��S=T���򷵻�0����S<T,�򷵻�<0
int StrCompare(SString S, SString T)
{
	for (int i = 0; i < S.length && i < T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
		{
			return S.ch[i]-T.ch[i];
		}
	}
	//��ɨ����������ַ�����ͬ���򳤶ȳ��ĸ���
	return S.length - T.length;
}

//Index��S,T��:��λ������������S�д����봮Tֵ��ͬ���Ӵ���
//�򷵻���������S�е�һ�γ��ֵ�λ�ã����򷵻�0

int Index(SString S, SString T)
{
	int n = strlen(S.ch);
	int m = strlen(T.ch);
	SString tem; //������ʱ�洢�Ӵ�
	for (int i =0;i+m<n;i++)
	{
		SubString(&tem, S, i, m);
		if (StrCompare(tem, T) == 0)
		{
			return i+1;  //�����±��Ǵ�0��ʼ��
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