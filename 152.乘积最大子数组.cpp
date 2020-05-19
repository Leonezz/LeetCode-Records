/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int mx = 1;
        int mn = 1;
        int ans = INT_MIN;
        for (int &num:nums)
        {
            int mxx = mx*num;
            int mnn = mn*num;
            mx = max(num,max(mxx,mnn));
            mn = min(num,min(mxx,mnn));
            ans = max(ans,mx);
        }
        return ans;
    }
};
// @lc code=end
