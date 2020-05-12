/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> un;
        for (int i = 0; i < edges.size() + 1; ++i)
            un.push_back(i);
        for (vector<vector<int>>::iterator it = edges.begin();
             it != edges.end(); ++it)
        {
            int first = it->at(0);
            int second = it->at(1);
            if (find(first, un) != find(second, un))    //如果不是同一个根节点
                un[find(first, un)] = find(second, un); //把first的根节点连接到second的根节点上
            else
                return *it;
        }
        return vector<int>();
    }
    int find(int x, vector<int> &u)
    {
        if (u[x] != x)
            u[x] = find(u[x], u); //路径压缩，把x和x到根节点之间的点都连接到根节点上
        return u[x];
    }
};
// @lc code=end
