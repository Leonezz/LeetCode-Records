/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * [1]????
 * Author:zhuwenq
 * Date:2 20 2020
 * 
 * ??Map????????????+??=target?????????????
 * ?????????=??????
 * ????map??????value????????????????
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i)
        {
            const int complement = target - nums.at(i);
            if (hashMap.find(complement) != hashMap.end())
            {
                return vector<int>{hashMap[complement], i};
            }
            else
            {
                hashMap.insert({nums[i], i});
            }
        }
        return vector<int>();
    }
};
// @lc code=end
int main(int argc, char *argv[])
{
    Solution sol;

    vector<int> vec = sol.twoSum(vector<int>{2, 7, 11, 15}, 9);
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout<<vec[i];
    }
}