/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 */
#include <vector>
#include <unordered_map>
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
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        if (root == NULL)
            return vector<int>();
        unordered_map<int, int> map;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            while (size--)
            {
                TreeNode *t = queue.front();
                queue.pop();
                int sum = subTreeSum(t);
                if (map.find(sum) != map.end())
                {
                    map[sum]++;
                }
                else
                    map[sum] = 1;
                if (t->left != NULL)
                    queue.push(t->left);
                if (t->right != NULL)
                    queue.push(t->right);
            }
        }
        vector<int> ans;
        int maxTimes = 0;
        for (const pair<int, int> &pair : map)
        {
            int times = pair.second;
            if (times > maxTimes)
            {
                ans = vector<int>(1, pair.first);
                maxTimes = times;
            }
            else if (times == maxTimes)
                ans.push_back(pair.first);
        }
        return ans;
    }
    int subTreeSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return root->val + subTreeSum(root->left) + subTreeSum(root->right);
    }
};
// @lc code=end
