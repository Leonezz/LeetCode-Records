/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int left = 0;
        while (left + 1 < nums.size())
        {
            if (left + 1 < nums.size() && nums[left] == nums[left + 1])
            {
                nums.erase(nums.begin() + left);
                continue;
            }
            left++;
        }
        return nums.size();
    }
};
// @lc code=end
