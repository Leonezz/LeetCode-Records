/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int findSecondMinimumValue(TreeNode *root)
    {
        queue<TreeNode *> queue;
        queue.push(root);
        int minOfTree = INT_MAX;
        bool minChanged = false;
        int secondMinOfTree = INT_MAX;
        bool secChanged = false;
        while (!queue.empty())
        {
            int size = queue.size();
            while (size--)
            {
                TreeNode *t = queue.front();
                queue.pop();
                if (t->left != NULL)
                {
                    queue.push(t->left);
                    queue.push(t->right);
                }
                if (t->val < minOfTree ||
                    ((t->val == INT_MAX) && (minOfTree == INT_MAX)))
                {
                    minChanged = true;
                    minOfTree = t->val;
                }
                if ((t->val > minOfTree && t->val < secondMinOfTree) ||
                    ((t->val == INT_MAX) && (secondMinOfTree == INT_MAX)))
                {
                    secChanged = true;
                    secondMinOfTree = t->val;
                }
            }
        }

        if (minChanged && minOfTree != root->val)
            return minOfTree;
        if (secChanged && secondMinOfTree != root->val && secondMinOfTree)
            return secondMinOfTree;
        return -1;
    }
};
// @lc code=end
