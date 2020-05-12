/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

/*
 * 看了别人的思路
 * 用f(i)表示以i为根节点的二叉搜索树个数
 * 则numTrees(n) = f(1)+f(2)+...+f(n)
 * i为根节点时，其左子树有1~i-1 i-1个节点组成，因此左子树个数是numTrees(i-1)
 * 其右子树由n-i个节点组成,因此右子树个数是numTrees(n-i)
 * 所以i为根节点的情况下总的二叉搜索树个数是numTrees(i-1)*numTrees(n-i)
 * 所以n个节点组成的二叉搜索树个数numTrees(n)为：
 * numTrees(n) = numTrees(0) * numTrees(n-1) + numTrees(1) * numTrees(n-2) +...
 *              + numTrees(n-1) * numTrees(0)
 * numTrees(0) = 1
 * 向下递推几项帮助理解：
 * numTrees(1) = numTrees(0)*numTrees(0) = 1
 * numTrees(2) = numTrees(0)*numTrees(1)+numTrees(0)*numTrees(1) = 2
 * numTrees(3) = numTrees(0)*numTrees(2)+numTrees(1)*numTrees(1)
 *               +numTrees(2)*numTrees(0) = 5
 * 可以看到计算numTrees(i)时，需要知道从0到i-1的numTrees值
 * 若使用递归的算法则会发生严重的重复计算
 * 使用动态规划算法，建立dp table储存前面计算得的值，避免重复计算
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        int *dp = new int[n + 1](); //后面的()执行int类型的默认初始化，没有会出错
        dp[0] = 1;
        dp[1] = 1;
        for (size_t i = 2; i < n + 1; ++i)
        {
            for (size_t j = 0; j < i; ++j)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        int result = dp[n];
        delete[] dp;
        return result;
    }
};
// @lc code=end
int main()
{
    std::cout << Solution().numTrees(3);
}