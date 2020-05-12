/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, pair<int,TreeNode*>> map;
        vector<TreeNode *> ans;
        treeToString(root,map);
        for(auto pair:map){
            if(pair.second.first>1)ans.push_back(pair.second.second);
        }
        return ans;
    }
    string treeToString(TreeNode *root,unordered_map<string, pair<int,TreeNode*>>& map)
    {
        if (root == NULL)
            return "#";
        string s = to_string(root->val);
        s += treeToString(root->left,map);
        s += treeToString(root->right,map);
        map[s].first++;
        map[s].second = root;
        return s;
    }
};
// @lc code=end
