/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        int table[128] = {0};
        table[0] = 0;
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
        int ans = 0;
        int idx = 0;
        char last = 0;
        while (idx < s.size())
        {
            char &ch = s[idx];
            idx++;
            if ((last == 'I' && (ch == 'V' || ch == 'X')) ||
                (last == 'X' && (ch == 'L' || ch == 'C')) ||
                (last == 'C') && (ch == 'D' || ch == 'M'))
            {
                ans += table[ch] - table[last] - table[last];
                last = 0;
            }
            else
            {
                ans += table[ch];
                last = ch;
            }
        }
        return ans;
    }
};
// @lc code=end
