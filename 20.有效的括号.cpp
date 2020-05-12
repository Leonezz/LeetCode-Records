/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        char table[256] = {0};
        table[')'] = '(';
        table[']'] = '[';
        table['}'] = '{';
        int idx = 0;
        while (idx < s.size())
        {
            char &ch = s[idx];
            idx++;
            if (ch == '(' || ch == '[' || ch == '{')
                stack.push(ch);
            else
            {
                if (stack.empty()||stack.top() != table[ch])
                    return false;
                else
                    stack.pop();
            }
        }
        return stack.empty();
    }
};
// @lc code=end
