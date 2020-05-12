/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * 简单题，可以直接层序遍历+堆栈解决
 * 
 * [107] 二叉树的层次遍历 II
 */
#include <stack>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> queue;
        if (root)
            queue.push(root);
        stack<vector<int>> levels;
        while (!queue.empty())
        {
            vector<int> vec;
            int levelSize = queue.size();
            while (levelSize--)
            {
                TreeNode *t = queue.front();
                queue.pop();
                vec.push_back(t->val);
                if (t->left)
                    queue.push(t->left);
                if (t->right)
                    queue.push(t->right);
            }
            levels.push(move(vec));
        }
        while (!levels.empty())
        {
            result.push_back(move(levels.top()));
            levels.pop();
        }
        return result;
    }
};
// @lc code=end
