/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

// @lc code=start
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int costOfYear[366] = {0};
        int dayIdx = 0;
        for (int i = 1; i < 366; ++i)
        {
            if (dayIdx == days.size())
                break;
            int day = days[dayIdx];
            if (day != i)
                costOfYear[i] = costOfYear[i - 1];
            else
            {
                costOfYear[i] = min({costOfYear[i - 1] + costs[0],
                                     costOfYear[max({0, i - 7})] + costs[1],
                                     costOfYear[max({0, i - 30})] + costs[2]});
                dayIdx++;
            }
        }
        return costOfYear[days[days.size() - 1]];
    }
    int &&min(initializer_list<int> list)
    {
        int min = INT_MAX;
        initializer_list<int>::iterator it = list.begin();
        for (; it != list.end(); ++it)
        {
            if (*it < min)
                min = *it;
        }
        return move(min);
    }
    int &&max(initializer_list<int> list)
    {
        int max = INT_MIN;
        initializer_list<int>::iterator it = list.begin();
        for (; it != list.end(); ++it)
        {
            if (*it > max)
                max = *it;
        }
        return move(max);
    }
};
// @lc code=end
