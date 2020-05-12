/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        queue<TreeNode *> queue;
        if (root != NULL)
            queue.push(root);
        while (!queue.empty())
        {
            const int size = queue.size();
            double sum = 0.0;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *t = queue.front();
                queue.pop();
                if (t->left != NULL)
                    queue.push(t->left);
                if (t->right != NULL)
                    queue.push(t->right);
                sum += t->val;
            }
            ans.push_back(sum/size);
        }
        return ans;
    }
};
// @lc code=end
