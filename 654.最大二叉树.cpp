/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return construct(nums, 0, nums.size());
    }
    TreeNode *construct(vector<int> &nums, int start, int end)
    {
        int maxIdx = findMaxIndex(nums, start, end);
        if (maxIdx == -1)
            return NULL;
        TreeNode *root = new TreeNode(nums[maxIdx]);
        root->left = construct(nums, start, maxIdx);
        root->right = construct(nums, maxIdx + 1, end);
        return root;
    }
    int findMaxIndex(vector<int> &nums, int start, int end)
    {
        if (start >= end)
            return -1;
        int max = 0;
        unordered_map<int, int> map;
        for (int i = start; i < end; ++i)
        {
            max = nums[i] > max ? nums[i] : max;
            map[nums[i]] = i;
        }
        return map[max];
    }
};
// @lc code=end
