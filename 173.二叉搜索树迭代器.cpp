/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */
#include <stack>
#include <queue>
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
class BSTIterator
{
private:
    TreeNode *cur;

public:
    BSTIterator(TreeNode *root)
    {
        cur = root;
    }

    /** @return the next smallest number */
    int next() //Morris
    {
        int ans = 0;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                ans = cur->val;
                cur = cur->right;
                break;
            }
            else
            {
                TreeNode *prev = cur->left;
                while (prev->right != NULL && prev->right != cur)
                    prev = prev->right;
                if (prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    prev->right = NULL;
                    ans = cur->val;
                    cur = cur->right;
                    break;
                }
            }
        }
        return ans;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return cur != NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
