/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
    struct node_status
    {
        int choiceA;
        int choiceB;
    };

public:
    int rob(TreeNode *root)
    {
        if (!root)
            return 0;
        struct node_status rootStatus = dfs(root);
        return rootStatus.choiceA > rootStatus.choiceB
                   ? rootStatus.choiceA
                   : rootStatus.choiceB;
    }
    struct node_status dfs(TreeNode *root)
    {
        if (!root)
        {
            return {0, 0};
        }
        struct node_status leftStatus = dfs(root->left);
        struct node_status rightStatus = dfs(root->right);
        int choiceA = root->val + leftStatus.choiceB + rightStatus.choiceB;
        int choiceB = (leftStatus.choiceA > leftStatus.choiceB
                          ? leftStatus.choiceA
                      : leftStatus.choiceB) + (rightStatus.choiceA > rightStatus.choiceB
                          ? rightStatus.choiceA
                          : rightStatus.choiceB);
        return {choiceA, choiceB};
    }
};
// @lc code=end
