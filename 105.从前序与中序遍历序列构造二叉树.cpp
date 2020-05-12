/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * 一开始的思路是递归然后构造新的向量向下传递，但是出了奇怪的运行时错误
 * 后来改用下标传参，各种+1-1的小细节整的头昏了，说明代码能力还不够
 * 居然忘了用左子树中序遍历序列的长度来截取前序遍历序列！
 * 
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder,
                        const int leftSideOfPre, const int rightSideOfPre,
                        const int leftSideOfIn, const int rightSideOfIn)
    {
        if (leftSideOfPre > rightSideOfPre || leftSideOfIn > leftSideOfIn)
            return NULL;
        TreeNode *root = new TreeNode(preorder[leftSideOfPre]);
        int rootOfIn = leftSideOfIn;
        while (rootOfIn <= rightSideOfIn && inorder[rootOfIn] != root->val)
            rootOfIn++;
        root->left = buildTree(preorder, inorder,
                               leftSideOfPre + 1, leftSideOfPre + rootOfIn - leftSideOfIn,
                               leftSideOfIn, rootOfIn);
        root->right = buildTree(preorder, inorder,
                                leftSideOfPre + rootOfIn - leftSideOfIn + 1, rightSideOfPre,
                                rootOfIn + 1, rightSideOfIn);
        return root;
    }
};
// @lc code=end
