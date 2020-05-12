/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> queue;
        queue.push(root);
        TreeNode *t = queue.front();
        while (!queue.empty())
        {
            t = queue.front();
            int size = queue.size();
            while (size--)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if (node->left != NULL)
                    queue.push(node->left);
                if (node->right != NULL)
                    queue.push(node->right);
            }
        }
        return t->val;
    }
};
// @lc code=end
