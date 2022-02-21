/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */
#define NULL 0
#include <vector>
using namespace std;
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;
    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        Node *root = new Node(grid[0][0], true);
        constructLeaf(0, 0, grid.size(), grid.size(), grid, root);
        return root;
    }
    void constructLeaf(int left, int top, int right, int bottom, const vector<vector<int>> &grid, Node *root)
    {
        if (isLeaf(left, top, right, bottom, grid))
            return;
        root->isLeaf = false;
        root->topLeft = new Node(grid[top][left], true);
        root->topRight = new Node(grid[top][right - 1], true);
        root->bottomLeft = new Node(grid[bottom - 1][left], true);
        root->bottomRight = new Node(grid[bottom - 1][right - 1], true);
        if (left + 2 == right)
            return;
        constructLeaf(left, top, (left + right) / 2, (top + bottom) / 2, grid, root->topLeft);
        constructLeaf((left + right) / 2, top, right, (top + bottom) / 2, grid, root->topRight);
        constructLeaf(left, (top + bottom) / 2, (left + right) / 2, bottom, grid, root->bottomLeft);
        constructLeaf((left + right) / 2, (top + bottom) / 2, right, bottom, grid, root->bottomRight);
    }
    bool isLeaf(int left, int top, int right, int bottom, const vector<vector<int>> &grid)
    {
        int temp = grid[top][left];
        for (; top < bottom; ++top)
            for (int left_t = left; left_t < right; ++left_t)
            {
                if (temp != grid[top][left_t])
                    return false;
            }
        return true;
    }
};

// @lc code=end
int main(){
    vector<vector<int> > grid = 
    {
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0}
    };
    Solution so;
    so.construct(grid);
}