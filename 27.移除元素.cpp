/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        for (vector<int>::iterator it = nums.begin(); it != nums.end();)
        {
            if (*it == val)
            {
                it = nums.erase(it);
                continue;
            }
            ++it;
        }
        return nums.size();
    }
};
// @lc code=end
