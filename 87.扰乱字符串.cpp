/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int str_length = s1.length();
        int dp[30][30][31] = {0};
        for(size_t i = 0; i < str_length; ++i)
        {
            for(size_t j = 0; j<str_length; ++j)
            {
                dp[i][j][1] = (s1[i] == s2[j]); 
            }
        }

        for(int len = 2; len <= str_length; ++len)
        {
            for(int i = 0; i <= str_length - len; ++i)
            {
                for(int j = 0; j <= str_length - len; ++j)
                {
                    for(int k = 1; k < len; ++k)
                    {
                        if(dp[i][j][k] && dp[i + k][j + k][len - k])
                        {
                            dp[i][j][len] = 1;
                            break;
                        }
                        if(dp[i][j + len - k][k] && dp[i + k][j][len - k])
                        {
                            dp[i][j][len] = 1;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][str_length];
    }
};
// @lc code=end

