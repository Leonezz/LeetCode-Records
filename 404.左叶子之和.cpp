/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return getLeft(root->left, true) + getLeft(root->right, false);
    }
    int getLeft(TreeNode *root, bool left)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL && left)
            return root->val;
        return getLeft(root->left, true) + getLeft(root->right, false);
    }
};
// @lc code=end
