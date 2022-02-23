/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        string::iterator begin = s.begin();
        string::iterator end = s.end() - 1;
        while(begin < end){
            while(!isEngCh(*begin) && (begin < end))
                ++begin;
            while(!isEngCh(*end) && (begin < end))
                --end;
            if(begin < end)swap(*begin++, *end--);
        }
        return s;
    }
    bool isEngCh(const int c)
    {
        static constexpr int a = 'a' - 1;
        static constexpr int z = 'z' + 1;
        static constexpr int A = 'A' - 1;
        static constexpr int Z = 'Z' + 1;
        return ((c > a) && (c < z)) || ((c > A) && (c < Z));
    }
};
// @lc code=end

int main(){
    Solution so;
    string s = "ab-cd";
    so.reverseOnlyLetters(s);
}