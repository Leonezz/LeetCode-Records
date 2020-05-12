/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string &longer = a.size() > b.size() ? a : b;
        string &shorter = a.size() > b.size() ? b : a;
        int idx = longer.size() - 1;
        char adition = '0';
        while (idx >= 0)
        {
            char &chl = longer[idx];
            int sIdx = idx - longer.size() + shorter.size();

            char chs = sIdx < 0 ? '0' : shorter[sIdx];
            adition = plus(chl, chs, adition);
            //cout << sIdx;
            idx--;
        }
        if (adition == '1')
            longer.insert(0, 1, adition);
        return longer;
    }
    char plus(char &bit, char add, char adition = '0')
    {
        if (add == '0' && adition == '0')
            return '0';
        if (add == '0')
            return plus(bit, adition);
        if (bit == '0')
        {
            bit = adition == '0' ? '1' : '0';
            return adition;
        }
        else
        {
            bit = adition;
            return '1';
        }
    }
};
// @lc code=end
