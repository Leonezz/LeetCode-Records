/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return string();
        if (strs.size() < 2)
            return strs[0];
        string ans;
        char ch = strs[0][0];
        while (ans.size() <= strs[0].size())
        {
            for (int i = 0; i < strs.size(); ++i)
            {
                if (ans.size() == strs[i].size() || ch !=strs[i][ans.size()])
                    return ans;
                if (i == strs.size() - 1)
                {
                    ans += ch;
                    ch = strs[i][ans.size()];
                }
            }
        }
        return ans;
    }
};
// @lc code=end
