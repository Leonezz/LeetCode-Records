/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution
{
public:
    int fib(int N)
    {
        if (N == 0)
            return 0;
        if (N < 3)
            return 1;
        int *dp_table = new int[N + 1]();
        dp_table[1] = 1;
        dp_table[2] = 1;
        for (int i = 3; i < N + 1; ++i)
            dp_table[i] = dp_table[i - 1] + dp_table[i - 2];
        return dp_table[N];
    }
};
// @lc code=end
