/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int height = getHeight(root);
        int left = 1;
        int right = (1 << (height - 1)) - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (isIndexNodeExit(root, height - 1, mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left + (1 << height - 1) - 1;
    }
    int getHeight(TreeNode *root)
    {
        int h = 0;
        while (root != NULL)
        {
            h++;
            root = root->left;
        }
        return h;
    }
    bool isIndexNodeExit(TreeNode *root, int depth, int index)
    {
        int left = 0;
        int right = (1 << depth) - 1;
        while (depth--)
        {
            int mid = (left + right) >> 1;
            if (index > mid)
            {
                root = root->right;
                left = mid + 1;
            }
            else
            {
                root = root->left;
                right = mid;
            }
        }
        return root != NULL;
    }
};
// @lc code=end
