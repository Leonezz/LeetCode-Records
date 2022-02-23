/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <queue>
using namespace std;
// @lc code=start
class MyStack
{
protected:
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        while (q.size() > 1)
        {
            q.push(q.front());
            q.pop();
        }
        int tmp = q.front();
        q.pop();
        return tmp;
    }

    int top()
    {
        int tmp = pop();
        q.push(tmp);
        return tmp;
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
