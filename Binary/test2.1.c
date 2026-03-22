这道题是判断两个二叉树是否相等
先想想吧






// 思路是用递归
// 事实上是判断每个根节点是否相等，具体代码如下


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 typedef struct TreeNode TreeNode;
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p==NULL&&q==NULL)
    {
        return true;
    }
    //只要一个为空就返回false,两个空的情况已经判断过了
    if(p==NULL||q==NULL)
    {
        return false;
    }
    //如果不相等就返回false,这里这样判断与第一个if呼应了,到了最后的节点还没返回就是真的了
    if(p->val!=q->val)
    {
        return false;
    }
    //只要有一个错误就返回false
    return isSameTree(p->left,q->left)&&
    isSameTree(p->right,q->right);
}
