/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 * copied from @Wait想念
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        const int numsLength1 = nums1.size();
        const int numsLength2 = nums2.size();
        //const int totalLengthHalf = (numsLength1 + numsLength2) / 2;
        const int left = (numsLength1 + numsLength2 + 1) / 2;
        const int right = (numsLength1 + numsLength2 + 2) / 2;
        return (findKthNumFromTwoLists(nums1, 0, nums2, 0, left) + findKthNumFromTwoLists(nums1, 0, nums2, 0, right)) / 2.0;
    }

private:
    double findKthNumFromTwoLists(const vector<int> &nums1, int s1,
                                  const vector<int> &nums2, int s2, int K)
    {
        if (s1 >= nums1.size())
        {
            return nums2[s2 + K - 1];
        }
        if (s2 >= nums2.size())
        {
            return nums1[s1 + K - 1];
        }
        if (K == 1)
        {
            return nums1[s1] > nums2[s2] ? nums2[s2] : nums1[s1];
        }
        const int val1 = (s1 + K / 2 - 1 < nums1.size()) ? nums1[s1 + K / 2 - 1] : INTMAX_MAX;
        const int val2 = (s2 + K / 2 - 1 < nums2.size()) ? nums2[s2 + K / 2 - 1] : INTMAX_MAX;
        if (val1 < val2)
        {
            return findKthNumFromTwoLists(nums1, s1 + K / 2, nums2, s2, K - K / 2);
        }
        else
        {
            return findKthNumFromTwoLists(nums1, s1, nums2, s2 + K / 2, K - K / 2);
        }
    }
};

// @lc code=end
