/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        else if (x < 10)
            return true;
        else
        {
            long bitCnt = 10;
            while (x / bitCnt > 0)
            {
                bitCnt *= 10;
            }
            bitCnt/=10;
            //cout<<bitCnt<<endl;
            for (int i = bitCnt; i > 1; i /= 10)
            {
                int first = (x / i) % 10;
                int second = x % (bitCnt * 10 / i) / (bitCnt / i);
                //cout<<first<<" "<<second<<endl;
                if (first != second)
                    return false;
            }
            return true;
        }
    }
};
// @lc code=end
