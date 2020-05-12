/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
            return true;
        else if (s == NULL || t == NULL)
            return false;
        if (s->val == t->val)
            return isSameTree(s, t) ||
                   (isSubtree(s->left, t) ||
                    isSubtree(s->right, t));
        else return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSameTree(TreeNode *first, TreeNode *second)
    {
        if (first == NULL && second == NULL)
            return true;
        else if (first == NULL || second == NULL)
            return false;
        else
        {
            if (first->val == second->val)
                return isSameTree(first->left, second->left) &&
                       isSameTree(first->right, second->right);
            else
                return false;
        }
    }
};
// @lc code=end
