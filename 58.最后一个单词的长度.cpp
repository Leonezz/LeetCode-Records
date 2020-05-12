/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                cnt++;
            else if (i < s.size() - 1)
                cnt = 0;
            ans = cnt == 0 ? ans : cnt;
        }
        return ans;
    }
};
// @lc code=end
