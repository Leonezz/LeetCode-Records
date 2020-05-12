/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "-";
        stack<TreeNode *> stack;
        TreeNode *t = root;
        string ans;
        while (t != NULL || !stack.empty())
        {
            while (t != NULL)
            {
                ans += to_string(t->val) + ',';
                stack.push(t);
                t = t->left;
            }
            if (!stack.empty())
            {
                t = stack.top();
                if (t->left == NULL)
                    ans += "-,";
                if (t->right == NULL)
                    ans += "-,";
                stack.pop();
                t = t->right;
            }
        }
       // cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream iss(data);
        queue<string> vec;
        while (!iss.eof())
        {
            string str;
            getline(iss, str, ',');
            if (!str.empty())
                vec.push(move(str));
        }
        return deserializeH(vec);
    }
    TreeNode *deserializeH(queue<string> &vec)
    {
        if (vec.empty())
            return NULL;
        string node = vec.front();
        vec.pop();
        if (node == "-")
            return NULL;
        TreeNode *root = new TreeNode(stoi(node));
        root->left = deserializeH(vec);
        root->right = deserializeH(vec);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->right->left = new TreeNode(4);
    tree->right->right = new TreeNode(5);
    Codec c;
    c.deserialize(c.serialize(tree));
}
