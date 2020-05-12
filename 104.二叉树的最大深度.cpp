/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * 简单的递归题解
 * 
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            return maxOfTwo(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    int maxOfTwo(const int first, const int second)
    {
        return first > second ? first : second;
    }
};
// @lc code=end
