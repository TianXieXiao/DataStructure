#pragma once
typedef int BDataType;

//孩子表示法
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

//层序遍历
void LevelOrder(BTNode* root);
//求二叉树中节点个数
int BinaryTreeSize(BTNode* root);
//二叉树叶子节点个数
int BinartTreeLeafSize(BTNode* root);
//二叉树第K层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
//求二叉树的高度
int BinaryTreeHeight(BTNode* root);
//二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BDataType x);
//判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
void BinaryTreeDestroy(BTNode** root);
void TestBinTree();