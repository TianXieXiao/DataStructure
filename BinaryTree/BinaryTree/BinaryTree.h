#pragma once
typedef int BDataType;

//���ӱ�ʾ��
typedef struct BTNode
{
	BDataType data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

BTNode* CreateBinTree(BDataType array[], int size, BDataType invalid);
//BTNode* CreateBinTree(BDataType array[], int size);
void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);

//�������
void LevelOrder(BTNode* root);
//��������нڵ����
int BinaryTreeSize(BTNode* root);
//������Ҷ�ӽڵ����
int BinartTreeLeafSize(BTNode* root);
//��������K��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
//��������ĸ߶�
int BinaryTreeHeight(BTNode* root);
//����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BDataType x);
//�ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
void BinaryTreeDestroy(BTNode** root);
void TestBinTree();