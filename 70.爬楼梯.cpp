/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 1;
        if (n <= 3)
            return n;
        int last = 2;
        int now = 3;
        int ans = 0;
        for (int i = 4; i < n + 1; ++i)
        {
            ans = last + now;
            last = now;
            now = ans;
            //dp_table[i] = dp_table[i - 1] + dp_table[i - 2];
        }
        return ans;
    }
};
// @lc code=end
