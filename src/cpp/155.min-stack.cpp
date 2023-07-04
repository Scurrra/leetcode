#include <vector>

/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack
{
private:
    std::vector<std::pair<int, int>> stack;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        int minimum = this->stack.empty() ? val : std::min(val, this->stack.back().second);
        stack.emplace_back(std::make_pair(val, minimum));
    }

    void pop()
    {
        this->stack.pop_back();
    }

    int top()
    {
        return this->stack.back().first;
    }

    int getMin()
    {
        return this->stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
