/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序查找树
 */
#include <stack>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        if (!root || (!root->left && !root->right))
            return root;
        stack<TreeNode *> stack;
        TreeNode* t = root;
        vector<int> vec;
        while (t || !stack.empty())
        {
            while (t)
            {
                stack.push(t);
                t = t->left;
            }
            if(!stack.empty())
            {
                t = stack.top();
                stack.pop();
                vec.push_back(t->val);
                t = t->right;
            }
        }
        TreeNode* ans = new TreeNode(vec[0]);
        TreeNode* res = ans;
        for(int i = 1;i < vec.size();++i)
        {
            ans->right = new TreeNode(vec[i]);
            ans->left = nullptr;
            ans = ans->right;
        }
        return res;
    }
};
// @lc code=end
