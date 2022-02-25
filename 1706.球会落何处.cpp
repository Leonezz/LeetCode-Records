/*
 * @lc app=leetcode.cn id=1706 lang=cpp
 *
 * [1706] 球会落何处
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(), 0);
        for(int i = 0; i < ans.size(); ++i)
            ans[i] = i;
        for(int i = 0; i < ans.size(); ++i){
            for(auto&& row : grid){
                int ball = ans[i];
                if(ball == -1)continue;
                if(ball == 0 && row[ball] == -1)ans[i] = -1;
                else if(ball == row.size() - 1 && row[ball] == 1)ans[i] = -1;
                else {
                    if (row[ball] == 1 && row[ball + 1] == 1)ans[i]++;
                    else if(row[ball] == -1 && row[ball - 1] == -1)ans[i]--;
                    else ans[i] = -1;
                }
             }
        }
        return ans;
    }
};
// @lc code=end
int main(){
    Solution so;
    vector<vector<int>> g = {
        {1,1,1,-1,-1},
        {1,1,1,-1,-1},
        {-1,-1,-1,1,1},
        {1,1,1,1,-1},
        {-1,-1,-1,-1,-1}
    };
    so.findBall(g);
}
