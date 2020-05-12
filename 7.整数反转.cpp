/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        long ans = 0;
        while (x != 0)
        {
            ans = ans * 10 + x % 10;
            if (ans < INT_MIN || ans > INT_MAX)
                return 0;
            x /= 10;
        }
        return ans;
    }
};
// @lc code=end
