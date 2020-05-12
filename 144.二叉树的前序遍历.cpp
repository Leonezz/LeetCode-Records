/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include <vector>
#include <stack>
using namespace std;
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> stack;
        TreeNode *t = root;
        vector<int> result;
        while (t != NULL || !stack.empty())
        {
            while (t != NULL)
            {
                stack.push(t);
                result.push_back(t->val);
                t = t->left;
            }
            if (!stack.empty())
            {
                t = stack.top();
                stack.pop();
                t = t->right;
            }
        }
        return result;
    }
};
// @lc code=end
