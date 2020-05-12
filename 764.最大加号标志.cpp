/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

// @lc code=start
class Solution
{
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines)
    {
        if (N & 1==0)
            N--;
        while (N)
        {
            bool n = false;
            for (vector<int> &vec : mines)
            {
                if ((vec[0] == N / 2 || vec[1] == N / 2) && vec[0] <= N && vec[1] <= N)
                {
                    n = true;
                    break;
                }
            }
            if (!n)
                return (N+1)/2;
            N-=2;
        }
        return 0;
    }
};
// @lc code=end
