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
        char table[128] = {0};
        int left = 0;
        int right = 0;
        int maxLength = 0;
        while (right < s.size())
        {
            char &ch = s[right];
            table[ch]++;

            while (table[ch] > 1)
            {
                table[s[left]]--;
                left++; 
            }
            maxLength = maxLength > right - left + 1 ? maxLength : right - left + 1;
            right++;
        }
        return maxLength;
    }
};
// @lc code=end
//int main(int argc,char* argv[])
//{
//    Solution so;
//    so.lengthOfLongestSubstring("abcabcbb");
//    return 0;
//}