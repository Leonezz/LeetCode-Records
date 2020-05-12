/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * +1/-1的小操作太烦了
 * 
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder,
                        const int leftSideIn, const int rightSideIn,
                        const int leftSidePost, const int rightSidePost)
    {
        if (leftSideIn > rightSideIn || leftSidePost > rightSidePost)
            return NULL;
        TreeNode *root = new TreeNode(postorder[rightSidePost]);
        int rootIn = leftSideIn;
        while (rootIn <= rightSideIn && inorder[rootIn] != root->val)
        {
            rootIn++;
        }
        const int leftLength = rootIn - leftSideIn;
        root->left = buildTree(inorder, postorder,
                               leftSideIn, rootIn - 1,
                               leftSidePost, leftSidePost + leftLength - 1);
        root->right = buildTree(inorder, postorder,
                                rootIn + 1, rightSideIn,
                                leftSidePost + leftLength, rightSidePost - 1);
        return root;
    }
};
// @lc code=end
