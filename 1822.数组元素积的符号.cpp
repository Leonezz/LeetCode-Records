/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        bool ans = true;
        for (auto &&num : nums)
        {
            if (num == 0)
                return 0;
            if (num < 0)
                ans = !ans;
        }
        return ans ? 1 : -1;
    }
};
// @lc code=end
