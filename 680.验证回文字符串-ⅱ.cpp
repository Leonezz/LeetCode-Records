/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int length = s.size();
        if (length < 3)
            return true;
        return validPalindrome(s, 0, length - 1);
    }
    bool validPalindrome(string &s, int left, int right, int change = 1)
    {
        if (left >= right)
            return change > -1;
        if (s[left] == s[right])
            return validPalindrome(s, left + 1, right - 1, change);
        if (s[left + 1] == s[right] || s[right - 1] == s[left])
            return validPalindrome(s, left + 2, right - 1, change - 1) ||
                   validPalindrome(s, left + 1, right - 2, change - 1);
        else
            return false;
    }
};
// @lc code=end
