这道题时输入一串字符表示二叉树的个节点元素，'#'表示为空
以此字符串来创建二叉树，并且以中序遍历的方式输出二叉树







  //思路是先创建一个数组来接受字符串
  //之后先定义二叉树结构，再以前序的方式(当然前中后序都可以)创建二叉树注意这里以malloc申请节点,最后中序遍历
  
#include <stdio.h>

//定义树结构
typedef struct BTNode
{
    struct BTNode* left;
    struct BTNode* right;
    char val;
}BTNode;

//使用malloc以及前序的方法创建树
BTNode* createTree(char* arr,int* i)
{
    //在申请节点之前给数组判空因为当数组的元素为空，也就不需要申请空间
    if(arr[*i]=='#')
    {
        (*i)++;
        return NULL;
    }
    BTNode* root=(BTNode*)malloc(sizeof(BTNode));
    if(root==NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    root->val=arr[*i];
    (*i)++;
    root->left=NULL;
    root->right=NULL;
    root->left=createTree(arr,i);
    root->right=createTree(arr,i);

    return root;
}

//开始中序遍历
void InOrder(BTNode* root)
{
    if(root==NULL)
    {
        return;
    }

    InOrder(root->left);
    printf("%c ",root->val);
    InOrder(root->right);
}

int main()
{
    //先把字符串给输入到一个数组里存起来
    char arr[100];
    scanf("%s",arr);

    int i=0;
    //然后创建树
    //为什么传地址呢，因为每一层函数栈帧中的i都是独立的，返回之后的i还是原来的i
    BTNode* root=createTree(arr,&i);

    //中序遍历
    InOrder(root);
    return 0;
}
