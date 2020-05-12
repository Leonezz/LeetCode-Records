/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */
#include <vector>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 看起来很可怕的一题，要把所有可能的二叉搜索树构造出来
 * 先想了想应该是要递归解决，根据96题的经验可以确定以从1到n分别作为根节点为切入点
 * 假设根节点是i，那么[1,i-1]这部分肯定是左子树，[i+1,n]这部分是右子树
 * 对于左子树和右子树再分别递归调用，一直到[left,right]这个区间是空集，这时说明该子树无法构造
 * 应该返回一个空向量
 * 函数返回说明递归开始出栈，这时返回到的递归层次是上一步返回空子树的根节点
 * 
 * 基于这样的思想，首先对i在[1,n]区间上做循环，i是跟节点
 * 然后分别递归调用在[1,i-1]和[i+1,n]区间上计算左右子树
 * 等待两步递归都返回时就得到了根节点i的左右子树所有可能
 * 分别在左右子树向量上循环，把子树挂到根节点上，同时把所有可能压进向量result
 * 最后循环退出向量result中储存的就是所有的二叉搜索树
 */

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
    vector<TreeNode *> generateTrees(int n)
    {
        if (n > 0)
            return generateTrees(1, n);
        else
            return std::vector<TreeNode *>();
    }
    std::vector<TreeNode *> generateTrees(const int left, const int right)
    {
        std::vector<TreeNode *> result;
        if (left > right)
        {
            result.push_back(NULL);
            return result;
        }
        for (int i = left; i < right + 1; ++i)
        {
            std::vector<TreeNode *> leftTrees = generateTrees(left, i - 1);
            std::vector<TreeNode *> rightTrees = generateTrees(i + 1, right);
            for (int l = 0; l < leftTrees.size(); ++l)
            {
                for (int r = 0; r < rightTrees.size(); ++r)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = leftTrees[l];
                    node->right = rightTrees[r];
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};
// @lc code=end
int main()
{
}