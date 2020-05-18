/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * 题目较为简单，被要求输出[]，实际输出了[[]]卡了一手
 * 于一般的中序遍历相比，本题区别在于需要把不同层的元素装到不同的vector中
 * 很自然的想到用一个数字curLevelNodesCnt标明本层还有多少个没装
 * 如果本层已经装完了，就新建一个vector给下一层
 * 由于装本层的同时中序遍历已经开始把下一层的节点装进队列了
 * 所以还需要一个数字nextLevelNodesCnt表明下一层有多少节点
 * 当本层的结点数curLevelNodesCnt == 0时
 * 把下层节点数nextLevelNodesCnt赋给curLevelNodesCnt然后把nextLevelNodesCnt清零
 * 
 * [102] 二叉树的层序遍历
 */
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return vector<vector<int>>();
        queue<TreeNode *> queue;
        queue.push(root);
        vector<vector<int>> ans;
        while (!queue.empty())
        {
            int size = queue.size();
            vector<int> level;
            while(size--){
                TreeNode* cur = queue.front();
                queue.pop();
                level.push_back(cur->val);
                if(cur->left)queue.push(cur->left);
                if(cur->right)queue.push(cur->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
// @lc code=end
