/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution
{
public:
    bool check(const string& haystack, const string& needle, int pos)
    {
        if(haystack.size() < pos + needle.size())
            return false;
        int i = 0;
        for(; i < needle.size(); ++pos)
        {
            if(needle[i++] != haystack[pos])
                return false;
        }
        return true;
    }
    int strStr(string haystack, string needle)
    {
        if (needle == "")
            return 0;
        for (int i = 0; i < haystack.size(); ++i)
        {
            if (haystack[i] == needle[0] && check(haystack, needle, i))
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
