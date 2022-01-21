/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <vector>
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        while (true)
        {
            for (int i = left; i <= right; ++i)
                ans.push_back(matrix[top][i]);
            if (++top > bottom)
                break;
            for (int i = top; i <= bottom; ++i)
                ans.push_back(matrix[i][right]);
            if (--right < left)
                break;
            for (int i = right; i >= left; --i)
                ans.push_back(matrix[bottom][i]);
            if (--bottom < top)
                break;
            for (int i = bottom; i >= top; --i)
                ans.push_back(matrix[i][left]);
            if (++left > right)
                break;
        }
        return ans;
    }
};
// @lc code=end
