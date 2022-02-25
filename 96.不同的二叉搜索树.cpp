/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4; i < n + 1; ++i){
            for(int j = 1; j < i + 1; ++j){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

// @lc code=end
int main(){
    Solution so;
    so.numTrees(5);
}