/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> queue;
        if (root != NULL)
            queue.push(root);
        while (!queue.empty())
        {
            ans.push_back(queue.front()->val);
            int size = queue.size();
            while (size--)
            {
                TreeNode *t = queue.front();
                queue.pop();
                if (t->right != NULL)
                    queue.push(t->right);
                if (t->left != NULL)
                    queue.push(t->left);
            }
        }
        return ans;
    }
};
// @lc code=end
