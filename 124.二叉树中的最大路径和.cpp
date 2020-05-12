/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
private:
    int result;

public:
    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;
        result = root->val;
        dfs(root);
        return result;
    }
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = maxOfTwo(dfs(root->left), 0);
        int right = maxOfTwo(dfs(root->right), 0);
        result = maxOfTwo(root->val + left + right, result);
        return maxOfTwo(left, right) + root->val;
    }
    int maxOfTwo(int first, int second)
    {
        return first > second ? first : second;
    }
};
// @lc code=end
