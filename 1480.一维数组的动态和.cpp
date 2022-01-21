/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans{nums[0]};
        for(int i = 1;i<nums.size();++i)
        {
            ans.push_back(ans[i-1]+nums[i]);
        }
        return ans;
    }
};
// @lc code=end

