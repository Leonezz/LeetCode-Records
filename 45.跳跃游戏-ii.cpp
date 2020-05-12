/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 0 || nums[0] == 0 || nums.size() == 1)
            return 0;
        if (nums[0] >= nums.size() - 1)
            return 1;
        int times = 0;
        for (int i = 0; i < nums.size() - 1;)
        {
            int step = nums[i];
            int choice = step;
            int tar = step;
            if (i + step < nums.size())
                choice += nums[i + step];
            for (int j = 1; j < step; ++j)
            {
                if (i + step >= nums.size() - 1)
                    return times + 1;
                if (j + nums[i + j] > choice)
                {
                    choice = j + nums[i + j];
                    tar = j;
                }
            }
            i += tar;
            times++;
        }
        return times;
    }
};
// @lc code=end
