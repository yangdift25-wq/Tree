这题是前序遍历
但是要把二叉树里的值都传入到一个数组里并且返回这个数组，另外要计算出这个二叉树节点个数并且存起来


//这题思路是先求二叉树的元素个数，然后malloc申请数组，然后就遍历了

这道题有一点坑具体看代码，然后总结出来

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
    //只要一个为空就返回false,两个空的情况以及判断过了
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
