/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        if(x==1.0)return 1;
        if(x==0.0)return 0;
        if(n==INT_MIN&&x!=-1)return 0;
        else if(n==INT_MIN&&x==-1)return 1;
        bool nag = n < 0 ? true : false;
        n = nag?(-n):n;
        double ans = 1.0;
        while (n != 0)
        {
            if (n & 1)
                ans *= x;

            x *= x;
            n >>= 1;
        }
        return nag ? (1 / ans) : ans;
    }
};
// @lc code=end
