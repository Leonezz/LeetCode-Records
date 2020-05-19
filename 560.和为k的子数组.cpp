/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for (auto &num : nums)
        {
            sum += num;
            ans += map[sum - k];
            map[sum]++;
        }
        return ans;
    }
};
// @lc code=end
