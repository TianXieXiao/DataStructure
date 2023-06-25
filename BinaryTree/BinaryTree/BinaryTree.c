 #pragma warning(disable:4996) 
#include "BinaryTree.h"
#include "Queue.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>

BTNode* BuyBinTreeNode(BDataType data)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == node)
	{
		assert(0);
		return NULL;
	}
	node->data = data;
	node->left = node->right = NULL;
	return node;
}
//index����ֵ�ķ�ʽ���ݵ�---�ڵݹ�����ж�index�޸�֮�󣬲��Ὣ�޸�֮��Ľ��������һ����
BTNode* _CreateBinTree(BDataType array[], int size, int *index, BDataType invalid)
{
	BTNode* root = NULL;
	if (*index < size && invalid != array[*index])
	{
		//�������ڵ�
		root = BuyBinTreeNode(array[*index]);
		//�������ڵ��������
		++(*index);
		root->left = _CreateBinTree(array, size, index, invalid);
		//�������ڵ��������
		++(*index);
		root->right = _CreateBinTree(array, size, index, invalid);
	}
	return root;
}
BTNode* CreateBinTree(BDataType array[], int size, BDataType invalid)
{
	int index = 0;
	return _CreateBinTree(array, size, &index, invalid);
}
//BTNode* CreateBinTree(BDataType array[], int size)
//{
//	BTNode* node1 = BuyBinTreeNode(array[0]);
//	BTNode* node2 = BuyBinTreeNode(array[1]);
//	BTNode* node3 = BuyBinTreeNode(array[2]);
//	BTNode* node4 = BuyBinTreeNode(array[3]);
//	BTNode* node5 = BuyBinTreeNode(array[4]);
//	BTNode* node6 = BuyBinTreeNode(array[5]);
//
//	node1->left = node2;
//	node1->right = node4;
//	node2->left = node3;
//	node4->left = node5;
//	node4->right = node6;
//
//	return node1;
//}
void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//���������������-->���ڵ�-->������
void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}
void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}

//�������
void LevelOrder(BTNode* root)
{
	Queue q;
	if (NULL == root)
		return;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		printf("%d ", cur->data);
		if (cur->left)
			QueuePush(&q, cur->left);
		if (cur->right)
			QueuePush(&q, cur->right);
		QueuePop(&q);
	}
	QueueDestroy(&q);
}
//��������нڵ����
int BinaryTreeSize(BTNode* root)
{
	if (NULL == root)
		return 0;
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}
//������Ҷ�ӽڵ����
int BinartTreeLeafSize(BTNode* root)
{
	if (NULL == root)
		return 0;
	if (NULL == root->left && NULL == root->right)
	{
		return 1;
	}
	return BinartTreeLeafSize(root->left) + BinartTreeLeafSize(root->right);
}
//��������K��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (NULL == root || k <= 0)
		return 0;
	//��1����ֻ�и��ڵ�
	if (1 == k)
		return 1;
	// k > 1
	return BinaryTreeLevelKSize(root->left, k - 1) +
		   BinaryTreeLevelKSize(root->right, k - 1);
}
//��������ĸ߶�
int BinaryTreeHeight(BTNode* root)
{
	if (NULL == root)
		return 0;
	int leftHeight = BinaryTreeHeight(root->left);
	int rightHeight = BinaryTreeHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
//����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BDataType x)
{
	BTNode* ret = NULL;
	if (NULL == root)
		return NULL;
	if (x == root->data)
		return root;
	if (ret = BinaryTreeFind(root->left, x))
		return ret;
	return BinaryTreeFind(root->right, x);
}

void BinaryTreeDestroy(BTNode** root)
{
	assert(root);
	if (NULL == *root)
		return NULL;
	//���պ���������������������
	BinaryTreeDestroy(&(*root)->left);
	BinaryTreeDestroy(&(*root)->right);
	free(*root);
	*root = NULL;
}
//�ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	//����Ҳ����ȫ������
	Queue q;
	int flag = 0;
	if (NULL == root)
	{
		return 1;
	}
	//���
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		if (flag)
		{
			//�ӵ�һ���������ڵ�֮�����нڵ㲻���к���
			if (cur->left || cur->right)
			{
				QueueDestroy(&q);
				return 0;
			}
		}
		else
		{
			//�ҵ�һ���������ڵ�
			if (cur->left && cur->right)
			{
				QueuePush(&q, cur->left);
				QueuePush(&q, cur->right);
			}
			else if (cur->left)
			{
				QueuePush(&q, cur->left);
				flag = 1;
			}
			else if (cur->right)
			{
				QueueDestroy(&q);
				return 0;
			}
			else
			{
				flag = 1;
			}
		}
		QueuePop(&q);
	}
	QueueDestroy(&q);
	return 1;
}
void TestBinTree()
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	BTNode* root = CreateBinTree(array, 6);
	printf("������ǰ����������");
	PreOrder(root);
	printf("\n");

	printf("������������������");
	InOrder(root);
	printf("\n");

	printf("������������������");
	PostOrder(root);
	printf("\n");

	printf("������������������");
	LevelOrder(root);
	printf("\n");

	printf("���нڵ��ܵĸ���Ϊ��%d\n", BinaryTreeSize(root));
	printf("����Ҷ�ӽڵ��ܵĸ���Ϊ��%d\n", BinartTreeLeafSize(root));
	printf("���е�%d��ڵ��ܵĸ���Ϊ��%d\n", BinaryTreeLevelKSize(root, 3));
	printf("���߶�Ϊ��%d\n", BinaryTreeHeight(root));
	printf("����%p\n", BinaryTreeFind(root, 5));
	printf("����%p\n", BinaryTreeFind(root, 10));

	BinaryTreeDestroy(&root);
}