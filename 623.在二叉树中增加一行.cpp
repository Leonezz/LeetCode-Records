/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode *addOneRow(TreeNode *root, int v, int d)
    {
        if (d == 1)
        {
            TreeNode *t = new TreeNode(v);
            t->left = root;
            return t;
        }
        queue<TreeNode *> queue;
        if (root != NULL)
            queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            d--;
            while (size--)
            {
                TreeNode *t = queue.front();
                queue.pop();
                if (d == 1)
                {
                    TreeNode *left = new TreeNode(v);
                    TreeNode *right = new TreeNode(v);
                    left->left = t->left;
                    right->right = t->right;
                    t->left = left;
                    t->right = right;
                }
                if(t->left!=NULL)queue.push(t->left);
                if(t->right!=NULL)queue.push(t->right);
            }
            if (d == 1)
                return root;
        }
        return root;
    }
};
// @lc code=end
