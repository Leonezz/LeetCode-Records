/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * 简单题，某些边界条件出了点错误
 * 感觉应该有更优雅的解法
 * 
 * 这题用递归居然更快
 * 
 * [100] 相同的树
 */
#include <queue>


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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        else if (p && q)
        {
        }
        else
            return false;
        TreeNode *pCopy = p;
        TreeNode *qCopy = q;
        std::queue<TreeNode *> pQueue;
        std::queue<TreeNode *> qQueue;
        pQueue.push(pCopy);
        qQueue.push(qCopy);
        while (!pQueue.empty() && !qQueue.empty())
        {
            TreeNode *tempP = pQueue.front();
            pQueue.pop();
            TreeNode *tempQ = qQueue.front();
            qQueue.pop();

            if (tempP->val != tempQ->val)
                return false;
            if (tempP->left && tempQ->left)
            {
                pQueue.push(tempP->left);
                qQueue.push(tempQ->left);
            }
            else if (tempP->left == NULL && tempQ->left == NULL)
            {
            }
            else
                return false;
            if (tempP->right && tempQ->right)
            {
                pQueue.push(tempP->right);
                qQueue.push(tempQ->right);
            }
            else if (tempP->right == NULL && tempQ->right == NULL)
            {
            }
            else
                return false;
        }
        if (pQueue.empty() && qQueue.empty())
            return true;
        return false;
    }
};

// @lc code=start

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
};

// @lc code=end
