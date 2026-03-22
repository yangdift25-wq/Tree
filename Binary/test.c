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

	PrevOrder(root->right);//前中后序就是这三个位置变化
}

void PostOrder(BTNode* root)
{
	//判空
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}

//所有节点个数(当然用全局变量size++也可以，不过每一次调用都要置为0麻烦
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) +
		TreeSize(root->right) +
		1;
}

//叶子节点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//树的高度(时间复杂度o(n))
int TreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//用变量吧节点的值存起来，如果不存起来，直接在return 里把leftHeight和rightHeight换成TreeHeight也可以做但是时间复杂度就成了o(n^2)
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);
	//这里不管是left+1或者right+1都是一样的，都是返回了上一节点
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//树的第k层节点数(用递归的方式去做，k=0时,k=1时，k>1时
int TreeKLevel(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeKLevel(root->left, k-1) + TreeKLevel(root->right, k-1);
}

//二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == x)
	{
		return root;
	}
	//如果找到了就层层返回，如果只返回一个root那么也只是返回上一个递归栈，所以还要返回left
	BTNode* left = TreeFind(root->left, x);
	if (left != NULL)
	{
		return left;
	}
	BTNode* right = TreeFind(root->right, x);
	if (right != NULL)
	{
		return right;
	}
}

int main()
{
	//先申请节点
	BTNode* root = CreateTree();
	//前序遍历
	PrevOrder(root);
	//中序遍历
	printf("\n");
	InOrder(root);
	//后序遍历
	printf("\n");
	PostOrder(root);
	
	//所有节点个数
	printf("\n");
	printf("%d", TreeSize(root));

	//叶子节点个数
	printf("\n");
	printf("%d",TreeLeafSize(root));

	//树的高度
	printf("\n");
	printf("%d", TreeHeight(root));

	//第k层节点个数
	printf("\n");
	printf("%d", TreeKLevel(root,2));
	//查找值为x的节点
	printf("\n");
	if (TreeFind(root, 2))
	{
		printf("找到了");
	}
	return 0;
}
