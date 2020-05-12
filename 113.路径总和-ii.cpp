/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
private:
    vector<vector<int>> result;
    vector<int> vec;

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        dfs(root, sum);
        return this->result;
    }
    void dfs(TreeNode *root, const int sum)
    {
        if (root == NULL)
            return;
        vec.push_back(root->val);
        if (root->left == NULL && root->right == NULL && sum == root->val)
            result.push_back(vec);
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        vec.pop_back();
    }
};
// @lc code=end
