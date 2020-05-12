/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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
    vector<vector<string>> printTree(TreeNode *root)
    {
        int height = getMaxHeight(root);
        int cols = (1 << height) - 1;
        vector<vector<string>> ans(height,
                                   vector<string>(cols, ""));
        printTree(ans, root, 0, ans[0].size() - 1, 0);
        return ans;
    }
    void printTree(vector<vector<string>> &ans, TreeNode *root, int left, int right, int level)
    {
        if (root == NULL)
            return;
        int mid = (left + right) / 2;
        ans[level][mid] = to_string(root->val);
        printTree(ans, root->left, left, mid - 1, level + 1);
        printTree(ans, root->right, mid + 1, right, level + 1);
    }
    int getMaxHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + maxOfTwo(getMaxHeight(root->left), getMaxHeight(root->right));
    }
    int maxOfTwo(int first, int second)
    {
        return first > second ? first : second;
    }
};
// @lc code=end
