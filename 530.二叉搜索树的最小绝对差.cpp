/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */
#include <initializer_list>
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
    int getMinimumDifference(TreeNode *root)
    {
        stack<TreeNode *> stack;
        TreeNode *t = root;
        int min = INT_MAX;
        TreeNode *prev = NULL;
        while (t != NULL || !stack.empty())
        {
            while (t != NULL)
            {
                stack.push(t);
                t = t->left;
            }
            if (!stack.empty())
            {
                t = stack.top();
                stack.pop();
                if (prev != NULL)
                {
                    min = getMin({min, absMinus(t->val, prev->val)});
                }
                prev = t;
                t = t->right;
            }
        }
        return min;
    }
    int &&absMinus(int first, int second)
    {
        return first > second ? move(first - second) : move(second - first);
    }
    int getMin(std::initializer_list<int> args)
    {
        int min = INT_MAX;
        std::initializer_list<int>::iterator it = args.begin();
        while (it != args.end())
        {
            if (*it < min)
                min = *it;
            it++;
        }
        return min;
    }
};
// @lc code=end
