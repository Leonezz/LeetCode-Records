/*
 * @lc app=leetcode.cn id=1095 lang=cpp
 *
 * 一个不错的题解
 * 思路很简单，先找到峰值位置，然后把山峰数组分为两部分分别二分查找
 * 一开始想着找到左边的有序序列二分查找，右边无序的部分递归实现
 * 不是错误就是超时就是调用get超过一百次
 * 整整卡了两小时
 * 
 * [1095] 山脉数组中查找目标值
 */
using namespace std;
class MountainArray
{
public:
    int get(int index);
    int length();
};
// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
private:
    std::vector<int> buf;

public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        buf = vector<int>(mountainArr.length(), -1);
        int left = 0;
        int right = mountainArr.length() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            int midVal = this->get(mid, mountainArr);
            int midLeft = this->get(mid - 1, mountainArr);
            int midRight = this->get(mid + 1, mountainArr);
            if (midVal > midLeft && midVal > midRight)
            {
                break;
            }
            else if (midVal > midRight)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        const int peek = (left + right) / 2;
        int ty = binarySearch(target, mountainArr, 0, peek, true);
        if (ty == -1)
        {
            ty = binarySearch(target, mountainArr, peek + 1, mountainArr.length() - 1, false);
        }
        return ty;
    }
    int get(const int index, MountainArray &m)
    {
        if (index < 0 || index > buf.size())
            return INT_MIN;
        else if (buf.at(index) != -1)
            return buf.at(index);
        else
        {
            const int g = m.get(index);
            buf[index] = g;
            return g;
        }
    }
    int binarySearch(int target, MountainArray &m, const int left, const int right, bool up)
    {
        while (left <= right)
        {
            const int mid = (left + right) / 2;
            const int midVal = this->get(mid, m);
            if (target == midVal)
                return mid;
            else if (target > midVal)
            {
                const int l = up ? mid + 1 : left;
                const int r = up ? right : mid - 1;
                return binarySearch(target, m, move(l), move(r), up);
            }
            else
            {
                const int l = up ? left : mid + 1;
                const int r = up ? mid - 1 : right;
                return binarySearch(target, m, move(l), move(r), up);
            }
        }
        return -1;
    }
};
// @lc code=end
