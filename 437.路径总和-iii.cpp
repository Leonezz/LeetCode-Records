/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
private:
    int cnt;
public:
    int pathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return 0;
        dfs(root, sum, cnt);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return cnt;
    }
    void dfs(TreeNode *root, int sum, int &cnt)
    {
        if (root == NULL)
            return;
        if (root->val == sum)
            cnt++;
        dfs(root->left, sum - root->val, cnt);
        dfs(root->right, sum - root->val, cnt);
    }
};
// @lc code=end
