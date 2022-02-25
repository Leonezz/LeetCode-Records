/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 */
#include<string>
using namespace std; 
// @lc code=start
class Solution {
public:
    bool queryString(string s, int n) {
        bool ans = true;
        for(int i = 1; i < n + 1; ++i){
            ans &= (s.find(getBinary(i)) != -1);
        }
        return ans;
    }
    string getBinary(int n){
        string res;
        for(int i = 0;i < 31; ++i){
            res += (n & 0x01) ? '1' : '0';
            n >>= 1;
        }
        reverse(res.begin(), res.end());
        int i = 0;
        for(; i < res.size(); ++i){
            if(res[i] == '1')break;
        }
        res.erase(0, i);
        return res;
    }
};
// @lc code=end
int main(){
    Solution so;
    so.queryString("0110", 4);
}