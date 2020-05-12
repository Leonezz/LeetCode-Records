/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> tree;
        preOrder(root,tree);
        int start = 0;
        int end = tree.size()-1;
        if(start==end)return false;
        while (start<end)
        {
            int sum = tree[start]+tree[end];
            if(sum==k)return true;
            if(sum>k)end--;
            else start++;
        }
        return false;
    }
    void preOrder(TreeNode*root,vector<int>& vec){
        if(root==NULL)return;
        preOrder(root->left,vec);
        vec.push_back(root->val);
        preOrder(root->right,vec);
    }
};
// @lc code=end
