/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * 题目简单，没想到的是多次重复计算的迭代代码居然跑的不错
 * 
 * [110] 平衡二叉树
 */
#include <unordered_map>
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
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        const int lH = getHeight(root->left);
        const int rH = getHeight(root->right);
        const int minus = lH > rH ? lH - rH : rH - lH;
        if (minus > 1)
            return false;
        else
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
    int getHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            return maxOfTwo(move(getHeight(root->left)),
                                            move(getHeight(root->right))) +
                                   1;
        }
    }
    int maxOfTwo(const int &&first, const int &&second)
    {
        return first > second ? first : second;
    }
};
// @lc code=end
