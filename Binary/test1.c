//单值二叉树
//判断这个二叉树所有值是否相等




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 typedef struct TreeNode TreeNode;
bool check(TreeNode* root,int val)
{
    if(root==NULL)
    {
        return true;
    }

    if(root->val!=val)
    {
        return false;
    }
    //递归判断的节点不断改变而要判断的值不变
    return check(root->left,val)&&check(root->right,val);
}
bool isUnivalTree(struct TreeNode* root) {
    return check(root,root->val);
}
