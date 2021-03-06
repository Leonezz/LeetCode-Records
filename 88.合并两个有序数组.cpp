/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int right = m + n - 1;
        while (n)
        {
            if (m == 0 || nums1[m - 1] < nums2[n - 1])
                nums1[right--] = nums2[--n];
            else
                nums1[right--] = nums1[--m];
        }
    }
};
// @lc code=end
