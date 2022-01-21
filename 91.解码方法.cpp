/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        if(s.empty())
            return 0;
        if(s[0] == '0')
            return 0;
        if(s.size() == 1)
            return 1;
        int* dp = new int[s.size() + 1];
        dp[0] = 1;
        for(int i = 0; i < s.size(); ++i)
        {
            dp[i + 1] = s[i] == '0' ? 0 : dp[i];
            if((i > 0) && ((s[i - 1] == '1')||((s[i - 1] == '2') && (s[i] < '7'))))
            {
                dp[i + 1] += dp[i - 1];
            }
        }
        int ans = dp[s.size()];
        delete[] dp;
        return ans;
    }
};
// @lc code=end
