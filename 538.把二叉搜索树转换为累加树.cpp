/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*>stack;
        TreeNode *cur = root;
        TreeNode *prev = NULL;
        while (cur!=NULL||!stack.empty())
        {
            while (cur!=NULL)
            {
                stack.push(cur);
                cur = cur->right;
            }
            if(!stack.empty()){
                cur = stack.top();
                stack.pop();
                if(prev!=NULL){
                    cur->val+=prev->val;
                }
                prev = cur;
                cur=cur->left;
            }
        }
        return root;
    }

};
// @lc code=end

