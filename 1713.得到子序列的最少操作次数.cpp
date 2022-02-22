/*
 * @lc app=leetcode.cn id=1713 lang=cpp
 *
 * [1713] 得到子序列的最少操作次数
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> map;
        for(int i = 0; i < target.size(); ++i){
            map[target[i]] = i;
        }
        vector<int> indexs;
        for(int i = 0; i < arr.size(); ++i){
            if(map.count(arr[i])){
                indexs.push_back(map[arr[i]]);
            }
        }
        if(indexs.empty()) return target.size();
        vector<int> ans{indexs[0]};
        for(int i = 1; i < indexs.size(); ++i){
            if(indexs[i] > ans.back()) ans.push_back(indexs[i]);
            else {
                int inset = find(ans, indexs[i]);
                ans[inset] = indexs[i];
            }
        }
        return target.size() - ans.size();
    }
    int find(const vector<int>& indexs, int value){
        int left = 0;
        int right = indexs.size();

        while(left < right){
            int mid = left + (right - left) / 2;
            if(indexs[mid] >= value)
                right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
// @lc code=end

int main()
{
    Solution so;
    vector<int> target = {16, 7, 20, 11, 15, 13, 10, 14, 6, 8};
    vector<int> arr = {11, 14, 15, 7, 5, 5, 6, 10, 11, 6};
    so.minOperations(target, arr);
}