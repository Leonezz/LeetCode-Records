/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int longestUnivaluePath(TreeNode *root)
    {
        if(root==NULL)return 0;
        int m = 0;
        longest(root,root->val,m);
        return m;
    }
    int longest(TreeNode *root, int val,int &maxL)
    {
        if (root == NULL)
            return 0;
        int left = longest(root->left,root->val,maxL);
        int right = longest(root->right,root->val,maxL);
        maxL = max(maxL,left+right);
        if(root->val==val)return max(left,right)+1;
        return 0;
    }
    int max(int first,int second){
        return first>second?first:second;
    }
};
// @lc code=end
