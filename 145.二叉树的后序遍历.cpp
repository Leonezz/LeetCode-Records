/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> stack;
        TreeNode *t = root;
        vector<int> result;
        while (t != NULL || !stack.empty())
        {
            while (t != NULL)
            {
                stack.push(t);
                t = t->left;
            }
            if (!stack.empty())
            {
                TreeNode *tCopy = new TreeNode(0);
                t = stack.top();
                stack.pop();
                tCopy->val = t->val;
                t = t->right;
                if (t != NULL)
                {
                    stack.push(tCopy);
                }
                else
                {
                    result.push_back(tCopy->val);
                }
            }
        }
        return result;
    }
};
// @lc code=end
