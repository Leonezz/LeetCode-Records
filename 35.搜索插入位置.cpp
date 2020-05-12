/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target <= nums[0])
            return 0;
        if (target > nums[nums.size() - 1])
            return nums.size();
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (target <= nums[left])
                return left;
            if (target > nums[right])
                return right + 1;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left == 0 ? 1 : left;
    }
};
// @lc code=end
