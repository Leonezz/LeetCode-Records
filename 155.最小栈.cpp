/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack
{
private:
    vector<int> vec;
    int _min;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        vec = vector<int>();
        _min = 0;
    }

    void push(int x)
    {
        vec.push_back(x);
        if (vec[_min] > x)
            _min = vec.size() - 1;
    }

    void pop()
    {
        vec.pop_back();
        if (_min == vec.size())
        {
            int minVal = INT_MAX;
            for(int i = 0;i<vec.size();++i){
                if(vec[i]<=minVal){
                    minVal = vec[i];
                    _min = i;
                }
            }
        }
    }

    int top()
    {
        return vec.back();
    }

    int getMin()
    {
        return vec[_min];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
