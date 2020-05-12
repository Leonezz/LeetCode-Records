/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int right = 0;
        int sum = nums[0];
        int tempSum = 0;
        while (right < nums.size())
        {
            tempSum += nums[right];
            if (sum < 0)
            {
                if (tempSum > sum)
                    sum = tempSum;
                tempSum = tempSum < 0 ? 0 : tempSum;
            }
            else
            {
                if (tempSum > sum)
                    sum = tempSum;
                else if (tempSum < 0)
                    tempSum = 0;
            }
            right++;
        }
        return sum;
    }
};
// @lc code=end
