/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * 没整懂
 * 
 * [117] 填充每个节点的下一个右侧节点指针 II
 */
#include <queue>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        dfs(root);
        return root;
    }
    void dfs(Node *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        if (root->left != NULL && root->right != NULL)
            root->left->next = root->right;
        Node *next = root->next;
        Node *left = root->right != NULL ? root->right : root->left;
        while (next != NULL)
        {
            if (next->left != NULL)
            {
                left->next = next->left;
                break;
            }
            else if (next->right != NULL)
            {
                left->next = next->right;
                break;
            }
            next = next->next;
        }
        dfs(root->right);
        dfs(root->left);
    }
};
// @lc code=end
