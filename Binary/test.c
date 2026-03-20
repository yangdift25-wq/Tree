#include<stdio.h>
#include<stdlib.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;//左孩子
	struct BinaryTreeNode* right;//右孩子
	BTDataType val;//当前节点值
}BTNode;
//申请节点
BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->val = x;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}
//创造节点
BTNode* CreateTree()
{
	BTNode* n1=BuyNode(1);
	BTNode* n2=BuyNode(2);
	BTNode* n3=BuyNode(3);
	BTNode* n4=BuyNode(4);
	BTNode* n5=BuyNode(5);
	BTNode* n6=BuyNode(6);
	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;

	return n1;
}
//前序遍历
void PrevOrder(BTNode* root)
{
	//先判空
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	//不是空的就打印root
	printf("%d ", root->val);

	//然后递归来遍历,先左后右
	PrevOrder(root->left);
	PrevOrder(root->right);//递归调用其实就是一份指令重复使用
}

void InOrder(BTNode* root)
{
	//先判空
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	PrevOrder(root->left);

	//不是空的就打印root
	printf("%d ", root->val);

	PrevOrder(root->right);
}

int main()
{
	//先申请节点
	BTNode* root = CreateTree();
	//前序遍历
	PrevOrder(root);
	printf("\n");
	InOrder(root);
	return 0;
}
