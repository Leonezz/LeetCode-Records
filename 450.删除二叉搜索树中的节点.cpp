/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left != NULL && root->right != NULL)
            {
                TreeNode *left = root->left;
                TreeNode *leftPos = root->right;
                while (leftPos != NULL && leftPos->left != NULL)
                    leftPos = leftPos->left;
                leftPos->left = left;
                return root->right;
            }
            else if (root->left != NULL)
                return root->left;
            else if (root->right != NULL)
                return root->right;
            else
                return NULL;
        }
        return root;
    }
};
// @lc code=end
