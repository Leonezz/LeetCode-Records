/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include <vector>
using namespace std;
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
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<TreeNode *> stack;
        TreeNode *t = root;
        std::vector<int> inorder;
        while (t || stack.size()!=0)
        {
            while (t)
            {
                stack.push_back(t);
                t = t->left;
            } //转向最左
            if (stack.size()!=0)
            {
                t = stack.back();
                stack.pop_back(); //取出最左的节点（这个节点的左子树已经访问过）
                inorder.push_back(t->val);
                t = t->right; //
            }
        }
        return inorder;
    }
};


// @lc code=end
int main()
{

}