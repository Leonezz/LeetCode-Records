/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ans;
        string str;
        for(auto&& ch : path)
        {
            switch (ch)
            {
            case '/':
                if(str == "..")
                {
                    ans.pop_back();
                    str.clear();
                    break;
                }
                if(str == ".")
                {
                    str.clear();
                    break;
                }
                if(str.empty())
                {
                    break;
                }
                ans.push_back(str);
                break;
            default:
                str+=ch;
                break;
            }
        }
        str.clear();
        for(auto&& s : ans)
            str+=("/"+s);
        return str;
    }
};
// @lc code=end

