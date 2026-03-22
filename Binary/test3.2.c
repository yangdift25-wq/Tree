这题是上一题的拓展
判断一个树的子树是否和另一个树一样




// 思路就是先创建一个判断相等函数
// 然后在原函数里写条件与递归



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 typedef struct TreeNode TreeNode;
 //构建一个判断相等函数
 bool issame(TreeNode* p,TreeNode* q)
 {
    if(p==NULL&&q==NULL)
    {
        return true;
    }
    if(p==NULL||q==NULL)
    {
        return false;
    }
    if(p->val!=q->val)
    {
        return false;
    }

    return issame(p->left,q->left)&&
    issame(p->right,q->right);
 }
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    //判断条件
    if(root==NULL)
    {
        return false;
    }
    if(subRoot==NULL)
    {
        return true;
    }
    if(issame(root,subRoot))
    {
        return true;
    }
        //只要有一个成立就可以了
        return isSubtree(root->left,subRoot)||
        isSubtree(root->right,subRoot);
}
