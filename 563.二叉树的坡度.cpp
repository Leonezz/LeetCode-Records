/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int findTilt(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 0;
        int tilt = absMinus(sum(root->left), sum(root->right));
        return tilt + findTilt(root->left) + findTilt(root->right);
    }
    int sum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    int &&absMinus(int first, int second)
    {
        return move(first > second ? first - second : second - first);
    }
};
// @lc code=end
