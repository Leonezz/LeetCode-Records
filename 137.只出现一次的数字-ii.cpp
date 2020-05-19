/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int l = 0;
        int h = 0;
        for(auto& num:nums){
            l = (l^num)&(~h);
            h = (h^num)&(~l);
        }
        return l;
    }
};
// @lc code=end

