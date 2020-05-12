/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int length = getMaxHeight(root->left) + getMaxHeight(root->right);
        return maxOfThree(length, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
    }
    int &&maxOfThree(int first, int second, int third)
    {
        int max = maxOfTwo(first, second);
        return move(maxOfTwo(max, third));
    }
    int &&maxOfTwo(int first, int second)
    {
        return move(first > second ? first : second);
    }
    int &&getMaxHeight(TreeNode *root)
    {
        if (root == NULL)
            return move(0);
        return move(maxOfTwo(getMaxHeight(root->left), getMaxHeight(root->right)) + 1);
    }
};
// @lc code=end
