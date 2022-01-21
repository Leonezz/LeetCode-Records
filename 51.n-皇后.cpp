/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        helper(board, 0, n);
        return ans;
    }
    void helper(vector<string> &board, int row, int n)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (!isValid(board, row, i, n))
                continue;
            board[row][i] = 'Q';
            helper(board, row + 1, n);
            board[row][i] = '.';
        }
    }
    bool isValid(const vector<string> &board, int row, int col, int n)
    {
        for (int i = 0; i < row; ++i)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    vector<vector<string>> ans;
};
// @lc code=end
