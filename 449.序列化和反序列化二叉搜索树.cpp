/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "#,";
        string s = to_string(root->val) + ",";
        s += serialize(root->left);
        s += serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty() || data == "#,")
            return NULL;
        stringstream iss(data);
        vector<string> vec;
        while (!iss.eof())
        {
            string str;
            getline(iss, str, ',');
            if (!str.empty())
                vec.push_back(move(str));
        }
        return deserialize(vec, 0, vec.size() - 1);
    }
    TreeNode *deserialize(vector<string> &vec, int start, int end)
    {
        if (start == end||vec[start]=="#")
            return NULL;
        TreeNode *root = new TreeNode(stoi(vec[start]));
        int i = 0;
        for (i = start + 1; i < end; ++i)
        {
            if (vec[i] != "#" && stoi(vec[i]) > stoi(vec[start]))
                break;
        }
        root->left = deserialize(vec, start + 1, i);
        root->right = deserialize(vec, i, end);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
