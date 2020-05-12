/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        if (digits.size() == 0)
            return vector<int>();
        int plusBit = digits.size() - 1;
        while (plusBit >= 0 && plusOne(digits[plusBit]) == 1)
        {
            if (plusBit == 0)
            {
                digits[plusBit] = 1;
                digits.push_back(0);
            }
            else
                digits[plusBit] = 0;
            plusBit--;
        }

        return digits;
    }
    int plusOne(int &num)
    {
        if (num == 9)
        {
            num = 0;
            return 1;
        }
        num++;
        return 0;
    }
};
// @lc code=end
