/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode *root)
    {
        unordered_map<int, vector<unsigned long long>> map;
        int ans = 0;
        dfs(map, 0, 1, ans, root);
        return ans;
    }
    void dfs(unordered_map<int, vector<unsigned long long>> &map, int level, unsigned long long index, int &max, TreeNode *root)
    {
        if (root == NULL)
            return;
        map[level].push_back(index);
        if (map[level].size() > 0)
            max = index - map[level][0] + 1 > max ? index - map[level][0] + 1 : max;
        dfs(map, level + 1, 2 * index, max, root->left);
        dfs(map, level + 1, 2 * index + 1, max, root->right);
    }
};
// @lc code=end
