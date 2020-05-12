/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * 一开始就想到了要用遍历找到错误来判断
 * 第一遍没看讨论区想着判断出不符合t->val>t->left->val&&t->val<t->right->val的情况就行
 * 于是就用了层序遍历，实际上这种判断只能确定父子正确性，无法获知爷孙正确性
 * 打开讨论区看到别人都是用的中序遍历
 * 中序遍历按照left---root---right的顺序访问
 * 先创建一个pre节点，对于每个访问到的节点，判断其是否>该pre节点，若是则更新pre为当前节点
 * 因为遍历顺序的关系，pre节点有三种情况
 * 1. pre节点是当前节点的左子节点
 * 2. 当前节点是pre节点的右子节点（巧妙）
 * 3. pre节点位于当前节点的左子树的右子树上（巧妙）
 * 基于上述三点可确定该算法是正确的
 * 
 * [98] 验证二叉搜索树
 */

#include <stack>
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
    bool isValidBST(TreeNode *root)
    {
        TreeNode *t = root;
        std::stack<TreeNode *> stack;
        long long preNodeVal = LLONG_MIN;
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
                if (t->val <= preNodeVal)
                    return false;
                preNodeVal = t->val;
                t = t->right;
            }
        }
        return true;
    }
};
// @lc code=end
int main() {}
