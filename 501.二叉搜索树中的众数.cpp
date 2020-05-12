/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> findMode(TreeNode *root)
    {
        if (root == NULL)
            return vector<int>();
        stack<TreeNode *> stack;
        vector<int> ans;
        TreeNode *t = root;
        int prev = 0;
        int cnt = 0;
        int maxCnt = 0;
        while (t != NULL || !stack.empty())
        {
            while (t != NULL)
            {
                stack.push(t);
                t = t->left;
            }
            if (!stack.empty())
            {
                t = stack.top();
                stack.pop();
                int cur = t->val;
                if (cnt == 0)
                    prev = cur;
                if (prev == cur)
                    cnt++;
                else
                {
                    if (maxCnt < cnt)
                    {
                        ans = vector<int>(1, prev);
                    }
                    else if (maxCnt == cnt)
                    {
                        ans.push_back(prev);
                    }
                    maxCnt = cnt > maxCnt ? cnt : maxCnt;
                    prev = cur;
                    cnt = 1;
                }

                t = t->right;
            }
        }
        if (maxCnt < cnt)
        {
            ans = vector<int>(1, prev);
        }
        else if (maxCnt == cnt)
        {
            ans.push_back(prev);
        }
        return ans;
    }
};
// @lc code=end
