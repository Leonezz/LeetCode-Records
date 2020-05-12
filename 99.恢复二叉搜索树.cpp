/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * 这题是在没有打开讨论区的情况下完成的，值得鼓励
 * 
 * 这个解基于一个十分朴素的想法，效率也十分朴素。。
 * 有了98题验证二叉搜索树的基础，我想到可以在判断BSD正确性的时候把错误的两个节点指针保存下来
 * 然后直接交换这两个节点
 * 由于交换过后仍不能保证BSD是正确的，就迭代着验证+交换
 * 相信在若干次迭代过后BSD会变成正确的
 * 
 * BSD验证过程中用到的二叉树中序遍历空间复杂度是O(log n)的
 * 没有做到题目要求的常数空间复杂度
 * 
 * [99] 恢复二叉搜索树
 */
#include <stack>
#include <queue>
#include <iostream>
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
    void recoverTree(TreeNode *root)
    {
        TreeNode *pre = NULL;
        std::stack<TreeNode *> stack;
        TreeNode *t = root;
        while (!isBSDValid(t, pre))
            ;
    }
    bool isBSDValid(TreeNode *t, TreeNode *pre)
    {
        std::stack<TreeNode *> stack;
        while (t || !stack.empty())
        {
            while (t)
            {
                stack.push(t);
                t = t->left;
            }
            if (!stack.empty())
            {
                t = stack.top();
                stack.pop();
                if (pre != NULL && t->val <= pre->val)
                {
                    int val = pre->val;
                    pre->val = t->val;
                    t->val = val;

                    return false;
                }
                pre = t;
                t = t->right;
            }
        }
        return true;
    }
};
// @lc code=end

void levelOrder(TreeNode *root)
{
    TreeNode *t = root;
    std::queue<TreeNode *> queue;
    queue.push(t);
    std::cout << '[';
    while (!queue.empty())
    {
        TreeNode *cur = queue.front();
        queue.pop();
        if (cur)
        {
            std::cout << cur->val;
            queue.push(cur->left);
            queue.push(cur->right);
        }
        else
            std::cout << "null";
        std::cout << ",";
    }
    std::cout << ']';
}

int main()
{
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(3);
    t->left->right = new TreeNode(2);

    levelOrder(t);

    //std::cout << Solution().isBSDValid(t, nullptr, nullptr);
    Solution().recoverTree(t);

    levelOrder(t);
}

//1,3,2
//1,2,3
//3,2,1
//3,1,2
