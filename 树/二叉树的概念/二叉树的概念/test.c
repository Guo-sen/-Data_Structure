

//��������˳��洢
#define MaxSize 100
//struct TreeNode {
//	ElemType value;  //����е�����Ԫ��
//	bool isEmpty;   //����Ƿ�Ϊ��
//};
//TreeNode t[MaxSize]; //����һ������t�����մ������£��������ҵ�˳�����δ洢��ȫ�������еĸ������
//for (int i < 0; i < MaxSize; i++)
//{
//	t[i].isEmpty = true; //��ʼ��ʱ�����н��	���Ϊ��
//}

//������Ҫ�Ļ�������
//i�����ӣ�i���Һ��ӣ�i�ĸ��ڵ㣬i�Ĳ��

//��������˳��洢�У�һ��Ҫ�Ѷ������Ľ��������ȫ��������Ӧ�������ᵼ�´洢�ռ���˷ѣ�
//��������˳��洢��ֻ�ʺϴ洢��ȫ������




//����������ʽ�洢(Ҳ���Խ�����������)
// n�����Ķ���������n+1��������
//typedef struct BiTNode {
//	ElemType data; //������
//	struct BiTNode* lchild, * rchild;
//}BiTNode,*BiTree;


//��ʼ��
struct ElemType {
	int value;
};

typedef struct BiTNode {
	struct ElemType data; //������
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

BiTree root = NULL; //����һ�ÿ���

//������ڵ�
root = (BiTree)malloc(sizeof(BiTNode));
root->data = { 1 };
root->lchild = NULL;
root->rchild = NULL;

//�����½ڵ�
BiTNode *p = NULL;
p = (BiTNode*)malloc(sizeof(BiTNode));
p->data = { 2 };
p->lchild = NULL;
p->rchild = NULL;
root->lchild = p; //��Ϊ���ڵ������

//���ϴ��룬���ڲ���ָ���ڵ�ĸ��ڵ㲻̫���㣬ֻ�ܴӸ���ʼ����Ѱ��
//��Ҫʱ������BiTNode�ṹ���У��ٶ���һ��ָ������ָ�����ĸ���㣨��������
