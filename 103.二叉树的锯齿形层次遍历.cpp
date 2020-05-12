/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * 看起来不难的一题，实际上却用了我几个小时！
 * 一开始的想法是用上一题的层序遍历+每层的标志来解决
 * 做着做着就发现不对了，这里直接卡了半天
 * 然后想到用一个队列+一个堆栈/两个堆栈，还是没做出来
 * 打开讨论区发现有人说每层的数目都是已知的
 * 这才想起来可以一次循环直接读取整层的节点
 * 这样每次读取的都是整层，不用费劲判断是否同层什么乱七八糟的
 * 跳出层序遍历的固定结构，稍微一点点改变，这题就迎刃而解了
 * 
 * [103] 二叉树的锯齿形层次遍历
 */
#include <stack>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> queue;
        if (root)
            queue.push(root);
        bool lr = true;
        while (!queue.empty())
        {
            int levelSize = queue.size();
            vector<int> vec(levelSize, 0);
            while (levelSize--)
            {
                TreeNode *t = queue.front();
                queue.pop();
                vec[lr ? vec.size() - levelSize - 1 : levelSize] = t->val;
                if (t->left)
                    queue.push(t->left);
                if (t->right)
                    queue.push(t->right);
            }
            lr = !lr;
            result.push_back(move(vec));
        }

        return result;
    }
};
// @lc code=end

int main()
{
}