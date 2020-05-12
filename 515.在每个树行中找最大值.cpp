/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>queue;
        if(root!=NULL)queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            int max = INT_MIN;
            while (size--)
            {
                TreeNode*t = queue.front();
                queue.pop();
                if(t->val>max)max = t->val;
                if(t->left!=NULL)queue.push(t->left);
                if(t->right!=NULL)queue.push(t->right);
            }
            ans.push_back(max);
        }
        return ans;
    }
};
// @lc code=end

