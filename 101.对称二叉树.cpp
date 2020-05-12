/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * 虽然是简单题，但我看来还是挺难的
 * 莫名其妙写出个递归居然一次过了！
 * 
 * 根据写好的尾递归想出了迭代的算法
 * 也一次过了
 * [101] 对称二叉树
 */
#include <queue>
#include <stack>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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
    bool isSymmetric(TreeNode *root)
    {
        //return isSymmetric(root, root);
        if (root == NULL)
            return true;
        std::stack<TreeNode *> stack;
        TreeNode *t = root;
        stack.push(t);
        stack.push(t);
        while (stack.size() > 1)
        {
            TreeNode *t1 = stack.top();
            stack.pop();
            TreeNode *t2 = stack.top();
            stack.pop();
            if (t1->val != t2->val)
                return false;
            if (t1->left && t2->right)
            {
                stack.push(t1->left);
                stack.push(t2->right);
            }
            else if (t1->left == NULL && t2->right == NULL)
            {
            }
            else
                return false;
            if (t1->right && t2->left)
            {
                stack.push(t1->right);
                stack.push(t2->left);
            }
            else if (t1->right == NULL && t2->left == NULL)
            {
            }
            else
                return false;
        }
        return true;
    }
    /* bool isSymmetric(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;
        if (left->val == right->val)
            return isSymmetric(left->left, right->right) &&
                   isSymmetric(left->right, right->left);
        else
            return false;
    }*/
};
// @lc code=end
