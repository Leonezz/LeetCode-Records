/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        vector<int> u;
        vector<int> ans;
        vector<int> indegree(edges.size() + 1, 0);
        int target = 0;
        for (int i = 0; i < edges.size() + 1; ++i)
            u.push_back(i);
        for (vector<vector<int>>::iterator it = edges.begin(); it != edges.end(); ++it)
        {
            int from = it->at(0);
            int to = it->at(1);
            if (++indegree[to] > 1)
            {
                target = to;
                break;
            }
            if (find(from, u) != find(to, u))
                u[to] = find(from, u);
            else
                ans = *it;
        }
        if (target == 0)
            return ans;
        else
        {
            vector<vector<int>> exs;
            for (int i = 0; i < edges.size(); ++i)
            {
                if (edges[i][1] == target)
                    exs.push_back(edges[i]);
            }
            for (int i = exs.size() - 1; i > -1; --i)
            {
                if (!circle(edges, exs[i]))
                    return exs[i];
            }
        }
        return vector<int>();
    }
    int find(int x, vector<int> &vec)
    {
        if (vec[x] != x)
            vec[x] = find(vec[x], vec);
        return vec[x];
    }
    bool circle(vector<vector<int>> &edges, vector<int> &except)
    {
        vector<int> u;
        for (int i = 0; i < edges.size() + 1; ++i)
            u.push_back(i);
        for (vector<vector<int>>::iterator it = edges.begin(); it != edges.end(); ++it)
        {
            if (it->at(0) == except[0] && it->at(1) == except[1])
                continue;
            int from = it->at(0);
            int to = it->at(1);
            if (find(from, u) != find(to, u))
                u[to] = find(from, u);
            else
                return true;
        }
        return false;
    }
};
// @lc code=end
