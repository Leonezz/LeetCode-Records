/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * 题目较为简单
 * 需要注意的是从数组中取树的根节点时，需要对mid进行一次向上取整
 * 否则得到的不是二叉搜索树
 * 
 * [108] 将有序数组转换为二叉搜索树
 */
#include <vector>
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
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    TreeNode *sortedArrayToBST(vector<int> &nums, const int left, const int right)
    {
        if (left > right)
            return NULL;
        TreeNode *root = new TreeNode(nums[(left + right + 1) / 2]);
        root->left = sortedArrayToBST(nums, left, (left + right + 1) / 2 - 1);
        root->right = sortedArrayToBST(nums, (left + right + 1) / 2 + 1, right);
        return root;
    }
};
// @lc code=end
//l = 0
//r = 4
//m = 2
//0 1 0

//0,-10,5,null,-3,null,9