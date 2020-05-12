/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */
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
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else if (root->left == NULL || root->right == NULL)
            return maxOfTwo(move(minDepth(root->left)), move(minDepth(root->right))) + 1;
        else
            return minOfTwo(move(minDepth(root->left)), move(minDepth(root->right))) + 1;
    }
    const int maxOfTwo(const int &&first, const int &&second) const
    {
        return first > second ? first : second;
    }
    const int minOfTwo(const int &&first, const int &&second) const
    {
        return first < second ? first : second;
    }
};
// @lc code=end
