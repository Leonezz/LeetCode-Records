/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;                //0
        int right = nums.size() - 1; //1
        while (left <= right)
        {
            int mid = (left + right) / 2; //0
            //左有序，必定是升序
            if (nums[mid] == target)
                return mid;
            if (nums[left] < nums[mid])
            {
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            //右有序,必定是升序
            else if (nums[left] > nums[mid])
            {
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else //数组无相等元素，相等意味着left==mid
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end


//这道题要求复杂度O(log n)，似乎是在提示使用二分查找法
//但我是个傻篮子，一开写就是递归，提交了十几次才通过
int main()
{
    vector<int> v{4, 5, 6, -1, 0, 1, 2};
    Solution so;
    cout << so.search(v, 0);
}
