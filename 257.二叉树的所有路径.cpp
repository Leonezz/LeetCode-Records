/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include <vector>
#include <string>
#include <stack>
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == NULL)
            return vector<string>();
        vector<string> ans;
        string str;
        biaryTreePaths(root, str, ans);
        return ans;
    }
    void biaryTreePaths(TreeNode *root, string str, vector<string> &vec)
    {
        str.append(to_string(root->val));
        if (root->left == NULL && root->right == NULL)
        {
            vec.push_back(str);
            return;
        }
        if (root->left != NULL)
        {
            biaryTreePaths(root->left, str + "->", vec);
        }
        if (root->right != NULL)
        {
            biaryTreePaths(root->right, str + "->", vec);
        }
    }
};
// @lc code=end
