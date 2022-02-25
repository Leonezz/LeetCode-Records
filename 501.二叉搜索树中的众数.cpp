/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
using namespace std;
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
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        int maxTimes = 0;
        int curTimes = 1;
        vector<int> ans;
        TreeNode* node = NULL;
        inOrder(node, root, maxTimes, curTimes, ans);
        return ans;
    }
    void inOrder(TreeNode*& pre, TreeNode* cur, int& maxTimes, int& curTimes, vector<int>& res)
    {
        if(!cur)return;
        inOrder(pre, cur->left, maxTimes, curTimes, res);
        if(pre){
            curTimes = (pre->val == cur->val) ? curTimes + 1 : 1;
        }
        if(curTimes == maxTimes)res.push_back(cur->val);
        else if(curTimes > maxTimes){
            maxTimes = curTimes;
            res.clear();
            res.push_back(cur->val);
        }
        pre = cur;
        inOrder(pre, cur->right, maxTimes, curTimes, res);
    }
};
// @lc code=end
