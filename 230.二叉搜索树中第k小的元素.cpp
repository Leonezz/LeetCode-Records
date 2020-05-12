/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> stack;
        TreeNode *t = root;
        while (t != NULL || !stack.empty())
        {
            while (t != NULL)
            {
                stack.push(t);
                t = t->left;
            }
            if (!stack.empty())
            {
                t = stack.top();
                stack.pop();
                if (--k == 0)
                {
                    return t->val;
                }
                t = t->right;
            }
        }
        return 0;
    }
};
// @lc code=end
