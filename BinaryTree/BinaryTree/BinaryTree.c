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
//index按照值的方式传递的---在递归过程中对index修改之后，不会将修改之后的结果带到上一层中
BTNode* _CreateBinTree(BDataType array[], int size, int *index, BDataType invalid)
{
	BTNode* root = NULL;
	if (*index < size && invalid != array[*index])
	{
		//创建根节点
		root = BuyBinTreeNode(array[*index]);
		//创建根节点的左子树
		++(*index);
		root->left = _CreateBinTree(array, size, index, invalid);
		//创建根节点的右子树
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
//中序遍历：左子树-->根节点-->右子树
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

//层序遍历
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
//求二叉树中节点个数
int BinaryTreeSize(BTNode* root)
{
	if (NULL == root)
		return 0;
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}
//二叉树叶子节点个数
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
//二叉树第K层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (NULL == root || k <= 0)
		return 0;
	//第1层中只有根节点
	if (1 == k)
		return 1;
	// k > 1
	return BinaryTreeLevelKSize(root->left, k - 1) +
		   BinaryTreeLevelKSize(root->right, k - 1);
}
//求二叉树的高度
int BinaryTreeHeight(BTNode* root)
{
	if (NULL == root)
		return 0;
	int leftHeight = BinaryTreeHeight(root->left);
	int rightHeight = BinaryTreeHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
//二叉树查找值为x的节点
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
	//按照后续遍历规则来进行销毁
	BinaryTreeDestroy(&(*root)->left);
	BinaryTreeDestroy(&(*root)->right);
	free(*root);
	*root = NULL;
}
//判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	//空树也是完全二叉树
	Queue q;
	int flag = 0;
	if (NULL == root)
	{
		return 1;
	}
	//检测
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		if (flag)
		{
			//从第一个不饱含节点之后，所有节点不能有孩子
			if (cur->left || cur->right)
			{
				QueueDestroy(&q);
				return 0;
			}
		}
		else
		{
			//找第一个不饱含节点
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
	printf("二叉树前序遍历结果：");
	PreOrder(root);
	printf("\n");

	printf("二叉树中序遍历结果：");
	InOrder(root);
	printf("\n");

	printf("二叉树后序遍历结果：");
	PostOrder(root);
	printf("\n");

	printf("二叉树层序遍历结果：");
	LevelOrder(root);
	printf("\n");

	printf("树中节点总的个数为：%d\n", BinaryTreeSize(root));
	printf("树中叶子节点总的个数为：%d\n", BinartTreeLeafSize(root));
	printf("树中第%d层节点总的个数为：%d\n", BinaryTreeLevelKSize(root, 3));
	printf("树高度为：%d\n", BinaryTreeHeight(root));
	printf("查找%p\n", BinaryTreeFind(root, 5));
	printf("查找%p\n", BinaryTreeFind(root, 10));

	BinaryTreeDestroy(&root);
}