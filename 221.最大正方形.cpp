/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int **dp_table = new int *[rows + 1];
        int ans = 0;
        for (int i = 0; i < rows + 1; ++i)
        {
            dp_table[i] = new int[cols + 1]();
        }
        for (int i = 1; i < rows + 1; i++)
        {
            for (int j = 1; j < cols + 1; j++)
            {
                if (matrix[i - 1][j - 1] == 49)
                {
                    dp_table[i][j] = 1 + minOfTwo(dp_table[i - 1][j], dp_table[i - 1][j - 1], dp_table[i][j - 1]);
                    ans = dp_table[i][j]>ans?dp_table[i][j]:ans;
                }
            }
        }
        return ans*ans;
    }
    int &&minOfTwo(int first, int second, int third)
    {
        int min = first < second ? first : second;
        return move(min < third ? min : third);
    }
};
// @lc code=end
