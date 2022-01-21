/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int size = nums.size();
        if(size == 1)
            return {nums[0]};
        vector<int> dp(size, 1);
        sort(nums.begin(), nums.end());
        int maxSize = 1;
        int maxVal = nums[0];
        for (int i = 1; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j])
                    continue;
                dp[i] = dp[i] > (dp[j] + 1) ? dp[i] : (dp[j] + 1);
            }
            if (dp[i] > maxSize)
            {
                maxSize = dp[i];
                maxVal = nums[i];
            }
        }
        vector<int> ans;
        for (int i = size - 1; i >= 0 && maxSize >= 0; --i)
        {
            if (maxVal % nums[i])
                continue;
            if(dp[i] != maxSize)
                continue;
            ans.push_back(nums[i]);
            maxVal = nums[i];
            maxSize--;
        }
        return ans;
    }
};
// @lc code=end
