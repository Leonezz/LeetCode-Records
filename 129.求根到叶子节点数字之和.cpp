/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
 */
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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
    int sumNumbers(TreeNode *root)
    {
        return dfs(root,0);
    }
    int dfs(TreeNode *root, int sum)
    {
        if (root == NULL)
            return 0;
        else if (root->left == NULL && root->right == NULL)
            return 10 * sum + root->val;
        else
            return dfs(root->left, 10 * sum + root->val) +
                   dfs(root->right, 10 * sum + root->val);
    }
};
// @lc code=end
