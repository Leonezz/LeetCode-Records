/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        vector<vector<int>> mat(N + 1, vector<int>(N + 1, INT_MAX));
        for (vector<int> &time : times)
            mat[time[0]][time[1]] = time[2];
        for (int i = 1; i < N + 1; ++i)
            mat[i][i] = 0;
        auto cmp = [](pair<int, int> &l, pair<int, int> &r) {
            return l.second > r.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            queue(cmp);
        for (int j = 1; j < N + 1; ++j)
        {
            if (j == K || mat[K][j] == INT_MAX)
                continue;
            queue.push({j, mat[K][j]});
        }
        while (!queue.empty())
        {
            pair<int, int> p = queue.top();
            queue.pop();
            for (int i = 1; i < N + 1; ++i)
            {
                if ((i == K) || (mat[p.first][i] == INT_MAX))
                    continue;
                if (mat[p.first][i] + p.second < mat[K][i])
                {
                    mat[K][i] = mat[p.first][i] + p.second;
                    queue.push({i, mat[K][i]});
                }
            }
        }
        int result = INT_MIN;
        for (int i = 1; i < N + 1; ++i)
        {
            if (mat[K][i] > result)
                result = mat[K][i];
        }
        return result == INT_MAX ? -1 : result;
    }
};
// @lc code=end
