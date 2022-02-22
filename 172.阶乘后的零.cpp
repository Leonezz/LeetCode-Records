/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n > 4)
        {
            n /= 5;
            res += n;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution so;
    so.trailingZeroes(5);
}