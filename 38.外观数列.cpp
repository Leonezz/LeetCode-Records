/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        string last = "1";
        for (int i = 1; i < n; ++i)
            last = deslove(last);
        return last;
    }
    string deslove(const string &str)
    {
        if (str.size() == 0)
            return string();
        string res;
        char ch = str[0];
        int cnt = 1;
        for (int i = 1; i < str.size(); ++i)
        {
            if (ch == str[i])
                cnt++;
            else
            {
                res += to_string(cnt) + ch;
                ch = str[i];
                cnt = 1;
            }
        }
        if (cnt != 0)
        {
            res += to_string(cnt) + ch;
        }
        //cout << res;
        return res;
    }
};
// @lc code=end
int main()
{
    cout << Solution().deslove("31131211131221");
}