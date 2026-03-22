这道题是判断两个二叉树是否对称
思路和上一道题相似所以放一起，先想想吧





// 好了，这题思路也是判断根节点是否相等
// 只是不同的是先把最上面的根节点的左右分为两棵树，而后在递归的时候两数方向相反判断就好了

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 typedef struct TreeNode TreeNode;

bool checkTree(TreeNode* left,TreeNode* right)
{
    if(left==NULL&&right==NULL)
    {
        return true;
    }
    if(left==NULL||right==NULL)
    {
        return false;
    }

    if(left->val!=right->val)
    {
        return false;
    }

    return checkTree(left->left,right->right)&&
    checkTree(left->right,right->left);
}
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)
    {
        return true;
    }
    return checkTree(root->left,root->right);
}
