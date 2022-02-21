/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int lastStep = 0;
        int lastMove = 0;
        for (int i = 0; i < dominoes.size(); ++i)
        {
            if (dominoes[i] == 'L')
            {
                if (lastMove == 0)
                    helper(lastStep, i + 1, 'L', dominoes);
                else
                {
                    helper(lastStep, (lastStep + i + 1) / 2, 'R', dominoes);
                    helper((lastStep + i) / 2 + 1, i + 1, 'L', dominoes);
                }
                lastStep = i + 1;
                lastMove = 0;
            }
            else if (dominoes[i] == 'R')
            {
                if (lastMove == 1)
                    helper(lastStep, i, 'R', dominoes);
                lastMove = 1;
                lastStep = i;
            }
        }
        if (lastMove == 1)
            helper(lastStep, dominoes.size() + 1, 'R', dominoes);
        return dominoes;
    }
    void helper(int left, int right, char c, string &dominoes)
    {
        for (; left < right; ++left)
            dominoes[left] = c;
    }
};
// @lc code=end
int main()
{
    string d = ".L.R...LR..L..";
    Solution so;
    so.pushDominoes(d);
}