/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 * Author:zhuwenq
 * Date:2 20 2020
 * 
 * string记录子串，遇同裁剪
 * 
 */

// @lc code=start
//#define HEADER
///#ifdef HEADER
//#include <string>
//#include <set>
//using namespace std;
//#endif

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string list;
        int max_length = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            const char &ch = s[i];
            if (list.find(ch) != list.npos)
            {
                if (list.size() > max_length)
                {
                    max_length = list.size();
                }
                list = list.substr(list.find(ch) + 1);
            }
            list += ch;
        }
        if (list.size() > max_length)
        {
            max_length = list.size();
        }
        return max_length;
    }
};
// @lc code=end
//int main(int argc,char* argv[])
//{
//    Solution so;
//    so.lengthOfLongestSubstring("abcabcbb");
//    return 0;
//}