/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *right = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right)
            root = root->right;
        root->right = right;
        root = right;
    }
    /*void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        stack<TreeNode *> stack;
        TreeNode *t = root;
        while (t || !stack.empty())
        {
            while (t)
            {
                stack.push(t);
                t = t->left;
            }
            if (!stack.empty())
            {
                TreeNode *n = stack.top();
                stack.pop();
                TreeNode *temp = n->right;
                n->right = n->left;
                n->left = NULL;
                while (n->right)
                    n = n->right;
                n->right = temp;
                t = temp;
            }
        }
    }*/
};
// @lc code=end
int main() {}