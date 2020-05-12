/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
#include <iostream>
// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;
        long ans = x;
        while (ans > x / ans)
        {
            ans = (ans + x / ans) / 2;
        }

        return ans;
    }
};
// @lc code=end
int main()
{
    std::cout << Solution().mySqrt(36);
}